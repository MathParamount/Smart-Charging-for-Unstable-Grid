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
    
## Analog circuit


# Instalation guide


# Observations

# status

# Conclusion

## Authors
