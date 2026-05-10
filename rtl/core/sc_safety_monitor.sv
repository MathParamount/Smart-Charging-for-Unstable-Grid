//`timeunit 1ns/1ps;
<<<<<<< HEAD
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
=======
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
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
				end
			    endcase
			end

			CHARGING: begin
				//grid verification
<<<<<<< HEAD
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
=======
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
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
				   end
			    	endcase
			end
			
			WAIT: begin
<<<<<<< HEAD
			   
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
=======
			    
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
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
				end
			end
			
			default: begin
<<<<<<< HEAD
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
=======
				safety_bus.fault_flag = safety_bus.ml_predict_instability;
			end
	       endcase
	end
	
	
	//outputs(assigns)
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
	
endmodule
					
