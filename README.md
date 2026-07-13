# Overview

Modern society relies heavily on high-power electronic devices, creating an urgent demand for advanced charging infrastructure. While smart charging is predominantly used in automated systems for Electric Vehicles (EVs), it is increasingly being adapted for smartphones, desktops, and general battery systems. However, outside of corporate tech environments, many of these systems still lack full automation and artificial intelligence integration. 

When evaluating charging architecture connected to the grid (categorized as *in-line* and *on-line*), traditional performance metrics like switching time are losing their relevance. 
For instance, while an in-line charger boasts a switching time of under 1 ms, commercially available smart chargers are already achieving near-zero (~0 ms) switching times. 
Therefore, response time is no longer the most efficient metric for evaluating modern system performance.
Currently, there is a lack of publicly available digital architectures for these systems. This project addresses this gap by providing a mathematically analyzed and extensively designed system using co-design tools
**PLECS co-simulation** is utilized as a core tool to link power electronic circuits with digital circuits (control logic). 

This approach makes the system more robust and significantly less prone to design faults when facing real-world instabilities.
Finally, real-world implementation is a crucial step for system testing and practical use cases. 
**Digital Signal Processing (DSP)** is employed as a landmark tool to test the system's real-time reaction to environmental noise and grid disturbances.

## Problem statement & user case

### The Brazilian energy Scenario

Energy instability in Brazil is an emerging issue that causes device damage and poses security risks. According to data from the ONS (*Operador Nacional do Sistema Elétrico*), 14.4% of the Brazilian population experienced energy instability during the World Cup in 2026. Furthermore, a lack of Smart Energy Management leads to significant energy loss and higher costs. An intelligent management system can detect and predict grid instabilities, communicating with both the end-users and the broader grid to prepare for energy fluctuations. This optimizes grid performance and minimizes costs during energy congestion. 
Additionally, the excess of renewable energy in the grid often triggers instabilities, such as frequency spikes and low system inertia (caused by reactive power). The current worldwide method to mitigate this relies on synchronous condensers—a costly tool with low scalability. These physical tools could be largely bypassed if a smart grid, driven by a predictive power management system, were implemented to detect and handle these instabilities dynamically.

### Global Scenario

The surging computational demands of AI training and data center operations have become an escalating issue, as massive amounts of energy are consumed for model training and cooling systems in these energy-hungry facilities. According to the International Energy Agency (IEA), data centers are projected to account for 3% to 4% of global energy consumption by the end of this decade. An Intelligent Energy Management System can mitigate this issue by scheduling energy intensive tasks during off-peak hours when grid congestion is low. This **load-shifting strategy** significantly reduces greenhouse gas emissions associated with fossil-fuel based peak power generation.

Furthermore, the Electric Reliability Council of Texas (ERCOT) has publicly warned about the growing implications of large, flexible loads, such as data centers, for long-term grid planning and operational stability. This dynamic creates a critical structural mismatch: while compute infrastructure can scale rapidly, electrical grid infrastructure generally cannot.

## Our solutions

This project aims to mitigate the hazards caused by grid instability during the charging process. The proposed **Power Management System (PMS)** detects and predicts grid anomalies, sending data to the actuators to make real-time decisions. 

**Key Technical Highlights:**

* **Control Logic & Verification:** The control logic is designed using EDA (Electronic Design Automation) software with **formal verification**, guaranteeing the resolution of metastability conditions.
* **Evolution of Scope:** Initially designed exclusively for Electric Vehicles (EVs), the architecture has evolved to support general battery charging and discharging (V2G/B2G concepts).
* **Hardware-in-the-Loop / DSP:** Utilizes DSP to ensure the digital control logic reacts accurately to real-time physical noise and grid variations.

## 🛠️ Tech Stack & Tools

* **Co-Simulation:** PLECS (Power electronics and digital control logic)
* **Hardware/Implementation:** DSP (Digital Signal Processing)
* **EDA & Verification:** Verilator, C++
* **Target Applications:** EVs, Smartphone/Desktop charging, Battery Energy Storage Systems (BESS)

# Architecture

The digital control system is the core of the architecture, responsible for managing state conditions and the charge activation mechanism. It receives the grid voltage and processes decisions based on real-time grid conditions. An internal buffer is utilized to calculate a moving average, which determines the filtered voltage used for comparison against an internal threshold.

## Digital circuit (control logic)

A high-level block diagram was created to define the signal routing and processing paths. The architecture consists of four main digital blocks, each with a specific internal logic function. A Finite State Machine (FSM) is implemented to manage state transitions, while the `grid_state` variable is evaluated within the Grid Monitor block.

<img width="31819" height="8175" alt="architecture" src="https://github.com/user-attachments/assets/1f6f35c7-d518-4d13-bc20-8946d40f0bb6" />

* **Grid Monitor:** Responsible for acquiring the `grid_voltage` and sensor data, and processing this information. Initially, it requires a stabilization and synchronization period upon battery connection. Subsequently, an internal buffer is filled with historical grid voltage data to calculate a moving average, which determines the current `grid_state` for the system.

