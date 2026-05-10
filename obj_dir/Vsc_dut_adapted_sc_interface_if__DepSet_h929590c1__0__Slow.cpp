// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut_adapted.h for the primary calling header

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted_sc_interface_if.h"

VL_ATTR_COLD void Vsc_dut_adapted_sc_interface_if___ctor_var_reset(Vsc_dut_adapted_sc_interface_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vsc_dut_adapted_sc_interface_if___ctor_var_reset\n"); );
    // Body
    vlSelf->current_state = VL_RAND_RESET_I(3);
    vlSelf->fault_flag = VL_RAND_RESET_I(1);
    vlSelf->fault_code = VL_RAND_RESET_I(2);
    vlSelf->charge_enable = VL_RAND_RESET_I(1);
    vlSelf->battery_connected = VL_RAND_RESET_I(1);
    vlSelf->battery_full = VL_RAND_RESET_I(1);
    vlSelf->ml_predict_instability = VL_RAND_RESET_I(1);
    vlSelf->grid_voltage_adc = VL_RAND_RESET_I(16);
    vlSelf->data_valid = VL_RAND_RESET_I(1);
    vlSelf->grid_state = VL_RAND_RESET_I(2);
}
