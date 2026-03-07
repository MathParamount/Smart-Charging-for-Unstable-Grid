# Smart Charge Device State Diagram

# Motivation
 Grid instabilities brings significant challenges to electronic devices, often causing damage due to overvoltage/undervoltage conditions and unstable charging scenarios. These issues are particularly prevalent in regions with unreliable power infrastructure, where both overcharging and undercharging can compromise system integrity and device longevity. Electronic systems are fundamentally structured around states, with their behavior typically represented through finite state machines (FSM). In this project, we designed states that balance simplicity with high representativeness, adopting a philosophy that minimizes unnecessary state retention while maximizing system expressiveness. Each state was carefully conceived to encapsulate specific functionalities, with clearly defined state names, transition conditions, and outputs. The transition logic is documented in the state diagram, which specifies the precise conditions required to move from one behavioral mode to another.
The system architecture comprises five distinct states, each implementing specific actions and incorporating dedicated verification blocks that determine when to transition to subsequent states based on active signal flags.
The smart charge device exhibits a fundamentally simple behaviour: enabling or disabling battery charging through a solid-state relay (SSR) actuator, which toggles based on electrical grid conditions. Internal and external signals collectively govern the device workflow, ensuring proper operation under varying circumstances. Scalability and modularity were primary design considerations. Accordingly, we partitioned the system into separate safety and FSM files, a decomposition that enhances modularity, improves reliability, and eliminates both redundant transitions and unnecessary states

# FSM structure
 This project was tought to has 5 states with specific behaviour and each state has an internal signal, which specify the transitions.
 
## FSM file
 In the framework the FSM is responsible to generate charge enable activation and control the work flow.

 - IDLE: is the initial state with default signal values, which verifies the grid condition and point out to the next state of the system. The functionalities ringes on of the battery_connected and battery_full boolean signals.
 
 - CHECK_GRID: It's an intermediate state that is looking to the grid conditions before go to the charging state. 
 
 - CHARGING: the charge_enable is active and relay is energized to load the battery connected. In this state we have verification blocks to change the state, depending on of the grid condition.
 
 - WAIT: It wait the grid normal condition to come back to the charge activation and hold on the battery full or the battery desactivation signal to go to IDLE state. 
 
 - FAULT: It is state which locks the system when is detected the critical grid condition and get out of this state if the reset_n is low or pop the battery out.
 
## Safety file
 The safety module acts as a monitor that observes FSM behavior and sets the fault_flag and fault_code signals high or low based on grid conditions. The implementation incorporates a fault_code mechanism specifically designed to facilitate analysis and debugging. Additionally, the WAIT state verifies the machine learning prediction flag, which influences the safety structure and provides valuable debug insights.
 
# Conclusion
 This project was developed to comprehensively model device behavior and address inefficiencies present in contemporary charge controllers. The system has been simulated and rigorously tested under various grid conditions, demonstrating no inconsistencies. The implementation successfully resolves the complex behaviors inherent in smart charging systems while achieving high efficiency through modular simulations and effectively mitigating grid instabilities.
