// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsc_dut__Syms.h"


void Vsc_dut___024root__trace_chg_0_sub_0(Vsc_dut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsc_dut___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_chg_0\n"); );
    // Init
    Vsc_dut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsc_dut___024root*>(voidSelf);
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsc_dut___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsc_dut___024root__trace_chg_0_sub_0(Vsc_dut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+0,(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum),2);
        bufp->chgCData(oldp+1,(vlSelf->sc_dut__DOT__u_fsm__DOT__next_state),3);
        bufp->chgCData(oldp+2,(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft),2);
        bufp->chgBit(oldp+3,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag));
        bufp->chgCData(oldp+4,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code),2);
        bufp->chgBit(oldp+5,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable));
        bufp->chgBit(oldp+6,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation));
    }
    bufp->chgBit(oldp+7,(vlSelf->clk));
    bufp->chgBit(oldp+8,(vlSelf->reset_n));
    bufp->chgBit(oldp+9,(vlSelf->battery_connected));
    bufp->chgBit(oldp+10,(vlSelf->battery_full));
    bufp->chgCData(oldp+11,(vlSelf->grid_state),2);
    bufp->chgBit(oldp+12,(vlSelf->ml_predict_instability));
    bufp->chgBit(oldp+13,(vlSelf->charge_enable));
    bufp->chgBit(oldp+14,(vlSelf->relay_active));
    bufp->chgBit(oldp+15,(vlSelf->fault_flag));
    bufp->chgCData(oldp+16,(vlSelf->fault_code),2);
    bufp->chgCData(oldp+17,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state),3);
}

void Vsc_dut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_cleanup\n"); );
    // Init
    Vsc_dut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsc_dut___024root*>(voidSelf);
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
