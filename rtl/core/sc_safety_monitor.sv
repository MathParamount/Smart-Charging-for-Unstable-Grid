`timeunit 1ns/1ps;

`include "include/sc_include.svh"

module charge_supervised
(
	input logic clk, 
	input logic reset_n, 
	
	input logic grid_status,
	input logic battery_connected,
	
	//Machine learning
	input logic ml_predict_instability, 

	//actuators
	output logic fault_flag, 		//general fail
	output logic charge_enable,	//activate chagrging
	output logic [3:0] fault_code,	//fail code to diagnostic
	
	output grid_state_t current_state
);
	
	//internal signals
	reg [2:0] nex_state;
	logic charge_enable_next, fault_flag_next;
	logic [15:0] fault_code_next;
	
	//assigns
	assign fault_flag = fault_flag_next;
	assign fault_code = fault_code_next;
	assign charge_enable = charge_enable_next;
	
	//combinational logic to state conditions
	always_comb begin
		//default
		next_state = current_state;
		grid_status = current_state;
		charge_enable_next = 0;
		fault_flag_next = fault_flag;
		load_request = 0;
		
		case(current_state)
			IDLE: begin
				fault_flag_next = 0;
				fault_code_next = 0;
				charge_enable_next = 0;
				
				if(battery_connected) begin
					next_state = CHECK_GRID;
				end
			end
			
			CHECK_GRID: begin
			    case(grid_state)
				GRID_CRITICAL: begin
				    next_state = FAULT;
				    fault_flag_next = 1;
				end
				
				GRID_UNSTABLE: next_state = WAIT;
				
				GRID_NORMAL: next_state = CHARGING;
				
				default: next_state = FAULT;	
			    endcase
			end

			CHARGING: begin
				//grid verification
				
				case(grid_state)
				   GRID_CRITICAL: begin
				     charge_enable_next = 0;
				     fault_flag_next = 1;
				     next_state = FAULT;
				   end
				   GRID_UNSTABLE: begin
					charge_enable_next = 0;
					next_state = WAIT;
				   end
				   battery_full: begin
				     charge_enable_next = 0;
				     next_state = IDLE;
				   end
				   
				   default: next_state = IDLE;	
			        endcase
			end
			
			WAIT: begin
			
			   if(GRID_NORMAL && !ml_predict_instability)
			   begin
				next_state = CHECK_GRID;
			   end
			end

			FAULT: begin
				charge_enable_next = 0;
				
				if(reset_n) begin
					fault_flag_next = 0;
					next_state = IDLE;
				end
			end
		endcase
	end
	
	always_ff @(posedge clk or negedge reset_n) begin
		if(!reset_n) begin
			charge_enable <= 0;
			fault_flag <= 0;
			current_state <= IDLE;
		end
		else begin
			current_state <= next_state;
			charge_enable <= charge_enable_next;
			fault_flag <= fault_flag_next;
		end
	end
	
	//outputs(assigns)
	
endmodule
					
