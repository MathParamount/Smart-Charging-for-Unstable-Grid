#include <iostream>
#include "verilated.h"
#include "Vsc_dut.h"

#include "verilated_vcd_c.h" //wave form generation

using namespace std;

<<<<<<< HEAD
VerilatedVcdC* pointer = nullptr;
Vsc_dut* top = nullptr;

const vluint64_t clock_half_period = 42000000;	// period of 83us

vluint64_t main_t = 0;

// Prototype
void tick(Vsc_dut *top, VerilatedVcdC* pointer);
void set_voltage(Vsc_dut *top, double V_rms);
=======
vluint64_t main_t = 0;

VerilatedVcdC* pointer = nullptr;
Vsc_dut* top = nullptr;

const vluint64_t clock_half_period = 10000;	//metade de 10ns

vluint64_t main_time = 0;	//to catch time unit of clock debug
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8

//clock count, time unit count and generation waves
void tick(Vsc_dut *top, VerilatedVcdC* pointer)
{
<<<<<<< HEAD

 cout << "tick start, time=" << main_t << endl;

    top->clk = 0;
    top->eval();

    main_t += clock_half_period;

    cout << "before dump 0" << endl;
    pointer->dump(main_t);

    top->clk = 1;
    top->eval();

    main_t += clock_half_period;

    cout << "before dump 1" << endl;
    pointer->dump(main_t);

    cout << "tick end" << endl;
}


void set_voltage(Vsc_dut *top, double V_rms)
{
    double Vmax = 400.0;  // maximum pick tension
    
	 if(V_rms < 0) V_rms = 0;	//negative values protection

	 double v_peak = V_rms * 1.414;

	 int adc_double = (v_peak * 65535.0) / Vmax;

	 int adc_value = (int)adc_double;

	 if(adc_value <0) adc_value = 0;

	 if(adc_value > 65535) adc_value = 65535;

    top->grid_voltage_adc = adc_value;
    printf("Time=%lu, V_rms=%.1f, ADC=%d\n", main_t, V_rms, adc_value);
}


//function to test the system 
void test_step(Vsc_dut *top)
{
	 static int cycle = 0;
	 cycle++;
	 
	 //reset after 1 cycle
	 if(cycle > 80) cycle = 1;

    double Vmax = 200.0;

    top->battery_connected = 1;
    top->ml_predict_instability = 0;

    double V_rms;

    if(cycle < 20)      V_rms = 127;	//normal
    else if(cycle < 40) V_rms = 70;		//critical low (~16200)
    else if(cycle < 60) V_rms = 260;	//critical high (~60200)
    else                V_rms = 100;	//unstable (~23150)
	 
    top->grid_voltage_adc = (int)(V_rms * 1.414 * 65535) / Vmax;
	 
	 set_voltage(top,V_rms);

	 printf("Time=%lu, V_rms=%.1f, ADC=%d\n", main_t, V_rms, top->grid_voltage_adc);
}


=======
	top->clk = 0;
	top->eval();
	
	main_t += clock_half_period;	//forward 10 ns

	pointer->dump(main_t);	//dump in clk=0

	top->clk=1;
	top->eval();
	
	main_t += clock_half_period;	//forward 10 ns

	pointer->dump(main_t);	//dump in clk=1
}

//function to test the system 
void test_function(Vsc_dut *top)
{
  top->battery_full = 0;
  top->relay_active = 0;
  top->charge_enable = 0;
  top->grid_state = 0;
  top->fault_flag = 0;
  top->fault_code = 0;
  
  tick(top,pointer);

  while(main_t < 20000000)
  {
  		top->battery_connected = 1;
	
  		if(main_t <= 50000)
  		{
		/*
    	top->relay_active = 0;
	 	top->charge_enable = 0;
		top->fault_flag = 0;
	 	*/
		top->grid_state = 0;
  		}
  		else if(main_t <= 100000)
  		{
	 	//top->relay_active = 0;
	 	top->grid_state = 1;
  		}
  		else if(main_t <= 150000)
  		{
	 	/*
		top->charge_enable = 1;
	 	top->relay_active = 1;
	 	*/
		top->grid_state = 2;
  		}
		else if( main_t <= 250000)
		{
			top->battery_full = 0;
			top->grid_state = 0;
		}
		else if (main_t <= 350000)
		{
		 top->ml_predict_instability=1;
		}
		else
		{
		top->ml_predict_instability = 0;
		}
		
		//clock generation
		tick(top,pointer);
	}
}

