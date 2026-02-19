interface sc_interface_if;
    import sc_types_pkg::*;

    //grid
    grid_state_t grid_state;
    
    //STates
    state_t current_state;
    
    logic fault_flag;
    logic [3:0] fault_code;
    
    //control
    logic charge_enable;		//come from fsm
    logic relay_activation;
    
    //battery
    logic battery_connected;
    logic battery_full;
    logic ml_predict_instability;
    
    modport fsm_connect
    (
      input grid_state, 
      input battery_connected,
      input battery_full,
      input fault_code,
      output current_state,
      output charge_enable,
      output relay_activation
    );
    
    modport safety
    (
      output fault_flag,
      output fault_code,
      input current_state,
      input grid_state,
      input ml_predict_instability
    );
    
endinterface

//I will going to declare in testbench: the interface name, 2modports with their internal signals.

