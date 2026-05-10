// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut.h for the primary calling header

#include "Vsc_dut__pch.h"
#include "Vsc_dut___024unit.h"

VL_ATTR_COLD void Vsc_dut___024unit___ctor_var_reset(Vsc_dut___024unit* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vsc_dut___024unit___ctor_var_reset\n"); );
    // Body
    for (int __Vi = 0; __Vi < 4; ++__Vi) {
        vlSelf->__Venumtab_enum_name0[__Vi] = std::string{""};
    }
    vlSelf->__Venumtab_enum_name0[0] = std::string{"GRID_NORMAL"};
    vlSelf->__Venumtab_enum_name0[1] = std::string{"GRID_UNSTABLE"};
    vlSelf->__Venumtab_enum_name0[2] = std::string{"GRID_CRITICAL"};
}