>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
int main(int argc, char **argv)
{
  Verilated::commandArgs(argc,argv);
  Verilated::traceEverOn(true);
  
  top = new Vsc_dut;
  pointer = new VerilatedVcdC;
  
  top->trace(pointer,99);
  pointer->open("wave.vcd");
  

  cout << "---------DEVICE_SIMULATION-----------" << endl;

<<<<<<< HEAD
  // Reset
  main_t = 0;
  
  top->reset_n = 0;
  top->battery_connected = 0;
  top->grid_voltage_adc = 0;
  top->ml_predict_instability = 0;

  for(int i = 0; i < 5; i++){
        tick(top, pointer);
  } 
  

  //deactivate reset
  top->reset_n = 1;
  for(int i = 0; i < 5; i++)
  {
	 tick(top,pointer);
  }

  //Initialization

  top->battery_connected = 1;
  
  set_voltage(top,127.0);		// 127v RMS

  //wait 20 cycles to fill filter
  for(int i = 0; i < 20; i++) {
        tick(top, pointer);
  }

  printf("Initial state: %d\n", top->current_state);
 
  // main test
  cout << "---------------SIGNAL_TEST-----------------" << endl;

 	 // voltage list to test
    struct TestStep {
        double v_rms;
        const char* description;
        int expected_state;  // 0=NORMAL, 1=UNSTABLE, 2=CRITICAL
		  int expected_adc_min;
		  int expected_adc_max;
    };
    
    TestStep tests[] = {
        {100, "Normal (100v)", 0, 23000, 24000},      // NORMAL; ADC ~23K
        {75, "Critical low (75v)", 17000, 18000},     // NORMAL 	ADC ~17.4K
        {220, "Critical high (220v)", 50000, 51000},   // NORMAL	 ADC ~50.9K
        {150,  "(Unstable (150v)", 34000, 35000},    // UNSTABLE	 ADC ~34.7K
    };
    
	 int num_tests = sizeof(tests) / sizeof(tests[0]);


    for(int test = 0; test < num_tests; test++) 
	 {
        printf("\n=== TEST %d: %s (%.0fV RMS) ===\n", 
               test+1, tests[test].description, tests[test].v_rms);
        
  		 // Apply tension
   	 set_voltage(top, tests[test].v_rms);

	         
   	 // wait cycle stabilization
   	 for(int i = 0; i < 20; i++) {
        	tick(top, pointer);
   	 }
        
		 // Read actual state
       int cpp_state = top->current_state;
        
       // Verifica se o estado é o esperado
       bool ok = (cpp_state == tests[test].expected_state);
   	 
		 printf("  Estado atual: %d (esperado: %d) - %s\n", 
               cpp_state, 
               tests[test].expected_state,
               ok ? "OK" : "ERRO");
        
        if(!ok) {
            printf("  ATENÇÃO: Estado incorreto!\n");
        }
		 // wait 10 cycles
       for(int i = 0; i < 10; i++) {
            tick(top, pointer);
       	 }
    }

 	 cout << "battery connected: " << (bool)top->battery_connected << endl;
  	 cout << "Battery full: " << (int)top->battery_full << endl;
  	 cout << "ml predict: " << (int)top->ml_predict_instability << endl;
  	 cout << "fault_code: " << (int)top->fault_code << endl;
 	 cout << "fault_flag: " << (int)top->fault_flag << endl;
  	 cout << "current_state: " << (int)top->current_state << endl;

  	 pointer->close();
  	 delete pointer;
  	 delete top;

  	 cout << "End simulation" << endl;
  	 return 0;
 
}
=======
  top->clk = 0;
  top->reset_n = 0;

// reset test during 5 clock cycles
  for(int i =0; i< 5; i++)
  {
		top->clk = !top->clk;
		top->eval();
		
		main_t += clock_half_period;

		pointer->dump(main_t);

		!(top->reset_n) ? cout << "reset is active" << endl : cout << "isn't active" << endl;
  }

  cout << "Actual time count: " << time << endl;

//

  cout << "---------------SIGNAL_TEST-----------------" << endl;
  
  top->clk = 0;
  top->reset_n = 0;

  //pointer->dump(main_t*10);	//manual dump for choice

  /*
  for(int i =0; i < 5; i++) tick(top,pointer);	 //Detect 5 clock stimulus
  */

  top->reset_n = 1;

  tick(top,pointer);		//stabilization of 1 cycle
  
  //system test function
  test_function(top);
 
  //top->grid_state = 0;	//Grid state(manual)

  top->ml_predict_instability = 0;

  //Verify result
  cout << "battery connected: " << (bool)top->battery_connected << endl;
  cout << "grid state: " << bitset<3> (top->grid_state) << endl;
  cout << "Battery full: " << (int)top->battery_full << endl;
  cout << "ml predict: " << (int)top->ml_predict_instability << endl;
  cout << "fault_code: " << (int)top->fault_code << endl;

  cout << "---------------FINAL_TEST-----------------" << endl;

  for(int time = 0; time < 10000; time++)
  {
     top->clk = !top->clk;
     top->eval();
     
	  main_time += 1;	//1 time unit

     if(time%100 == 0) 
	  {
		  cout << "time step: " << main_time << endl;
  	  }
  }
   
  pointer->close();
  delete pointer;
  
  delete top;
  cout << "End simulation" << endl;
  
  return 0;
}

>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
