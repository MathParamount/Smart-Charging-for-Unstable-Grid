interface sc_connection;
    logic clk;
    logic reset_n;
    
    logic fault_flag;
    logic charge_enable;
    logic relay_activation;
    
    grid_state_t grid_state
    
    modport fsm_connect
    (
      input fault_flag,
      input grid_state,
      output charge_enable,
      output relay_activation
    );
    
    modport safety
    (
      output fault_flag,
      input grid_state
    );
    
endinterface

//I will going to declare in testbench: the interface name, 2modports with their internal signals.


