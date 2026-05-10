// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut_adapted.h for the primary calling header

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted__Syms.h"
#include "Vsc_dut_adapted___024root.h"

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_initial__TOP(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_initial__TOP\n"); );
    // Body
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_connected = 1U;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.ml_predict_instability = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__stl(Vsc_dut_adapted___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_triggers__stl(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsc_dut_adapted___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
