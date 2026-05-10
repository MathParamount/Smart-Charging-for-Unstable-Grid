module sc_dut_adapted
(
  input wire clk,
  input wire reset_n,
  input wire battery_connected,
  input wire battery_full,
  input wire ml_predict_instability,
  input wire [15:0] grid_voltage_adc,

  output wire charge_enable,
  output wire fault_flag,
  output wire [2:0] current_state,
  output wire [1:0] fault_code,
  output wire [1:0] grid_state		//output to plecs
);

 import sc_types_pkg::*;
 import sc_include_pkg::*;

  sc_interface_if sc_interf_bus();
  
  assign sc_interf_bus.battery_full = battery_full;
  assign sc_interf_bus.grid_voltage_adc = grid_voltage_adc;
  //assign sc_interf_bus.battery_connected = battery_connected;
  
  assign sc_interf_bus.battery_connected = 1;
  
  assign sc_interf_bus.ml_predict_instability = 0;

  sc_top u_top (
    .clk(clk),
    .reset_n(reset_n),
    .battery_connected(sc_interf_bus.battery_connected),
    .battery_full(sc_interf_bus.battery_full),
    .grid_voltage_adc(sc_interf_bus.grid_voltage_adc),
    .ml_predict_instability(sc_interf_bus.ml_predict_instability),
    
    .charge_enable(sc_interf_bus.charge_enable),
    .fault_flag(sc_interf_bus.fault_flag),
    .current_state(sc_interf_bus.current_state),
    .fault_code(sc_interf_bus.fault_code),
    .grid_state(sc_interf_bus.grid_state)
  );

  // Coping signals
  assign charge_enable = sc_interf_bus.charge_enable;
  assign fault_flag    = sc_interf_bus.fault_flag;
  assign current_state = sc_interf_bus.current_state;
  assign fault_code = 	sc_interf_bus.fault_code;
  
  assign grid_state = u_top.u_grid.grid_state_enum;
  
  // debug
  always_ff @(posedge clk) begin
    $display("ADAPTER: battery_connected input = %0d", battery_connected);
  end
  
endmodule
