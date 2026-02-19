#include <iostream>
#include "verilated.h"
#include "Vsc_dut.h"

#include "verilated_vcd_c.h" //wave form generation

using namespace std;

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
  
  top->reset_n = 1;

  cout << "---------------SIGNAL_TEST-----------------" << endl;

  top->reset_n = 0;
  top->tick();
  top->reset_n = 1;

  top->battery_connected = 1;
  top->battery_full = 0;
  top->grid_state = 2;	//Grid_critical

  top->ml_predict_instability = 0;
  tick();


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



