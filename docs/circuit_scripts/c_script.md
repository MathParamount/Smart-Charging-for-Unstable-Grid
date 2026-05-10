# Description
  The circuit was built to be implemented in SystemVerilog using Verilator to debug and simulate the digital design. Moreover, the waveform modeled the high and low level digital design to do a behaviour in critical conditions in a grid with high incertaints that has a high chance of metastabilities. Thus was implemented in a modular and 
easy way to wrap up the overtension and high frequency ordem.
The system was analyzed and debuged in SystemVerilog building a signal commands that correspond the grid condition.

# Limitations
The core code of the system isn't able to get direct input of alternate current and direct grid frequency, hence we developed a c-script algorithm in PLECS system to be able to receive analog signals direct from load simulations.

# Conclusion
