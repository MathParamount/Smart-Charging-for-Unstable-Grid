# Explanation
 Complex digital systems require internal mechanisms to specify illegal behaviors that could lead to catastrophic failures, and to track whether specific rules or scenarios have been previously exercised during verification. Assertions are statements about your design that are expected to always hold true. If an assertion condition is violated, the simulation immediately reports a failure. Assertions specify that certain unwanted conditions must never occur in the system, such as an unauthorized state transition or a change to an invalid state.
 The covers (cover properties) provide reactive measurement by checking whether a specific scenario, event, or sequence has ever occurred during test conditions. They help verify that interesting or critical scenarios are actually being exercised by the testbench.
 The assumptions file defines constraints for the verification environment, ensuring it does not violate system properties. In a complex device with numerous internal signals, we need to define rules that the environment must always obey, regardless of external instabilities, to maintain a stable configuration and valid stimulus.

# Environment modeling

## Assertions
 In a stable finite state machine (FSM), state transitions must be predictable and cannot arbitrarily deviate to unspecified states without proper structural definition. Moreover, the deadlock is a frequent issue in a digital design project. To enforce these requirements, we implemented an assertions file that explicitly prohibits random state transitions by monitoring the current_state signal. The assertions file structure was designed to validate all operational states except check_grid. This exception is based on the natural FSM flow, where IDLE serves as the initial state. Under normal conditions when grid instability is not detected the system transitions directly from IDLE to the check_grid state. The assertions implemented for each state are as follows:

- IDLE: Ensures that when a transition condition occurs, the next state will not be CHARGING. This verification is based on the FSM structure defined in the project scope.

- CHARGING: Prevents the system from either remaining in CHARGING or transitioning to CHECK_GRID when a transaction begins from the CHARGING state. In this state, we also verify battery connection status and full charge conditions.

- FAULT: Ensures that the next state after FAULT is exclusively IDLE. The only internal signals influencing this transition are `battery_connection` and `reset_negative`.

- WAIT: In this state, the system may only transition to CHARGING under normal grid conditions.

## Assumption
 The assumptions were formulated to constrain key signals and prevent nondeterministic behavior within the system workflow, thereby ensuring FSM compliance and overall system stability. In this project, the assumptions impose the following constraints:
 
- The battery_full signal may only be asserted while in the CHARGING state;
- The battery_connected signal must remain stable;
- The reset signal may only change on the rising edge of the clock;
- relay_activation transitions are synchronized with the clock edge;
- charge_enable obeys the clock pulses;
- The `fault_code` signal must remain stable under all grid state conditions.
 
## Covers
 The cover properties analyze state-dependent behaviors derived from assertion statements in the sc_assertion file, preventing incomplete system testing by ensuring that both current_state and internal signals are properly verified. The methodology applies a "thumb rule" where each assert property has an equivalent cover property, encompassing all relevant system excitations.
The cover properties were designed to comprehensively verify current_state transitions and internal signals, ensuring thorough system test coverage. Special attention is given to the check_grid exceptional case, as its internal functions are fundamental to maintaining system integrity.
 

