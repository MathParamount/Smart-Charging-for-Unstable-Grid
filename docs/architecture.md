# Summary
 A device to control the charge derived from the electric grid has a lot of internal signals that ringes on of the finite state machine(FSM) and actuators to make the system works. We tought in split the system between FSM and safety modules. Knowing that the system need to divide among different signals to transfer data between FSM and Safety system, like a data share among different buses. Hence, we implemented an interface to control the data flow.
 The different functionalities among modules follows a philosofy of modularity and simplicity to become the system more easy to debug and scalable to do complex behaviours. We defined the FSM responsibilites to control the external response and define the system state. The Safety module urge the FSM signals to generate the flag and codification of the system's actual stage. 

# Problem to solve
The current architecture was designed to simplify the smart charge device while maintaining an efficient system capable of handling grid instability conditions. However, the original digital design presented significant issues, which were addressed in this project. Among these problems were:
- Deadlock caused by the FSM sending data to the safety module through the same route.
- Signal synchronization issues within the device to ensure data is received precisely at the clock edge and to avoid timing delays.
- Gate delay on module inputs, affecting signal integrity.
- Coupling between the FSM and the safety module, which must operate in close coordination.
- Synchronization with the electrical grid, particularly concerning zero-cross detection and grid frequency.
- Measurement and filtering layer required before signals reach the FSM.

# Structure

## Interface
 The interface instantiates the signals and modules, defining their directions and interconnections. It is instantiated twice, each with specific port modes and designated names.
In this project, the interface functions as a bus that routes signals, helping to avoid deadlock and signal propagation issues. More importantly, it enhances modularity, simplifies debugging, and facilitates division of labor, ensuring the system remains scalable and maintainable.

## Internal signals
 The FSM sends signals to the interface, which then redirects them to the appropriate modules, such as the safety module. A clear separation between internal and external signals was established to improve control and security. Signals such as `charge_enable` and `relay_activation` are responsible for enforcing this separation.
The battery status, split into `battery_full` and `battery_connected` that is received from the device and forwarded to the FSM. Based on this information and the current grid conditions, the FSM adjusts its behavior accordingly. Grid conditions are represented internally by the signal grid_state.

# Technical limitation

## 1. Coupling between modules
 The FSM and Safety has a tightly coupled interface emerging a possible failure point. If the Safety module enter in an undefined state the FSM cannot recover, requiring a system reset.

## 2. Synchronization Overhead
 The grid syncronism need to analyze the zero-cross using, for example, an LM393 comparator or a 4N25 optocoupler for isolation. It insert certain uncertainties in the system affecting precision.

## 3. Scalability Concerns
 Adding new grid conditions will need to modify the FSM logic to be able to accomplish the smart charge project. As the actual system is unstable when there is a high grid volatility changing from a state to another in a continual way emerging a risk of remain in an atypical grid condition.

## 5. Testability Challenges
 The internal signal grid_state is not directly observable at the module boundaries, making system detection error without additional test hooks or physical instrumentations.
