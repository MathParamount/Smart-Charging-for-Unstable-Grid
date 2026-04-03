#include <iostream>
#include "verilated.h"
#include "Vsc_dut.h"

#include "verilated_vcd_c.h" //wave form generation

using namespace std;

vluint64_t main_t = 0;

VerilatedVcdC* pointer = nullptr;
Vsc_dut* top = nullptr;

const vluint64_t clock_half_period = 10000;	//metade de 10ns

vluint64_t main_time = 0;	//to catch time unit of clock debug

//clock count, time unit count and generation waves
void tick(Vsc_dut *top, VerilatedVcdC* pointer)
{
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

int main(int argc, char **argv)
{
  Verilated::commandArgs(argc,argv);
  Verilated::traceEverOn(true);
  
  top = new Vsc_dut;
  pointer = new VerilatedVcdC;
  
  top->trace(pointer,99);
  pointer->open("wave.vcd");
  

  cout << "---------DEVICE_SIMULATION-----------" << endl;

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

