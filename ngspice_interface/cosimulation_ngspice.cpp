#include "verilated.h"
#include "Vsc_dut.h"
#include "ngspice/sharedspice.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>


static int ng_getic(int, double*) { return 0;}
static int ng_send_data(void) {return 0;}
static int ng_unload(void) {return 0;}
static int ng_load(void) {return 0;}

double read_current_from_file() {

    std::ifstream file("ngspice_output.txt");
    if (!file.is_open()) return 0.0;
    
    std::string line;
    double current = 0.0;
    
    // Procura a última linha com corrente
    while (std::getline(file, line)) {
        if (line.find("i(vmeas1)") != std::string::npos) {
            // Encontra o valor após o "="
            size_t pos = line.find("=");
            if (pos != std::string::npos) {
                current = std::stod(line.substr(pos + 1));
            }
        }
    }
    file.close();
    return current;
}


int main(int argc, char **argv)
{
ngSpice_Init(NULL, NULL, NULL, NULL, NULL, NULL, NULL);

//circuit load
ngSpice_Command("source source_circuit.cir");

ngSpice_Command((char*)"display");	//debug


//verilator initialization
VerilatedContext* contextp = new VerilatedContext;
Vsc_dut* dut = new Vsc_dut(contextp, "dut");
dut->reset_n = 1;
dut->clk = 0;

//time declaration variables
double t = 0;
double dt = 1e-6;
double t_end = 10e-3;

double ctrl1, ctrl2, ctrl3, ctrl4;
char cmd[128];

ngSpice_Command((char*)"run");

while (t < t_end)
{
	/*
    // read corrent
    double current_1 = read_current_from_file();

    // transform to digital
    dut->ml_predict_instability = (current_1 > 1.0);
   
	// --- clock ---
    dut->clk = (fmod(t, 10e-9) < 5e-9) ? 1 : 0;

    dut->eval();

    // catch output
   ctrl1 = (dut->charge_enable && !dut->fault_flag) ? 5.0 : 0.0;
	ctrl2 = (dut->charge_enable && !dut->fault_flag) ? 5.0 : 0.0;
	ctrl3 = (dut->charge_enable && !dut->fault_flag) ? 5.0 : 0.0;
	ctrl4 = (dut->charge_enable && !dut->fault_flag) ? 5.0 : 0.0;


    // write in ngspice
 	 snprintf(cmd, sizeof(cmd), "alter Vctrl1 = %f", ctrl1);
	 ngSpice_Command(cmd);

	 snprintf(cmd, sizeof(cmd), "alter Vctrl2 = %f", ctrl2);
	 ngSpice_Command(cmd);

	 snprintf(cmd, sizeof(cmd), "alter Vctrl3 = %f", ctrl3);
	 ngSpice_Command(cmd);

	 snprintf(cmd, sizeof(cmd), "alter Vctrl4 = %f", ctrl4);
	 ngSpice_Command(cmd);


	 //print debug
	 printf("t=%.2e | I=%.4f | ctrl=%.1f | clk=%d | charge=%d | fault=%d\n",t, current_1, ctrl1, dut->clk, dut->charge_enable, dut->fault_flag);
	
	
    t += dt;
	 */

dut->ml_predict_instability = 0;  // Força = 1
    dut->battery_connected = 1;       // Conecta bateria
    dut->battery_full = 0;            // Bateria não cheia
    dut->grid_state = 0;              // Grid normal
    
    dut->clk = (fmod(t, 10e-9) < 5e-9) ? 1 : 0;
    dut->eval();
    
    printf("t=%.2e | charge=%d | fault=%d | ml=%d\n",
           t, dut->charge_enable, dut->fault_flag, dut->ml_predict_instability);
    
    t += dt;	 
}

printf("reset_n = %d\n", dut->reset_n);  // Deve ser 1

delete dut;
delete contextp;

return 0;
}
