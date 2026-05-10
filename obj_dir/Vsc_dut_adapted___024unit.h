// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsc_dut_adapted.h for the primary calling header

#ifndef VERILATED_VSC_DUT_ADAPTED___024UNIT_H_
#define VERILATED_VSC_DUT_ADAPTED___024UNIT_H_  // guard

#include "verilated.h"


class Vsc_dut_adapted__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsc_dut_adapted___024unit final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    static VlUnpacked<std::string, 4> __Venumtab_enum_name0;
    static VlUnpacked<std::string, 8> __Venumtab_enum_name1;

    // INTERNAL VARIABLES
    Vsc_dut_adapted__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsc_dut_adapted___024unit(Vsc_dut_adapted__Syms* symsp, const char* v__name);
    ~Vsc_dut_adapted___024unit();
    VL_UNCOPYABLE(Vsc_dut_adapted___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
