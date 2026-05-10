interface sc_interface_if;
    import sc_types_pkg::*;
    
    //states
    state_t current_state;
    
    wire fault_flag;
    logic [1:0] fault_code;
    
    //control
    logic charge_enable;		//come from fsm
    
    //battery
    logic battery_connected;
    logic battery_full;
    logic ml_predict_instability;
    
    logic [15:0] grid_voltage_adc;
    
    logic data_valid;
    
    //grid state
    grid_state_t grid_state;
    
    //logic [15:0] grid_current_sensor;
    
    modport grid_monitor
    (
      input battery_connected,
      input grid_voltage_adc,
      //input grid_current_sensor,
  
      input ml_predict_instability,
      output grid_state,
      output data_valid
    );
    
    modport fsm_connect
    (
      input grid_state, 
      input battery_full,
      input fault_flag,
      input fault_code,
      input ml_predict_instability,
      input data_valid,
      output current_state,
      output charge_enable
    );
    
    modport safety
    (
      input current_state,
      input grid_state,
      input ml_predict_instability,
      input charge_enable,
      output fault_flag,
      output fault_code
    );
    
endinterface

//I will going to declare in testbench: the interface name, 2modports with their internal signals.


