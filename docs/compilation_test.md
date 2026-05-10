# Compilation tutorial

This project is designed with modularity and simplicity in mind to ensure a successful compilation process. The fundamental code is structured to facilitate easy setup and execution.

## Required packages

Before testing the program, you must verify that all necessary packages are installed on your system. The verification process depends on your operating system.

- In Linux (Ubuntu/Debian):

```
sudo apt update;
sudo apt upgrade;

sudo apt-get install verilator build-essential;	#install dependeces and verilator(GCC,Make)

```

There are some essential packages to compilation be sucessful.

```
sudo apt-get install g++;
sudo apt-get install make;

sudo apt-get install build-essential; 	#include g++,gcc and make packages
sudo apt-get install verilator;
sudo apt-get install gtkwave;
sudo apt-get install python3;		#some scripts in verilator

sudo apt-get install git help2man perl python3 make autoconf g++ flex bison libfl-dev ccache

```

- In Windows:

To run Verilator on Windows, you need to use the MSYS2 environment. It allows you to install Verilator, GCC/G++, Make, and GTKWave binaries. It is recommended to follow a dedicated tutorial that explains how to download and set up these tools for compilation on Windows.

# Terminal scripts

In this project, the script responsible for execution is `run_verl.sh`. This script handles:

1. Generation commands
2. Pointers to the `testbench` or `Build` folders
3. Automatic cleanup of the previous compilation's build folder

Additionally, the `build` folder is automatically created when the script is executed.

To run the script, navigate to the root directory of the project and execute the following command:

```
./run_verl.sh
```
