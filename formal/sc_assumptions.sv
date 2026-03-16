module sc_assumptions(input logic clk, sc_interface_if fsm_bus);

import sc_types_pkg::*;

//batterty is only possible when we are charging
assume property(@(posedge clk)
  $rose(fsm_bus.battery_full) |-> fsm_bus.current_state == CHARGING
);


endmodule
