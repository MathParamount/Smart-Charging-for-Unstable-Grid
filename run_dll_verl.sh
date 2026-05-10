#!/bin/bash

set -e	#flag to stop if detect error(e)

TOP=sc_top

echo "-----------DLL simulation----------------"

#Generating the file
verilator \
  --cc \
  --build \
  --timescale "1ns/1ps" \
  -Wall \
  --assert \
  --lib-create new_dut \
  --x-assign unique \
  --x-initial unique \
  --top-module sc_dut_adapted \
  --public-flat-rw \
  -Irtl \
  -Irtl/interface \
  -Irtl/pkg \
  -Irtl/core \
  rtl/pkg/sc_types_pkg.sv \
  rtl/include/sc_include_pkg.sv \
  rtl/interface/sc_interface_if.sv \
  rtl/core/sc_grid_monitor.sv \
  rtl/core/sc_fsm.sv \
  rtl/core/sc_safety_monitor.sv \
  dll_interface/sc_dut_adapted.sv \
  dll_interface/plecs_interface.cpp \
  rtl/core/sc_top.sv
