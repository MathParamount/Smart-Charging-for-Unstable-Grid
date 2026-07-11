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

The digital control system is the core of the system which owns the state conditions and charge activation mechanism.

## Digital circuit (control logic)


## Analog circuit


# Instalation guide


# Observations

# status

# Conclusion

## Authors
