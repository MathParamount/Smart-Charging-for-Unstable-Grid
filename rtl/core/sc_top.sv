<<<<<<< HEAD
`timescale 1ns/1ps

=======
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
// sc_top.sv
module sc_top
(
input logic clk, 
input logic reset_n,
input logic battery_connected,
input logic battery_full,
input logic ml_predict_instability,
<<<<<<< HEAD
input logic [15:0] grid_voltage_adc,
//input logic [15:0] grid_current_sensor,

output logic charge_enable,
output logic fault_flag,
output [2:0] current_state,
output logic [1:0] fault_code,
output logic [1:0] grid_state
);
	sc_interface_if sc_interface_bus_t();
	//state_t current_state;
	
	//Connect top signals interface
    	
    	assign sc_interface_bus_t.battery_full = battery_full;

    	assign sc_interface_bus_t.grid_voltage_adc = grid_voltage_adc;
	//assign sc_interface_bus_t.grid_current_sensor = grid_current_sensor;
	assign sc_interface_bus_t.battery_connected = battery_connected;
	assign sc_interface_bus_t.ml_predict_instability = ml_predict_instability;
    	
    	//The output of the top come from interface
       	assign charge_enable = sc_interface_bus_t.charge_enable;
    	assign fault_flag = sc_interface_bus_t.fault_flag;
    	
    	assign fault_code = sc_interface_bus_t.fault_code;
    	
    	assign current_state = sc_interface_bus_t.current_state;
    	
    	assign grid_state = sc_interface_bus_t.grid_state;  // read from interface
	
	sc_grid_monitor u_grid (
        .clk(clk),
        .reset_n(reset_n),
        .grid_bus(sc_interface_bus_t.grid_monitor),
	.fsm_bus(sc_interface_bus_t.fsm_connect)
    	);
    
=======
input grid_state_t grid_state
);

	sc_interface_if sc_bus();
	state_t current_state;
	
	//assignments
	always_comb begin
  	    sc_bus.battery_connected = battery_connected;
	    sc_bus.battery_full = battery_full;
	end
	
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
	sc_fsm u_fsm
	(
	  .clk(clk),
	  .reset_n(reset_n),
<<<<<<< HEAD
	  .fsm_bus(sc_interface_bus_t.fsm_connect),
	  .grid_bus(sc_interface_bus_t.grid_monitor)
=======
	  .fsm_bus(sc_bus),
	  .current_state(current_state)
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
	);
	
	sc_safety_monitor u_safety
	(
	  .clk(clk),
	  .reset_n(reset_n),
<<<<<<< HEAD
	  .safety_bus(sc_interface_bus_t.safety),
	  .grid_bus(sc_interface_bus_t.grid_monitor)
	);
	
	//debug
	always_ff @(posedge clk) begin
        $display("TOP: fault_flag=%d, state=%s, charge=%d", 
                 sc_interface_bus_t.fault_flag,
                 sc_interface_bus_t.current_state.name(),
                 sc_interface_bus_t.charge_enable);
	
	$display("TOP: reset_n=1, batt_conn=%0d, data_valid=%0d", 
                 sc_interface_bus_t.battery_connected,
                 sc_interface_bus_t.data_valid);
    	end
    
=======
	  .ml_predict_instability(ml_predict_instability),
	  .safety_bus(safety_bus)
	);
	
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
endmodule
