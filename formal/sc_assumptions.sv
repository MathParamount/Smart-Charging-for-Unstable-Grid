module sc_assumptions(input logic clk, sc_interface_if fsm_bus);

import sc_types_pkg::*;

//batterty is only possible when we are charging
assume property(@(posedge clk)
  $rose(fsm_bus.battery_full) |-> fsm_bus.current_state == CHARGING
);

//battery connected don't oscillate in a mad way
assume property(@(posedge clk)
  $changed(fsm_bus.battery_connected) |-> fsm_bus.current_state == IDLE
);

//the reset_n only change with syncronically
assume property(@(posedge clk)
  $changed(reset_n) |-> $rose(clk)
);

//the relay is active in the positive edge of clock
assume property(@(posedge clk)
  $changed(fsm_bus.relay_activation) |-> $rose(clk)
);

//charge enable is high in the positive edge of clock
assume property(@(posedge clk)
  $changed(fsm_bus.charge_enable) |-> $rose(clk)
);

//fault code need be stable until happens a change
assume property(@(posedge clk)
  safety_bus.grid_state |-> $stable(safety_bus.fault_code)
);

endmodule
