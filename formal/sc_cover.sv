module sc_cover(input logic clk, sc_interface_if fsm_bus);

import sc_types_pkg::*;

 //cover IDLE state
 a_cover: cover property(@(posedge clk)
    (fsm_bus.current_state == IDLE) |=> (fsm_bus.current_state != CHARGING)
 );
 
 //cover charging state
 b_cover: cover property(@(posedge clk)
    (fsm_bus.current_state == CHARGING && (fsm_bus.battery_full || !fsm_bus.battery_connected))
    |=>
    (fsm_bus.current_state != CHARGING && fsm_bus.current_state != CHECK_GRID)
 );

  //cover Fault current state
 c_cover: cover property(@(posedge clk)
   (fsm_bus.current_state == FAULT && (fsm_bus.battery_connected || !reset_n) )
   |=>
   (fsm_bus.current_state != CHARGING && fsm_bus.current_state != CHECK_GRID && fsm_bus.current_state != WAIT)
 );
 
 d_cover: cover property(@(posedge clk)
   (fsm_bus.current_state == WAIT)
   |=>
   (fsm_bus.current_state != IDLE && fsm_bus.current_state != FAULT && fsm_bus.current_state != CHECK_GRID)
 );
 
 //covering exceptional state
 e_cover: cover property(@(posedge clk)
    fsm_bus.current_state == CHECK_GRID
 );
endmodule
