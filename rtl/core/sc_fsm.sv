//global include from source include file
`include "rtl/include/sc_include.svh"

module sc_fsm
(
  //internal signal
  input logic clk,
  input logic reset_n,
  
  //going to actuator
  sc_interface_if.fsm_connect fsm_bus
);

import sc_types_pkg::*;
//O grid_state só é olhado no carregamento e no check_grid

grid_state_t grid_state_enum;

assign grid_state_enum = grid_state_t'(fsm_bus.grid_state);

state_t next_state;

always_comb begin
   //default
   next_state = fsm_bus.current_state;
   fsm_bus.charge_enable = 0;
   fsm_bus.relay_activation = 0;
   
   case(fsm_bus.current_state)
   	
	IDLE: begin
	   if(fsm_bus.battery_connected && !fsm_bus.battery_full) begin
	   	if(grid_state_enum == GRID_CRITICAL) begin
	     	  //fault_flag = 1'b1;
	    	  next_state = FAULT;
	   	end
	   	else begin
	   	  next_state = CHECK_GRID;
	   	end
	   end
	end
	
	CHECK_GRID: begin
	   if(grid_state_enum == GRID_CRITICAL) begin
	   	next_state = FAULT;
	   end
	   
	   else if(grid_state_enum == GRID_UNSTABLE) begin
	   	next_state = WAIT;
	   end
	   else begin
	   	fsm_bus.charge_enable = 1'b1;
		next_state = CHARGING;
	   end
	end
	
	CHARGING: begin
	   fsm_bus.relay_activation = 1'b1;
	   fsm_bus.charge_enable = 1'b1;
	   
	   if(fsm_bus.battery_full) begin
	   	fsm_bus.relay_activation = 1'b0;
	   	fsm_bus.charge_enable = 1'b0;
	   	
	   	next_state = IDLE;
	   end
	   
	   else if(grid_state_enum == GRID_UNSTABLE) begin
	   	fsm_bus.relay_activation = 1'b0;
	   	fsm_bus.charge_enable = 1'b0;
	   	next_state = WAIT;
	   end
	   
	end
	WAIT: begin
	    if(grid_state_enum == GRID_NORMAL) begin 
	   	next_state = IDLE;
	    end
	end
	
	FAULT: begin
	    if(reset_n) next_state = IDLE;
	end
	
	default: begin 
		next_state = FAULT;
	end
   endcase
   
end

/*
always_ff @(posedge clk or negedge reset_n) begin
   if(reset_n) begin
   	charge_enable_r <= 0;
   	relay_activation_r <= 0;
   end
   else begin
   	fsm_bus.charge_enable <= charge_enable_r;
   	fsm_bus.relay_activation <= relay_activation_r;
   end
   
end
*/
// registrador de estado
always_ff @(posedge clk or negedge reset_n) begin
  if (!reset_n)
    fsm_bus.current_state <= IDLE;
  else
    fsm_bus.current_state <= next_state;
end

endmodule