* **State Machine:** Receives the state signal and checks the battery connection status and data validity flags to determine FSM transitions. Furthermore, charge activation is enabled only when the current state and transitions match the specific internal requirements for charging.

<img width="13084" height="6132" alt="FSM(2)" src="https://github.com/user-attachments/assets/dbbcf9b7-b4ca-4ef3-b1b2-6a23e107d8d6" />

* **Interface:** Serves as the interconnect block, managing signal directions and orchestrating the `modports` and signal routing/handshaking among the different modules.

* **Safety Monitor:** Acts as a protection block that continuously evaluates grid conditions. It asserts a binary fault signal to indicate a FAULT state and generates system error codes for debugging and simulation analysis.


### Waveforms && digital flow

<img width="1867" height="315" alt="wave_general" src="https://github.com/user-attachments/assets/49aef023-adf0-4b29-abb5-2c7085c3522e" />

The simulation waveforms demonstrate proper synchronization with minimal latency between signal transmissions within the system's communication protocol. In-depth details regarding the inter-signal activation delays and synchronization techniques are thoroughly documented and commented within the RTL code, following a careful analysis to optimize system responsiveness.

The system initializes with a reset signal for validation purposes, after which the signals begin transitioning according to the designed logic. The waveform below illustrates the initial simulation phase, showing the system's startup behavior and signal stabilization.

<img width="1371" height="280" alt="screenshot1" src="https://github.com/user-attachments/assets/b3a8314e-cc6f-481d-a21f-414a4b8a9077" />

**Key Observations:**

1) **Synchronization:** The protocol maintains tight synchronization between control signals.
2) **Latency:** Minimal delay observed between activation signals, ensuring fast response to grid conditions.
3) **Reset Sequence:** The system properly initializes from the reset state before transitioning to operational modes.
    
## Analog Circuit & PMS Implementation

The analog subsystem focuses on co-simulation and actuator interfacing, interacting directly with grid conditions to regulate energy delivery to the load. Physical connections introduce challenges such as synchronization issues and switching delays. However, because the electrical grid operates at a relatively low frequency (e.g., 60 Hz, with a ~16.6 ms period), the time required to measure and make decisions is considerably slower compared to high-speed digital logic. Nevertheless, the fault-clearing time (the time required to safely interrupt or revert an action) is fundamental for overall system stabilization. Hence, to bridge the digital and analog domains, the digital control logic was re-implemented as a C-Script within PLECS, strictly adhering to the platform's coding rules.

<img width="1586" height="835" alt="circuitoverw_Top" src="https://github.com/user-attachments/assets/64ec2fe3-ebec-4605-9893-935ddbb44600" />


### Power Management System (PMS) Design
The PMS was designed to process a three-phase power supply with a 120-degree phase displacement. The system operates with a sample time of **1/6000 s** (approx. 166 us, yielding 100 samples per 60 Hz cycle), utilizing 5 inputs and 7 outputs.

<img width="1374" height="526" alt="code_declaration1" src="https://github.com/user-attachments/assets/c8460117-8fa7-451b-a0b3-2e873c7c11de" />


Inside the PMS C-Script, the Root Mean Square (RMS) voltage for each phase is calculated using a moving average filter. The output function computes the individual phase RMS values, which are then combined to calculate an **equivalent grid voltage** (the aggregate RMS of the three phases).

### Grid State Evaluation & BESS Control

Based on this equivalent grid voltage, the system determines the current grid condition. This information is then processed by a Finite State Machine (FSM), which defines the current operational stage. Finally, the FSM sends this state information to the Battery Energy Storage System (BESS) via the `bess_cmd` signal, dictating the battery's operational mode and defining the simulation test scenarios.

### Signal Definitions

**Inputs:**
* `battery_connected` (Digital signal)
* `Va` (Voltage Phase A)
* `Vb` (Voltage Phase B)
* `Vc` (Voltage Phase C)
* `SOC` (State of Charge)

**Outputs:**
* `rms_valid` (Digital signal)
* `grid_state` (Enumerated type)
* `current_state` (Enumerated type)
* `fault_flag` (Digital signal)
* `fault_code` (Integer / Error Code)
* `Vgrid` (Float type)
* `bess_cmd` (Enumerated type)

# Instalation/Compilation guide

<img width="965" height="883" alt="compilation_guide" src="https://github.com/user-attachments/assets/2b71d1bc-6781-4b05-bb37-b44f7de3e792" />

## Prerequisites

Before compiling the project, make sure the following tools are installed:

- Verilator (version 5.x or newer recommended)
- GTKWave (for waveform visualization)
- GNU Make
- GCC/G++ compiler
- Git
- Bash shell (Linux or WSL on Windows)

It is also recommended to keep your operating system updated before installing the required packages.

## Clone the Repository

