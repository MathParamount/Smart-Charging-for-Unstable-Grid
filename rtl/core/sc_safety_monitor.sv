//`timeunit 1ns/1ps;
`include "rtl/include/sc_include.svh"

module sc_safety_monitor
(
	input logic reset_n, 
	
	sc_interface_if.safety safety_bus
);
	import sc_types_pkg::*;
	
	//combinational logic to state conditions
	always_comb begin
		//default
		safety_bus.fault_flag = 0;
		safety_bus.fault_code = '0;
		
		grd_saft = grid_state_t'(safety_bus.grid_state);
		
		unique case(safety_bus.current_state)
			
			IDLE: begin
			   safety_bus.fault_flag = 0;
			   safety_bus.fault_code = 2'b00;
			end
			
			CHECK_GRID: begin
			    case(grd_saft)
				GRID_CRITICAL: begin
				    safety_bus.fault_flag = 1;
				    safety_bus.fault_code = 2'b11;
				end
				
				GRID_UNSTABLE: begin
				    safety_bus.fault_flag = 0;
				    safety_bus.fault_code = 2'b10;
				end
				
				GRID_NORMAL: begin 
				    safety_bus.fault_flag = 0;
				    safety_bus.fault_code = 2'b01;			
				end
				default: begin
				    safety_bus.fault_flag = safety_bus.ml_predict_instability;
				end
			    endcase
			end

			CHARGING: begin
				//grid verification
				case(grd_saft)
				   GRID_CRITICAL: begin
				     safety_bus.fault_flag = 1'b1;
				     safety_bus.fault_code = 2'b11;
				   end
				   GRID_UNSTABLE: begin
					safety_bus.fault_flag = 1'b0;
				        safety_bus.fault_code = 2'b10;
				   end
				   GRID_NORMAL: begin
				    safety_bus.fault_flag = 1'b0;
				    safety_bus.fault_code = 2'b01;
				   end
				   
				   default: begin
					safety_bus.fault_flag = safety_bus.ml_predict_instability;
				   end
			    	endcase
			end
			
			WAIT: begin
			    
			   if(grd_saft == GRID_UNSTABLE || grd_saft == GRID_NORMAL)
			   begin
				safety_bus.fault_flag = 0;
				safety_bus.fault_code = 2'b10;
			   end
			end

			FAULT: begin
				if(grd_saft == GRID_CRITICAL) begin
				   safety_bus.fault_flag = 1;
				   safety_bus.fault_code = 2'b11;
				end
				
				else if(grd_saft == GRID_NORMAL) begin
				   safety_bus.fault_flag = 1'b0;
				   safety_bus.fault_code = 2'b01;
				end
				
				else if(grd_saft == GRID_UNSTABLE) begin
				   safety_bus.fault_flag = 1'b0;
				   safety_bus.fault_code = 2'b10;
				end
				
				if(!reset_n) begin
				    safety_bus.fault_flag = 0;
				end
			end
			
			default: begin
				safety_bus.fault_flag = safety_bus.ml_predict_instability;
			end
	       endcase
	end
	
	
	//outputs(assigns)
	
endmodule
					
