`timescale 1ns/1ps

module sc_fpga_top
(
  input logic clk,
  input logic reset_n,
  input logic battery_connected,
  input logic battery_full,
  input logic ml_predict_instability,
  input wire [15:0] grid_voltage_adc,
  input logic cmd,
  output logic charge_enable,
  output logic power_discharge,
  output logic fault_flag,
  output [2:0] current_state,
  output logic [1:0] fault_code
);
  
  import sc_types_pkg::*;
  
  //interface declaration
  sc_interface_if sc_interf_bus();
  
  assign sc_interf_bus.grid_voltage_adc = grid_voltage_adc;
  
  sc_dut u_sc_dut (
     .clk(clk),
     .reset_n(reset_n),
     .battery_connected(battery_connected),
     .cmd(cmd),
     .battery_full(battery_full),
     .ml_predict_instability(ml_predict_instability),
     .grid_voltage_adc(voltage_value),
     .charge_enable(charge_enable),
     .power_discharge(power_discharge),
     .fault_flag(fault_flag),
     .current_state(current_state),
     .fault_code(fault_code)
  );
  
  sc_grid_monitor u_grid 
  (
    .clk(clk),
    .reset_n(reset_n),
    .grid_bus(sc_interf_bus.grid_monitor),
    .fsm_bus(sc_interf_bus.fsm_connect)
  );
  
  sc_fsm u_fsm
  (
    .clk(clk),
    .reset_n(reset_n),
    .fsm_bus(sc_interf_bus.fsm_connect),
    .grid_bus(sc_interf_bus.grid_monitor)
  );
  
  sc_safety_monitor u_safety
  (
    .clk(clk),
    .reset_n(reset_n),
    .safety_bus(sc_interf_bus.safety),
    .grid_bus(sc_interf_bus.grid_monitor)
  );
  
  
  //output signals
  assign charge_enable = sc_interf_bus.charge_enable;
  assign power_discharge = sc_interf_bus.power_discharge;
  assign fault_flag = sc_interf_bus.fault_flag;
  assign fault_code = sc_interf_bus.fault_code;
  assign current_state = sc_interf_bus.current_state;
  
  //input signals
  assign sc_interf_bus.battery_full = battery_full;
  assign sc_interf_bus.battery_connected = battery_connected;
  assign sc_interf_bus.ml_predict_instability = ml_predict_instability;
  assign sc_interf_bus.cmd = cmd;
  
endmodule
