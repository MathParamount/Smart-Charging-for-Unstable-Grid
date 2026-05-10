// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsc_dut_adapted.h for the primary calling header

#ifndef VERILATED_VSC_DUT_ADAPTED_SC_INTERFACE_IF_H_
#define VERILATED_VSC_DUT_ADAPTED_SC_INTERFACE_IF_H_  // guard

#include "verilated.h"


class Vsc_dut_adapted__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsc_dut_adapted_sc_interface_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*2:0*/ current_state;
    CData/*0:0*/ fault_flag;
    CData/*1:0*/ fault_code;
    CData/*0:0*/ charge_enable;
    CData/*0:0*/ battery_connected;
    CData/*0:0*/ battery_full;
    CData/*0:0*/ ml_predict_instability;
    CData/*0:0*/ data_valid;
    CData/*1:0*/ grid_state;
    SData/*15:0*/ grid_voltage_adc;

    // INTERNAL VARIABLES
    Vsc_dut_adapted__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsc_dut_adapted_sc_interface_if(Vsc_dut_adapted__Syms* symsp, const char* v__name);
    ~Vsc_dut_adapted_sc_interface_if();
    VL_UNCOPYABLE(Vsc_dut_adapted_sc_interface_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsc_dut_adapted_sc_interface_if* obj);

#endif  // guard
