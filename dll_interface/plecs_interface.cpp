#include "verilated.h"
#include "Vsc_dut_adapted.h"

#include <cmath>
#include <cstdio>

struct SimulationSizes {
    int numInputs;
    int numOutputs;
    int numStates;
    int numParameters;
};

struct SimulationState {
    double time;
    const double* inputs;
    double* outputs;
    const double* states;
    double* derivatives;
    const double* parameters;
};


static VerilatedContext* contextp = NULL;

static Vsc_dut_adapted* dut = NULL;
static vluint64_t last_time_ps = 0;

#ifdef _WIN32
    #define DLLEXPORT __declspec(dllexport)
#else
    #define DLLEXPORT __attribute__((visibility("default")))
#endif


extern "C" {
	DLLEXPORT void plecsSetSizes(struct SimulationSizes* aSizes) 
	{
	aSizes->numInputs = 1;
	aSizes->numOutputs = 2;
	aSizes->numStates = 0;
	aSizes->numParameters = 0;
	}

	const double PLECS_STEP_TIME_S = 0.001;  // 1ms by step
	const double CLOCK_PERIOD_S = 166.666e-9;  // 166.666μs = 6kHz
	const int CYCLES_PER_PLECS_STEP = (int)(PLECS_STEP_TIME_S / CLOCK_PERIOD_S);

	const vluint64_t CLOCK_HALF_PERIOD_NS = 83;  // 83.333 us = 12 kHz 

	DLLEXPORT void plecsStart(struct SimulationState* aState)
	{    
		  //Context
        contextp = new VerilatedContext;
		  contextp->traceEverOn(true);
        
        // Create DUT
        dut = new Vsc_dut_adapted(contextp, "dut");
        
		  dut->reset_n = 0;
		   
   	  const int RESET_CYCLES = 10;

		  for(int i = 0; i < RESET_CYCLES; i++) {
        dut->clk = 0;
    	  contextp->timeInc(CLOCK_HALF_PERIOD_NS);
        dut->eval();
        
        dut->clk = 1;
   	  contextp->timeInc(CLOCK_HALF_PERIOD_NS);
        dut->eval();
   	  }		

		  // release reset
		  dut->reset_n = 1;	  
	 	  dut->eval();

		  dut->clk = 0;
    	  contextp->timeInc(CLOCK_HALF_PERIOD_NS);
    	  dut->eval();
    
   	  dut->clk = 1;
    	  contextp->timeInc(CLOCK_HALF_PERIOD_NS);
    	  dut->eval();
    
    	  // Initialized the DUT
    	  dut->grid_voltage_adc = 0;
        dut->battery_connected = 1;
    	  dut->charge_enable = 0;
	}

	DLLEXPORT void plecsOutput(struct SimulationState* aState)
	{
	    if (!dut || !aState) return;

		 // Read analog input
    	 double volt_peak = aState->inputs[0];
    
    	 // COnvert  to adc
    	 const double V_MAX_PEAK = 180.0;
    	 int adc_value = (int)((volt_peak / V_MAX_PEAK) * 65535.0);
   	  if (adc_value < 0) adc_value = 0;
    	 if (adc_value > 65535) adc_value = 65535;
    
    	 // Apply the DUT
    	 dut->grid_voltage_adc = adc_value;
    	 dut->battery_connected = 1;
    
    	 // Execute clock cycles
    	 for (int i = 0; i < CYCLES_PER_PLECS_STEP; i++) {
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
    	 }
    
    	 // Send data to PLECS
    	 aState->outputs[0] = dut->charge_enable;
    	 aState->outputs[1] = (double)adc_value;
    
    	 // Debug (opcional)
    	 static int count = 0;
    	 if (count++ % 1000 == 0) {
        printf("Vin=%.1fV, ADC=%d, Charge=%.0f\n", 
               volt_peak, adc_value, dut->charge_enable);
    	 }
 		 
	}

	DLLEXPORT void plecsTerminate(struct SimulationState* aState)
	{
    delete dut;
    delete contextp;
    printf("DLL finalized\n");
	}
}
