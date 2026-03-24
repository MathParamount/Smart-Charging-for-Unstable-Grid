#include <iostream>
#include "verilated.h"
#include "Vsc_dut.h"

#include "verilated_vcd_c.h" //wave form generation

using namespace std;

vluint64_t main_t = 0;

void tick(Vsc_dut *top)
{
	top->clk = 0;
	top->eval();
   main_t++;

	top->clk=1;
	top->eval();
	main_t++;
}

int main(int argc, char **argv)
{
  Verilated::commandArgs(argc,argv);
  Verilated::traceEverOn(true);
  
  Vsc_dut *top = new Vsc_dut;
  VerilatedVcdC* pointer = new VerilatedVcdC;
  
  top->trace(pointer,99);
  pointer->open("wave.vcd");
  
  cout << "---------DEVICE_SIMULATION-----------" << endl;
  
  top->clk = 0;
  top->reset_n = 0;

//
  for(int i =0; i< 5; i++)
  {
		top->clk = !top->clk;
		top->eval();
		
		pointer->dump(main_t*10 + 5);

		!(top->reset_n) ? cout << "reset is active" << endl : cout << "isn't active" << endl;
  }

  cout << "Actual time count: " << main_t << endl;

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
  
  //system test
  
  top->battery_full = 0;
  top->relay_active = 0;
  top->charge_enable = 0;
  top->grid_state = 0;
  tick(top,pointer);
	
  while(main_t < 50)
  {
  		top->battery_connected = 1;
	
  		if(main_t <= 10)
  		{
		/*
    	top->relay_active = 0;
	 	top->charge_enable = 0;
		top->fault_flag = 0;
	 	*/
		top->grid_state = 0;
  		}
  		else if(main_t <= 20)
  		{
	 	//top->relay_active = 0;
	 	top->grid_state = 1;
  		}
  		else if(main_t <= 30)
  		{
	 	/*
		top->charge_enable = 1;
	 	top->relay_active = 1;
	 	*/
		top->grid_state = 2;
  		}
  		else
  		{
	 	/*
		top->relay_active = 0;
	 	top->charge_enable =0;
		top->fault_flag = 1;
	 	top->battery_full = 1;
		*/
	 	top->grid_state = 4;
  		}

		//clock generation
		tick(top,pointer);
	}
  //top->grid_state = 0;	//Grid state(manual)

  top->ml_predict_instability = 0;

  //Verify result
  cout << "battery connected: " << (bool)top->battery_connected << endl;
  cout << "grid state: " << bitset<3> (top->grid_state) << endl;
  cout << "Battery full: " << (int)top->battery_full << endl;
  cout << "ml predict: " << (int)top->ml_predict_instability << endl;
   
  cout << "---------------FINAL_TEST-----------------" << endl;

  for(int time = 0; time < 1000; time++)
  {
     top->clk = !top->clk;
     top->eval();
     
     if(time%100 == 0) 
	  {
		  cout << "time step: " << time << endl;
  	  }
  }
   
  pointer->close();
  delete pointer;
  
  delete top;
  cout << "End simulation" << endl;
  
  return 0;
}
