//global include from source include file
`include "include/sc_include.svh"

module sc_fsm
(
  //internal signal
  input logic clk,
  input logic reset_n,
  
  //come from grid_classifier
  input grid_state_t grid_state,
  
  //come from load
  input logic battery_connected,
  input logic battery_full,
  
  //come from safety
  input logic fault_flag,
  
  //going to actuator
  output logic charge_enable,
  output logic relay_activation,
  output state_t current_state
);

//O grid_state só é olhado no carregamento e no check_grid

reg [2:0] next_state;

always_comb begin
   //default
   next_state = current_state;
   
   case(current_state) begin
   	charge_enable = 1'b0;
   	relay_activation = 1'b0;
   	
	IDLE: begin
	   if(battery_connected && !battery_full) begin
	   	if(current_state == GRID_CRITICAL) begin
	     	  fault_flag = 1'b1;
	    	  next_state = FAULT;
	   	end
	   	else begin
	   	  next_state = CHECK_GRID;
	   	end
	   end
	end
	
	CHECK_GRID: begin
	   if(fault_flag) begin
	   	next_state = FAULT;
	   end
	   
	   else if(grid_state == GRID_CRITICAL) begin
	   	next_state = FAULT;
	   end
	   
	   else if(grid_state == GRID_UNSTABLE) begin
	   	next_state = WAIT;
	   end
	   else begin
	   	charge_enable = 1'b1;
		next_state = CHARGING;
	   end
	end
	
	CHARGING: begin
	   relay_activation = 1'b1;
	   
	   if(battery_full) begin
	   	relay_activation = 1'b0;
	   	charge_enable = 1'b0;
	   	
	   	next_state = IDLE;
	   end
	end
	WAIT: begin
	    if(grid_state == GRID_NORMAL) begin 
	   	next_state = IDLE;
	    end
	end
	
	FAULT: begin
	    if(reset_n) next_state = IDLE;
	end
	
	default: next_state = IDLE;
   end
   
   
end

always_ff @(posedge clk or negedge reset_n) begin
   if(!reset_n) begin
   	current_state <= IDLE;
   end
   else begin
   	current_state <= next_state;
   end
   
end

endmodule
