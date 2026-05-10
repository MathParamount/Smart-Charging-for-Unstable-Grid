// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsc_dut.h for the primary calling header

#ifndef VERILATED_VSC_DUT_SC_INTERFACE_IF_H_
#define VERILATED_VSC_DUT_SC_INTERFACE_IF_H_  // guard

#include "verilated.h"


class Vsc_dut__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsc_dut_sc_interface_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*2:0*/ current_state;
    CData/*0:0*/ fault_flag;
    CData/*1:0*/ fault_code;
    CData/*0:0*/ charge_enable;
    CData/*0:0*/ relay_activation;

    // INTERNAL VARIABLES
    Vsc_dut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsc_dut_sc_interface_if(Vsc_dut__Syms* symsp, const char* v__name);
    ~Vsc_dut_sc_interface_if();
    VL_UNCOPYABLE(Vsc_dut_sc_interface_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsc_dut_sc_interface_if* obj);

#endif  // guard
