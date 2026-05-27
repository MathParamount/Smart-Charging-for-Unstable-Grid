#include <iostream>
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


const double CLOCK_PERIOD_S = 100e-6;     // 100µs (10 kHz)
const double CLOCK_HALF_PERIOD_S = 50e-6;
const double PLECS_STEP_S = 500e-6;       // 500µs (2 kHz sampling)
const int CYCLES_PER_PLECS_STEP = 5;      // 5 * 100µs = 500µs EXATO		

//prototype
void set_voltage_dut(Vsc_dut_adapted* dut, double V_rms);

void set_voltage_dut(Vsc_dut_adapted* dut, double V_rms)
{
    const double V_MAX_RMS = 180.0;

    if (V_rms < 0) V_rms = 0;

	 double v_peak = V_rms * 1.414;
    int adc_value = (int)((v_peak * 65535.0) / V_MAX_RMS);
    
    if (adc_value < 0) adc_value = 0;
    if (adc_value > 65535) adc_value = 65535;
    
    dut->grid_voltage_adc = adc_value;

	 static int debug_count = 0;
    if (debug_count++ % 100 == 0) {
        printf("set_voltage: V_rms=%.2f, ADC=%d\n", V_rms, adc_value);
    }
}


extern "C" 
{
	DLLEXPORT void plecsSetSizes(struct SimulationSizes* aSizes) 
	{
	aSizes->numInputs = 1;
	aSizes->numOutputs = 2;
	aSizes->numStates = 0;
	aSizes->numParameters = 0;
	}

	DLLEXPORT void plecsStart(struct SimulationState* aState)
	{    
		  //Context
        contextp = new VerilatedContext;
		  contextp->traceEverOn(true);
        
        // create DUT
        dut = new Vsc_dut_adapted(contextp, "dut");
		   
   	  const int RESET_CYCLES = 5;		//same from testbench

    	  // aplly reset
    	  dut->reset_n = 0;
		  dut->battery_connected = 0;
    	  dut->charge_enable = 0;
    	  dut->grid_voltage_adc = 0;
  		  dut->ml_predict_instability = 0;
    
    	  // Executing clock cycles
    	  for (int i = 0; i < RESET_CYCLES; i++) {
         dut->clk = 0;
         contextp->timeInc(CLOCK_HALF_PERIOD_S);
         dut->eval();
        
         dut->clk = 1;
         contextp->timeInc(CLOCK_HALF_PERIOD_S);
         dut->eval();
    	 }
    
    	  // release reset
    	  dut->reset_n = 1;

    	 // MOre a cycle to stablish
		 for (int i = 0; i < 5; i++)
		 {
    	 dut->clk = 0;
    	 contextp->timeInc(CLOCK_HALF_PERIOD_S);
    	 dut->eval();
    
    	 dut->clk = 1;
    	 contextp->timeInc(CLOCK_HALF_PERIOD_S);
    	 dut->eval();
		 }

    	 dut->battery_connected = 1;
    
    	 // Initial voltage (127V RMS)
    	 set_voltage_dut(dut, 127.0);

		 for (int i = 0; i < 20; i++) {
        dut->clk = 0;
        contextp->timeInc(CLOCK_HALF_PERIOD_S);
        dut->eval();
        
        dut->clk = 1;
        contextp->timeInc(CLOCK_HALF_PERIOD_S);
        dut->eval();
    	  }

	 	 //debug
    	 printf("=== DUT Initialized ===\n");
    	 printf("Initial state: %d\n", dut->current_state);
    	 printf("Clock period: %.2f us\n", CLOCK_PERIOD_S * 1e6);
		 printf("PLECS step: %.2f us\n", PLECS_STEP_S * 1e6);
   	 printf("Cycles per PLECS step: %d\n", CYCLES_PER_PLECS_STEP);
   }
	
	
	DLLEXPORT void plecsOutput(struct SimulationState* aState)
	{
		  if (!dut || !contextp || !aState) {
            printf("plecsOutput: invalid state\n");
            return;
        }

		 
		  //debug: meeting in PLECS
		  static int call_count = 0;
        call_count++;
        
        if (call_count % 100 == 0) {
            printf("plecsOutput #%d: time=%.6f, input[0]=%.6f\n", 
                   call_count, aState->time, aState->inputs[0]);
        }

	    // RMS voltage from PLECS (input)
    	 double grid_voltage_rms = aState->inputs[0];
    	 
		 //Applying testbench voltage
		 set_voltage_dut(dut, grid_voltage_rms);

    	 // Execute clock cycles
    	 for (int i = 0; i < CYCLES_PER_PLECS_STEP; i++) {
        dut->clk = 0;
		  contextp->timeInc(CLOCK_HALF_PERIOD_S);
        dut->eval();

        dut->clk = 1;
		  contextp->timeInc(CLOCK_HALF_PERIOD_S);
        dut->eval();
    	 }
    	 
    	 aState->outputs[0] = dut->charge_enable;
   	 aState->outputs[1] = (double)dut->current_state;

    	 // Debug
    	 static int count = 0;
    	 if (count++ % 100 == 0) {
        printf("PLECS Step: V_rms=%.1fV, ADC=%d, State=%d, Charge=%d\n",grid_voltage_rms, dut->grid_voltage_adc, dut->current_state, dut->charge_enable);
       }		 
	}

DLLEXPORT void plecsEnd(struct SimulationState* aState)
{
	 printf("plecsTerminate called\n");

    if (dut) {
        delete dut;
        dut = NULL;
    }
    if (contextp) {
        delete contextp;
        contextp = NULL;
    }
}

}
