// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut_adapted.h for the primary calling header

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted___024unit.h"

VL_ATTR_COLD void Vsc_dut_adapted___024unit___ctor_var_reset(Vsc_dut_adapted___024unit* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vsc_dut_adapted___024unit___ctor_var_reset\n"); );
    // Body
    for (int __Vi = 0; __Vi < 4; ++__Vi) {
        vlSelf->__Venumtab_enum_name0[__Vi] = std::string{""};
    }
    vlSelf->__Venumtab_enum_name0[0] = std::string{"GRID_NORMAL"};
    vlSelf->__Venumtab_enum_name0[1] = std::string{"GRID_UNSTABLE"};
    vlSelf->__Venumtab_enum_name0[2] = std::string{"GRID_CRITICAL"};
    for (int __Vi = 0; __Vi < 8; ++__Vi) {
        vlSelf->__Venumtab_enum_name1[__Vi] = std::string{""};
    }
    vlSelf->__Venumtab_enum_name1[0] = std::string{"IDLE"};
    vlSelf->__Venumtab_enum_name1[1] = std::string{"CHECK_GRID"};
    vlSelf->__Venumtab_enum_name1[2] = std::string{"CHARGING"};
    vlSelf->__Venumtab_enum_name1[3] = std::string{"WAIT"};
    vlSelf->__Venumtab_enum_name1[4] = std::string{"FAULT"};
}
