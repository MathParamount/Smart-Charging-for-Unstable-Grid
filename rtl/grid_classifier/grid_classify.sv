`include "rtl/include/sc_include.svh"

// sc_safety_monitor.sv
module sc_safety_monitor
(
  input logic clk,
  input logic reset_n,
  input logic [15:0] grid_voltage_adc,
  input logic [15:0] grid_current_sensor,
  
  input logic ml_predict_instability,
  
  //classification output
  output logic [15:0] measured_voltage,
  output grid_state_t grid_state
);

import sc_types_pkg::*;

logic [15:0] voltage_history [0:3];
logic [15:0] filter_volt;

// ----------Simple measure -------------
	
always_ff @(posedge clk) begin
	if(reset_n) begin
	voltage_history[0] <= '0;
	voltage_history[1] <= '0;
	voltage_history[2] <= '0;
	voltage_history[3] <= '0;
	filter_volt <= '0;
	end
	else begin
	voltage_history[0] <= grid_voltage_adc;
	voltage_history[1] <= voltage_history[0];
	voltage_history[2] <= voltage_history[1];
	voltage_history[3] <= voltage_history[2];
	   
	//simple measure after that is made a bit-wise to diveded by 4 the sum
	filter_volt <= (voltage_history[0] + voltage_history[1] + voltage_history[2] + voltage_history[3]) >> 2;
	end
end
	
assign measured_voltage = filter_volt;
	
//calcule to detect grid conditioN
always_comb begin
	 if(measured_voltage < v_critico_low_adc || measured_voltage > v_critico_high_adc || grid_current_sensor > MAX_CURRENT_ADC) begin
	    	grid_state = GRID_CRITICAL;
	 end
	    
	 else if(measured_voltage < v_unstable_min || measured_voltage > v_unstable_max || ml_predict_instability) begin
	 	grid_state = GRID_UNSTABLE;
	 end
	    
	 else begin
	 	grid_state = GRID_NORMAL;
	 end
end
