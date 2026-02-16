module charge_supervised_tb(input logic clk, logic reset_n);
	
	charge_supervised u_charge
	(
	   .clk(clk),
	   .reset_n(reset_n),
	   .grid_status(grid_status),
	   .battery_connected(battery_connected),
	   .charge_complete(charge_complete),
	   .load_request(load_request),
	   .ml_predict_instability(ml_predict_instability),
	);
	
endmodule
