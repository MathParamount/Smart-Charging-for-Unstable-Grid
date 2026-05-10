// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut_adapted.h for the primary calling header

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted__Syms.h"
#include "Vsc_dut_adapted_sc_interface_if.h"

void Vsc_dut_adapted_sc_interface_if___ctor_var_reset(Vsc_dut_adapted_sc_interface_if* vlSelf);

Vsc_dut_adapted_sc_interface_if::Vsc_dut_adapted_sc_interface_if(Vsc_dut_adapted__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsc_dut_adapted_sc_interface_if___ctor_var_reset(this);
}

void Vsc_dut_adapted_sc_interface_if::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsc_dut_adapted_sc_interface_if::~Vsc_dut_adapted_sc_interface_if() {
}
