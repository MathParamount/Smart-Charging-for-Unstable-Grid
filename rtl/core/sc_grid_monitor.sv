// sc_safety_monitor.sv
module sc_grid_monitor
(
  input logic clk,
  input logic reset_n,
  sc_interface_if.grid_monitor grid_bus,
  sc_interface_if.fsm_connect fsm_bus
);

import sc_types_pkg::*;
import sc_include_pkg::*;	//adc_constants

 logic [31:0] voltage_history [0:3];

/* verilator lint_off UNUSEDSIGNAL */
 logic [31:0] sum_voltage;		//18 bits to avoid overflow
/* verilator lint_on UNUSEDSIGNAL */


logic [31:0] filter_volt;

grid_state_t grid_state_enum;

logic [2:0] sample_count;

logic data_valid;

logic battery_connected_q;

assign grid_bus.data_valid = data_valid;
//assign fsm_bus.grid_state = (sample_count == 3) ? grid_state_stable : grid_state_enum;

//stabilization data syste
always_ff @(posedge clk or negedge reset_n) begin
    if(!reset_n) begin
        sample_count <= 0;
        data_valid <= 0;
    end else begin
      if(battery_connected_q) begin
        if(sample_count < 4) begin		//wait 4 cycle to data_valid
            sample_count <= sample_count + 1;
            data_valid <= (sample_count == 3);		//active 3 cycle
        end
        else begin
            data_valid <= 1;	// active in stabilization cycle
    	end
    end
    else begin
    	sample_count <= 0;
    	data_valid <= 0;
    end
  end
end

//sincronization
always_ff @(posedge clk or negedge reset_n) begin
    if(!reset_n)
        battery_connected_q <= 0;
    else
        battery_connected_q <= grid_bus.battery_connected;
end

//debug
always_ff @(posedge clk) begin
    if (battery_connected_q)
        $display("DEBUG: battery_connected_q = 1");
end


always_ff @(posedge clk or negedge reset_n) begin
    if(!reset_n) begin
        for(int i=0; i<4; i++) voltage_history[i] <= 0;
        
        filter_volt <= 0;
    end
    else if(battery_connected_q) begin
	
	// Shift register
        for(int i=3; i>0; i--) 
            voltage_history[i] <= voltage_history[i-1];
        voltage_history[0] <= {16'b0, grid_bus.grid_voltage_adc};	//16'b0 extend to 32 bits
        
        sum_voltage <= {16'b0, grid_bus.grid_voltage_adc} + 
                      voltage_history[0] + 
                      voltage_history[1] + 
                      voltage_history[2];
        
        filter_volt <= sum_voltage >> 2;
        
    end
end

always_comb begin
    if(!data_valid) begin
    	grid_state_enum = GRID_NORMAL;
    	
    end
    else if (filter_volt < V_CRIT_LOW_ADC || 
             filter_volt > V_CRIT_HIGH_ADC || 
             grid_bus.ml_predict_instability) begin
          grid_state_enum = GRID_CRITICAL;
          end
    else if (filter_volt < V_UNSTABLE_MIN_ADC || 
             filter_volt > V_UNSTABLE_MAX_ADC) begin
           grid_state_enum = GRID_UNSTABLE;
          end
    else begin
           grid_state_enum = GRID_NORMAL;
    	end
end

/*
always_ff @(posedge clk) begin
    if(data_valid) begin
        $display("GRID_MONITOR: filter_volt=%0d, grid_state=%s (%d), valid =%0d, battery_connected_q=%0d", 
                 filter_volt, grid_state_enum.name(), grid_state_enum,data_valid, battery_connected_q);
    end
end

*/

always_ff @(posedge clk or negedge reset_n) begin
    if(!reset_n)  begin
        grid_bus.grid_state <= GRID_NORMAL;
    end
    else begin
        grid_bus.grid_state <= grid_state_enum;
    end
end

// No grid_monitor, adicione sinais de debug
logic [31:0] debug_sum;
logic [31:0] debug_adc;
logic [31:0] debug_h0, debug_h1, debug_h2, debug_h3;

//debug
always_ff @(posedge clk) begin
    if(battery_connected_q && (sample_count > 2)) begin
        debug_adc <= {16'b0, grid_bus.grid_voltage_adc};
        debug_h0 <= voltage_history[0];
        debug_h1 <= voltage_history[1];
        debug_h2 <= voltage_history[2];
        debug_h3 <= voltage_history[3];
        debug_sum <= {16'b0, grid_bus.grid_voltage_adc} + 
                    voltage_history[0] + 
                    voltage_history[1] + 
                    voltage_history[2];
        
        $display("=== FILTER DEBUG ===");
        $display("ADC_IN=%0d", debug_adc);
        $display("HIST[0]=%0d, HIST[1]=%0d, HIST[2]=%0d, HIST[3]=%0d", 
                 debug_h0, debug_h1, debug_h2, debug_h3);
        $display("SOMA (ADC+H0+H1+H2)=%0d", debug_sum);
        $display("FILTER (soma>>2)=%0d", debug_sum >> 2);
        $display("filter_volt atual=%0d", filter_volt);
        $display("data_valid=%0d, battery_connected_q=%0d", 
                 data_valid, battery_connected_q);
        $display("V_CRIT_LOW_ADC=%0d, V_UNSTABLE_MIN_ADC=%0d", 
                 V_CRIT_LOW_ADC, V_UNSTABLE_MIN_ADC);
        $display("==================");
    end
end

endmodule
