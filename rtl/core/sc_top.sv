// sc_top.sv
module sc_top
(
input logic clk, 
input logic reset_n,
input logic battery_connected,
input logic battery_full,
input logic ml_predict_instability,
input grid_state_t grid_state
);

	sc_interface_if sc_bus();
	state_t current_state;
	
	//assignments
	always_comb begin
  	    sc_bus.battery_connected = battery_connected;
	    sc_bus.battery_full = battery_full;
	end
	
	sc_fsm u_fsm
	(
	  .clk(clk),
	  .reset_n(reset_n),
	  .fsm_bus(sc_bus),
	  .current_state(current_state)
	);
	
	sc_safety_monitor u_safety
	(
	  .clk(clk),
	  .reset_n(reset_n),
	  .ml_predict_instability(ml_predict_instability),
	  .safety_bus(safety_bus)
	);
	
endmodule
