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
		safety_bus.fault_flag = 1'b0;
		safety_bus.fault_code = 4'b0;
		
		case(safety_bus.current_state)
			IDLE: begin
				safety_bus.fault_flag = 0;
				safety_bus.fault_code = '0;
			end
			
			CHECK_GRID: begin
			    case(safety_bus.grid_state)
				GRID_CRITICAL: begin
				    safety_bus.fault_flag = 1'b1;
				    safety_bus.fault_code = 4'b0001;
				end
				
				GRID_UNSTABLE: begin
				    safety_bus.fault_code = 4'b0010;
				end
				
				GRID_NORMAL: begin 
				   safety_bus.fault_code = 4'b0011;			
				end
				default: begin
				   safety_bus.fault_flag = 1'b1;
				   safety_bus.fault_code = '0;			
				end
			    endcase
			    
			   	if(safety_bus.ml_predict_instability) begin
			   	    safety_bus.fault_flag = 1'b1;
			   	    safety_bus.fault_code = 4'b0100;
			   	end
			end

			CHARGING: begin
				//grid verification
				
				case(safety_bus.grid_state)
				   GRID_CRITICAL: begin
				     safety_bus.fault_flag = 1'b1;
				     safety_bus.fault_code = 4'b0101;
				   end
				   GRID_UNSTABLE: begin
					safety_bus.fault_code = 4'b0110;
				   end
				   GRID_NORMAL: begin
					safety_bus.fault_code = 4'b0111;
				   end
				   
				   default: begin
				   	safety_bus.fault_flag = 0;
				   end
			        endcase
			end
			
			WAIT: begin
			
			   if(safety_bus.grid_state == GRID_NORMAL && !safety_bus.ml_predict_instability)
			   begin
				safety_bus.fault_flag = 0;
			   end
			end

			FAULT: begin
				if(reset_n) begin
					safety_bus.fault_code = '0;
					safety_bus.fault_flag = 0;
				end
			end
			
			default: begin
				safety_bus.fault_flag = 0;
			end
		endcase
	end
	
	//outputs(assigns)
	
endmodule
					
