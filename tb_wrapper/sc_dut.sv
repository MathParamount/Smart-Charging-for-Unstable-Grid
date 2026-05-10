<<<<<<< HEAD
`timescale 1ns/1ps

=======
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
// sc_dut.sv
module sc_dut
(
  input logic clk,
  input logic reset_n,
 
  input logic battery_connected,
  input logic battery_full,
<<<<<<< HEAD
  input logic ml_predict_instability,
  input logic [15:0] grid_voltage_adc,
  //input logic [15:0] grid_current_sensor,

  output logic charge_enable,
  output logic fault_flag,
  output [2:0] current_state,
  output logic [1:0] fault_code
=======
  input logic [1:0] grid_state,
  input logic ml_predict_instability,
  output logic fault_flag,

  output logic charge_enable,
  output logic relay_active,
  output logic [3:0] fault_code
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
);
  
  import sc_types_pkg::*;
  
  //unical interface to fsm and safety
<<<<<<< HEAD
  sc_interface_if sc_interf_bus();
  
  sc_grid_monitor u_grid 
  (
    .clk(clk),
    .reset_n(reset_n),
    .grid_bus(sc_interf_bus.grid_monitor),
    .fsm_bus(sc_interf_bus.fsm_connect)
  );
=======
  sc_interface_if sc_fsm_bus();
  sc_interface_if sc_safety_bus();
  
  assign sc_fsm_bus.grid_state = grid_state_t'(grid_state);
  assign fault_flag = sc_safety_bus.fault_flag;
  assign fault_code = sc_safety_bus.fault_code;
  assign sc_safety_bus.ml_predict_instability = ml_predict_instability;
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
  
  sc_fsm u_fsm
  (
    .clk(clk),
    .reset_n(reset_n),
<<<<<<< HEAD
    .fsm_bus(sc_interf_bus.fsm_connect),
    .grid_bus(sc_interf_bus.grid_monitor)
=======
    .fsm_bus(sc_fsm_bus)
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
  );
  
  sc_safety_monitor u_safety
  (
<<<<<<< HEAD
    .clk(clk),
    .reset_n(reset_n),
    .safety_bus(sc_interf_bus.safety),
    .grid_bus(sc_interf_bus.grid_monitor)
  );
  
  //join the interface with DUT
  assign charge_enable = sc_interf_bus.charge_enable;
  assign fault_flag = sc_interf_bus.fault_flag;
  assign fault_code = sc_interf_bus.fault_code;
  
  assign current_state = sc_interf_bus.current_state;
  
  //attach external input on interface
  assign sc_interf_bus.battery_full = battery_full;
  
  assign sc_interf_bus.grid_voltage_adc = grid_voltage_adc;
  //assign sc_interf_bus.grid_current_sensor = grid_current_sensor;
  assign sc_interf_bus.battery_connected = battery_connected;
  assign sc_interf_bus.ml_predict_instability = ml_predict_instability;
  
=======
    .reset_n(reset_n),
    .safety_bus(sc_safety_bus)
  );
  
  //join the interface with DUT
  assign charge_enable = sc_fsm_bus.charge_enable;
  assign relay_active=  sc_fsm_bus.relay_activation;
  
  //attach external input on interface
  assign sc_fsm_bus.battery_connected = battery_connected;
  assign sc_fsm_bus.battery_full = battery_full;

>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
endmodule
