#!/bin/bash

set -e	#flag to stop if detect error(e)

TOP=sc_dut
BUILD_DIR=build

echo "-----------SYSTEMVEILOG WITH VERILAOTR---------------"

#Clean build before
rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

#Generating the file
verilator \
  --cc \
  --exe \
  --build \
  --trace \
<<<<<<< HEAD
  --timescale "1ns/1ps" \
=======
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
  -Wall \
  --assert \
  --x-assign unique \
  --x-initial unique \
  --top-module ${TOP} \
  -Irtl \
  -Irtl/interface \
  -Irtl/pkg \
  rtl/pkg/sc_types_pkg.sv \
<<<<<<< HEAD
  rtl/include/sc_include_pkg.sv \
  rtl/interface/sc_interface_if.sv \
  rtl/core/sc_grid_monitor.sv \
=======
  rtl/interface/sc_interface_if.sv \
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
  rtl/core/sc_fsm.sv \
  rtl/core/sc_safety_monitor.sv \
  rtl/core/sc_top.sv \
  formal/*.sv \
  tb_wrapper/sc_dut.sv \
  sim_run_tb.cpp \
  -o sim_${TOP} \
  --Mdir ${BUILD_DIR}
  
echo "----------------RUN SIMULATION---------------" 

#Executing the binary
./${BUILD_DIR}/sim_${TOP}

echo "----------------FINISHED SIMULATION ----------"
