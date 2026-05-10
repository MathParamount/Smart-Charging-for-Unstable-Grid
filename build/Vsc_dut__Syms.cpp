// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsc_dut__pch.h"
#include "Vsc_dut.h"
#include "Vsc_dut___024root.h"
#include "Vsc_dut_sc_interface_if.h"
#include "Vsc_dut___024unit.h"

// FUNCTIONS
Vsc_dut__Syms::~Vsc_dut__Syms()
{
}

Vsc_dut__Syms::Vsc_dut__Syms(VerilatedContext* contextp, const char* namep, Vsc_dut* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
    , TOP__sc_dut__DOT__sc_interf_bus{this, Verilated::catName(namep, "sc_dut.sc_interf_bus")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    TOP.__PVT__sc_dut__DOT__sc_interf_bus = &TOP__sc_dut__DOT__sc_interf_bus;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    TOP__sc_dut__DOT__sc_interf_bus.__Vconfigure(true);
}
