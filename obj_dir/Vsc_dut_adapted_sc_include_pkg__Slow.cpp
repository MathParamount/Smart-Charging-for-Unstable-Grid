// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut_adapted.h for the primary calling header

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted__Syms.h"
#include "Vsc_dut_adapted_sc_include_pkg.h"

// Parameter definitions for Vsc_dut_adapted_sc_include_pkg
constexpr SData/*15:0*/ Vsc_dut_adapted_sc_include_pkg::V_CRIT_LOW_ADC;
constexpr SData/*15:0*/ Vsc_dut_adapted_sc_include_pkg::V_UNSTABLE_MIN_ADC;
constexpr SData/*15:0*/ Vsc_dut_adapted_sc_include_pkg::V_UNSTABLE_MAX_ADC;
constexpr SData/*15:0*/ Vsc_dut_adapted_sc_include_pkg::V_CRIT_HIGH_ADC;


void Vsc_dut_adapted_sc_include_pkg___ctor_var_reset(Vsc_dut_adapted_sc_include_pkg* vlSelf);

Vsc_dut_adapted_sc_include_pkg::Vsc_dut_adapted_sc_include_pkg(Vsc_dut_adapted__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsc_dut_adapted_sc_include_pkg___ctor_var_reset(this);
}

void Vsc_dut_adapted_sc_include_pkg::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsc_dut_adapted_sc_include_pkg::~Vsc_dut_adapted_sc_include_pkg() {
}
