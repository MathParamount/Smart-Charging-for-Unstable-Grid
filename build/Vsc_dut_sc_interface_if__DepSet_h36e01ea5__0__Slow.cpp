// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut.h for the primary calling header

#include "Vsc_dut__pch.h"
#include "Vsc_dut_sc_interface_if.h"

VL_ATTR_COLD void Vsc_dut_sc_interface_if___ctor_var_reset(Vsc_dut_sc_interface_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vsc_dut_sc_interface_if___ctor_var_reset\n"); );
    // Body
    vlSelf->current_state = VL_RAND_RESET_I(3);
    vlSelf->fault_flag = VL_RAND_RESET_I(1);
    vlSelf->fault_code = VL_RAND_RESET_I(2);
    vlSelf->grid_state = VL_RAND_RESET_I(2);
}
