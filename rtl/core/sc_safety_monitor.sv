//`timeunit 1ns/1ps;

module sc_safety_monitor
(
	input logic clk,
	input logic reset_n, 
	
	sc_interface_if.safety safety_bus,
	sc_interface_if.grid_monitor grid_bus
);
	import sc_types_pkg::*;
	
	grid_state_t grid_state_enum;
	
	logic fault_flag_comb;
	logic [1:0] fault_code_comb;
	
	always_ff @(posedge clk or negedge reset_n) begin
	    if(!reset_n) begin
	    	safety_bus.fault_flag <= 0;
        	safety_bus.fault_code <= 0;
	    end
	    else begin
	    	safety_bus.fault_flag <= fault_flag_comb;
        	safety_bus.fault_code <= fault_code_comb;
	    end
	end
	
	//combinational logic to state conditions
	always_comb begin
		//default
		fault_code_comb = 0;
		fault_code_comb = '0;
		
   		grid_state_enum = grid_bus.grid_state;
		
		if(reset_n && grid_bus.grid_voltage_adc != '0) begin
		    
		    unique case(safety_bus.current_state)
			
			IDLE: begin
			   fault_flag_comb = 0;
			   fault_code_comb = 2'b00;
			end
			
			CHECK_GRID: begin
			    case(grid_state_enum)
				GRID_CRITICAL: begin
				    fault_flag_comb = 1;
				    fault_code_comb = 2'b11;
				    $display("SAFETY: FAULT ativado! grid_state=%s", grid_bus.grid_state.name());
				end
				
				GRID_UNSTABLE: begin
				    fault_flag_comb = 0;
				    fault_code_comb = 2'b10;
				end
				
				GRID_NORMAL: begin 
				    fault_flag_comb = 0;
				    fault_code_comb = 2'b01;			
				end
				default: begin
				    fault_flag_comb = 0;
				end
			    endcase
			end

			CHARGING: begin
				//grid verification
				
				case(grid_state_enum)
				   GRID_CRITICAL: begin
				     fault_flag_comb = 1'b1;
				     fault_code_comb = 2'b11;
				   end
				   GRID_UNSTABLE: begin
					fault_flag_comb = 1'b0;
				        fault_code_comb = 2'b10;
				   end
				   GRID_NORMAL: begin
				    fault_flag_comb = 1'b0;
				    fault_code_comb = 2'b01;
				   end
				   
				   default: begin
					fault_flag_comb = safety_bus.ml_predict_instability;
				   end
			    	endcase
			end
			
			WAIT: begin
			   
			   case(grid_state_enum)
				   GRID_CRITICAL: begin
				     fault_flag_comb = 1'b1;
				     fault_code_comb = 2'b11;
				   end
				   GRID_UNSTABLE: begin
					fault_flag_comb = 1'b0;
				        fault_code_comb = 2'b10;
				   end
				   GRID_NORMAL: begin
				    fault_flag_comb = 1'b0;
				    fault_code_comb = 2'b01;
				   end
				   
				   default: begin
					fault_flag_comb = safety_bus.ml_predict_instability;
				   end
			    endcase
			    
			end

			FAULT: begin
				
				case(grid_state_enum)
				   GRID_CRITICAL: begin
				     fault_flag_comb = 1'b1;
				     fault_code_comb = 2'b11;
				     $display("SAFETY: FAULT ativado! grid_state=%s (%d)", 
                 grid_bus.grid_state.name(), grid_bus.grid_state);
				   end
				   GRID_UNSTABLE: begin
					fault_flag_comb = 1'b0;
				        fault_code_comb = 2'b10;
				        $display("SAFETY: Sem fault, grid_state=%s (%d)", 
                 grid_bus.grid_state.name(), grid_bus.grid_state);
				   end
				   GRID_NORMAL: begin
				    fault_flag_comb = 1'b0;
				    fault_code_comb = 2'b01;
				    $display("SAFETY: Sem fault, grid_state=%s (%d)", 
                 grid_bus.grid_state.name(), grid_bus.grid_state);
				   end
				   
				   default: begin
					fault_flag_comb = safety_bus.ml_predict_instability;
				   end
			    endcase
				
				if(!reset_n) begin
				    fault_flag_comb = 0;
				end
			end
			
			default: begin
				fault_flag_comb = safety_bus.ml_predict_instability;
			end
	       endcase
	       
	    end
	end
	
	//I pop the sequential logic out(don't need embrace fsm - safety)
	/*
	always_ff @(posedge clk or negedge reset_n) begin
	    if(!reset_n) begin
	        safety_bus.current_state <= IDLE;
	        safety_bus.grid_state <= '0;
	    end
	    else begin
	    	safety_bus.current_state <= fsm_bus.current_state;
	    	safety_bus.grid_state <= fsm_bus.grid_state;
	    end
	end
	*/
	
endmodule
					
