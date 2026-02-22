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
  
  cout << "---------Device_simulation-----------" << endl;
  
  top->clk = 0;
  top->reset_n = 0;
  top->eval();

  for(int i =0; i< 5; i++)
  {
		top->clk = !top->clk;
		top->eval();
  }

  cout << "---------------SIGNAL_TEST-----------------" << endl;

  top->reset_n = 0;
  for(int i =0; i < 5; i++) tick(top);
  top->reset_n = 1;

  tick(top);		//stabilization of 1 cycle

  top->battery_connected = 1;

  top->battery_full = 0;
  top->grid_state = 2;	//Grid_critical

  top->ml_predict_instability = 0;

  tick(top);		//capture active edge

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
     
     pointer->dump(time*10);
     
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
