module sc_assertions (input logic clk, sc_interface_if fsm_bus);

import sc_types_pkg::*;

/*the next state cannot be CHARGING state*/
a_assert: assert property (@(posedge clk)
    (fsm_bus.current_state == IDLE) |=> (fsm_bus.current_state != CHARGING)
);
	
//the battery full to condition to change the state
b_assert: assert property (@(posedge clk)
	(fsm_bus.current_state == CHARGING && (fsm_bus.battery_full || !fsm_bus.battery_connected))
	|=>
	(fsm_bus.current_state != CHARGING && fsm_bus.current_state != CHECK_GRID)
	);
	
endmodule
