// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut.h for the primary calling header

#include "Vsc_dut__pch.h"
#include "Vsc_dut__Syms.h"
#include "Vsc_dut___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut___024root___dump_triggers__stl(Vsc_dut___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsc_dut___024root___eval_triggers__stl(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsc_dut___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
