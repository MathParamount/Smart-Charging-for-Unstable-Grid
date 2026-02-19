// sc_dut.sv
module sc_dut
(
  input logic clk,
  input logic reset_n,
 
  input logic battery_connected,
  input logic battery_full,
  input logic [1:0] grid_state,
  input logic ml_predict_instability,
  output logic fault_flag,

  output logic charge_enable,
  output logic relay_active,
  output logic [3:0] fault_code
);
  
  import sc_types_pkg::*;
  
  //unical interface to fsm and safety
  sc_interface_if sc_fsm_bus();
  sc_interface_if sc_safety_bus();
  
  assign sc_fsm_bus.grid_state = grid_state_t'(grid_state);
  assign fault_flag = sc_safety_bus.fault_flag;
  assign fault_code = sc_safety_bus.fault_code;
  assign sc_safety_bus.ml_predict_instability = ml_predict_instability;
  
  sc_fsm u_fsm
  (
    .clk(clk),
    .reset_n(reset_n),
    .fsm_bus(sc_fsm_bus)
  );
  
  sc_safety_monitor u_safety
  (
    .reset_n(reset_n),
    .safety_bus(sc_safety_bus)
  );
  
  //join the interface with DUT
  assign charge_enable = sc_fsm_bus.charge_enable;
  assign relay_active=  sc_fsm_bus.relay_activation;
  
  //attach external input on interface
  assign sc_fsm_bus.battery_connected = battery_connected;
  assign sc_fsm_bus.battery_full = battery_full;

endmodule
