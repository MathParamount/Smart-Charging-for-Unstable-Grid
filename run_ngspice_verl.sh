#!/bin/bash

set -e

TOP=sc_dut
BUILD_DIR=build_ngspice

#Clean build before
rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

#Generating the file
verilator \
  --cc \
  --exe \
  --build \
  --trace \
  --timescale "1ns/1ps" \
  -Wall \
  --assert \
  --x-assign unique \
  --x-initial unique \
  --top-module ${TOP} \
  -Irtl \
  -Irtl/interface \
  -Irtl/pkg \
  rtl/pkg/sc_types_pkg.sv \
  rtl/include/sc_include.sv \
  rtl/interface/sc_interface_if.sv \
  rtl/grid_montr/sc_grid_monitor.sv \
  rtl/core/sc_fsm.sv \
  rtl/core/sc_safety_monitor.sv \
  rtl/core/sc_top.sv \
  tb_wrapper/sc_dut.sv \
  ngspice_interface/cosimulation_ngspice.cpp \
  -o sim_${TOP} \
  -LDFLAGS "-L/usr/local/lib -lngspice -lstdc++" \
  -CFLAGS "-I/usr/local/include" \
  --Mdir ${BUILD_DIR}

