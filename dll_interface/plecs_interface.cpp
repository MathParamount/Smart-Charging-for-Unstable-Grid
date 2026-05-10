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

	const vluint64_t CLOCK_CYCLES_PER_PLECS_STEP = 10.0;		//12 us

	const vluint64_t CLOCK_HALF_PERIOD_NS = 83333.0;  // 83.333 us = 12 kHz 

	DLLEXPORT void plecsStart(struct SimulationState* aState)
	{    
		  // Contexto mínimo
        contextp = new VerilatedContext;
		  contextp->traceEverOn(true);
        
        // Create DUT
        dut = new Vsc_dut_adapted(contextp, "dut");
        
		  dut->reset_n = 0;
		  dut->clk = 0;
		  dut->eval();

		  double clock_cycles = CLOCK_CYCLES_PER_PLECS_STEP * 1000.0 / CLOCK_HALF_PERIOD_NS;
   	  int num_cycles = (int)clock_cycles;

		  for(int i = 0; i < num_cycles; i++) {
        dut->clk = 0;
        contextp->timeInc((vluint64_t)(CLOCK_HALF_PERIOD_NS / 2.0));
        dut->eval();
        
        dut->clk = 1;
        contextp->timeInc((vluint64_t)(CLOCK_HALF_PERIOD_NS / 2.0));
        dut->eval();
   	  }		

		  // release reset
		  dut->reset_n = 1;	  
	 	  dut->eval();
	 }

	DLLEXPORT void plecsOutput(struct SimulationState* aState)
	{
	    if (!dut) return;
 		 
   	 double v_instant = aState->inputs[0];
    	 
		 double v_rms = fabs(v_instant) * 0.707; 

	    const double ADC_FULL_SCALE_VOLTAGE = 180.0;  // 180V RMS
       const double ADC_MAX_VALUE = 65535.0;

		 double adc_raw = (v_rms / ADC_FULL_SCALE_VOLTAGE) * ADC_MAX_VALUE;
    
    	 if (adc_raw > ADC_MAX_VALUE) adc_raw = ADC_MAX_VALUE;
    	 if (adc_raw < 0) adc_raw = 0;
    
    	 // Convert to uint16_t
    	 uint16_t adc_value = (uint16_t)adc_raw;
    
    	 // Debug to threshold verifications
    	 static int count = 0;
    	 if (++count % 10 == 0) {
        printf("DEBUG: v_instant=%.2f v_rms=%.2f ADC=%d (0x%04X)\n", 
               v_instant, v_rms, adc_value, adc_value);
        
        // Verifica thresholds
        if (adc_value < 18000) 
            printf("  -> V_CRIT_LOW (abaixo de 80V)\n");
        else if (adc_value >= 20000 && adc_value <= 50000) 
            printf("  -> Zona instável (%d-%d)\n", 20000, 50000);
        else if (adc_value > 60000) 
            printf("  -> V_CRIT_HIGH (acima de 260V)\n");
    	 }

    	 // update the adc
    	 dut->grid_voltage_adc = adc_value;
    	 dut->battery_connected = 1;

        // dut->battery_connected = (bool)aState->inputs[1];
        
        dut->battery_full = 0;
        dut->ml_predict_instability = 0;
        
        //debug
        /*
		  static int count = 0;
        if (++count % 100 == 0) {
            printf("DEBUG: V_inst=%.1f, ADC=%d\n", v_instant, dut->grid_voltage_adc);
        }
       */ 
        //clock
        for (int cycle = 0; cycle < CLOCK_CYCLES_PER_PLECS_STEP; cycle++) {
            dut->clk = 0;
            contextp->timeInc(CLOCK_HALF_PERIOD_NS);
            dut->eval();
            
            dut->clk = 1;
            contextp->timeInc(CLOCK_HALF_PERIOD_NS);
            dut->eval();
        }

		  //input
		 printf("IN0=%f | IN1=%f\n",
       aState->inputs[0],
       aState->inputs[1]); 

        // output
        static int step = 0;
        if (step++ % 100 == 0) {
           printf("fault=%d grid_state=%d in0=%f in1=%f\n",
       (int)dut->fault_flag,
       (int)dut->grid_state,
       aState->inputs[0],
       aState->inputs[1]);

fflush(stdout); 
        }

    	 
		 aState->outputs[0] = dut->charge_enable ? 1.0 : 0.0;
		 aState->outputs[1] = (double)dut->grid_voltage_adc;
		 //aState->outputs[5] = (double)dut->clk;  // debug
   }

}