Clone the repository and enter the project directory:

```bash
git clone https://github.com/MathParamount/Smart-Charging-for-Unstable-Grid.git
cd Smart-Charging-for-Unstable-Grid
```

## Project Structure

```
.
├── rtl/                 # SystemVerilog source files
├── sim_run_cpp          # C++ simulation/testbench
├── run_verl.sh          # Build and simulation script
├── run_dll_verl.sh
├── sim_run_tb.cpp       # The test file
├── obj_dir/
├── formal/              # Formal verification folder
├── dll_interface/       # An DLL implementation test tentative
├── build/               # Generated during compilation
├── docs/                # Documentantion and project description
├── obj_dir/             # Generated by Verilator
├── ML/                  # A simple machine learninig implementation
└── wave.vcd             # Generated simulation waveform
```

## Compile and Run

The easiest way to compile and execute the simulation is:

```bash
cd ./Smart-Charging-for-Unstable-Grid
chmod +x run_verl.sh
./run_verl.sh
```

The script automatically:

1. Compiles the SystemVerilog sources using Verilator.
2. Compiles the C++ testbench.
3. Links the generated executable.
4. Runs the simulation.
5. Generates the waveform file (`wave.vcd`).

Wait until the compilation finishes successfully. The terminal will display simulation logs and test information.

## Viewing the Waveform

After a successful execution, open the generated waveform:

```bash
gtkwave wave.vcd
```

or, if the waveform is inside the build directory,

```bash
gtkwave build/wave.vcd
```

**Note:** The exact command may vary depending on the modules included in your project.

## Simulation

The C++ testbench (`sim_run_cpp/script_test.cpp`) is responsible for:

- Applying reset sequences.
- Generating the system clock.
- Sending transactions.
- Monitoring the DUT outputs.
- Producing the `wave.vcd` file for waveform analysis.

The `build/` and `obj_dir/` directories are automatically generated during compilation and contain intermediate files, generated C++ sources, object files, and the simulation executable.

# Observations

- The mixed-signal co-simulation was one of the most challenging parts of the project. Several approaches were investigated, including Ngspice integration and DLL-based communication.
- The digital hardware was designed as a secure communication interface intended for electric vehicle (EV) charging and discharging applications.
- The hardware prototype is currently under development.
- The SystemVerilog implementation incorporates mechanisms to reduce metastability risks and includes assertions and formal verification constructs where applicable.
- Artificial intelligence techniques have been explored to improve system maintenance, monitoring, and future project scalability.

# status

- Digital architecture design (Completed)
- RTL code (Completed)
- Waveform analyses (Completed)
- Interface and formal verification (Completed)
- Co-simulation digital + analog (Completed)
- Documentation (In progress)
- New versions (release) with improvements (In progress)
- Battery adaptation to discharge (In progress)
- FPGA testbench analyses (In progress)
- DSP implementation (In progress)
- Improve IA implementation (In progress)

# Conclusion

This project successfully demonstrated the design and co-simulation of a Smart Grid-Aware Power Management System capable of detecting, predicting, and mitigating grid instabilities during charging processes. The core innovation lies in the seamless integration of digital control logic with analog power electronics through PLECS co-simulation, creating a robust architecture that bridges the gap between theoretical design and real-world deployment. By implementing the control logic as a C-Script within PLECS and validating it through RTL-level waveform analysis, the system achieves deterministic behavior with formal verification, ensuring safe state transitions and reliable fault handling.
The technical approach combined multiple layers of abstraction to create a comprehensive solution. At the digital level, a Finite State Machine manages charging states based on real-time grid conditions, while the analog interface handles three-phase voltage monitoring with a 1/6000 second sampling rate. This high-frequency sampling enables the system to react within a fraction of the 60 Hz grid cycle (approximately 16.6 ms).

The practical relevance of this work extends across multiple domains. In the Brazilian context, where grid instabilities affect millions of users and cause significant equipment damage, the proposed PMS offers an intelligent alternative to costly infrastructure solutions like synchronous condensers. By detecting and predicting grid anomalies before they cascade into larger failures, the system can proactively adjust charging behavior, reducing stress on the grid during congestion events. This is particularly important as renewable energy sources introduce lower system inertia and frequency spikes that challenge traditional grid management approaches. On a global scale, the system addresses the emerging energy crisis driven by AI training and data center operations. With data centers projected to consume 3 to 4 percent of global energy by the end of this decade, intelligent energy management becomes critical. The PMS enables load-shifting strategies, scheduling energy-intensive operations during off-peak hours when grid congestion is minimal. This not only reduces operational costs but also decreases greenhouse gas emissions associated with fossil-fuel based peak power generation.

## Authors

- Gabriel da cruz # (Digital architecture design | Systemverilog implementation | Testbenchs tests | SV to C-script translation);
- Prof. João Marcus Callegari # (Analog implementation | Plecs adjusts | Co-simulation guide | PMS and BESS design | hardware implementation mentor);
