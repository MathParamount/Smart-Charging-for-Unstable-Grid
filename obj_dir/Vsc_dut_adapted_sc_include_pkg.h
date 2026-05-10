// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsc_dut_adapted.h for the primary calling header

#ifndef VERILATED_VSC_DUT_ADAPTED_SC_INCLUDE_PKG_H_
#define VERILATED_VSC_DUT_ADAPTED_SC_INCLUDE_PKG_H_  // guard

#include "verilated.h"


class Vsc_dut_adapted__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsc_dut_adapted_sc_include_pkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vsc_dut_adapted__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr SData/*15:0*/ V_CRIT_LOW_ADC = 0x4650U;
    static constexpr SData/*15:0*/ V_UNSTABLE_MIN_ADC = 0x4e20U;
    static constexpr SData/*15:0*/ V_UNSTABLE_MAX_ADC = 0xc350U;
    static constexpr SData/*15:0*/ V_CRIT_HIGH_ADC = 0xea60U;

    // CONSTRUCTORS
    Vsc_dut_adapted_sc_include_pkg(Vsc_dut_adapted__Syms* symsp, const char* v__name);
    ~Vsc_dut_adapted_sc_include_pkg();
    VL_UNCOPYABLE(Vsc_dut_adapted_sc_include_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
