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

endmodule
