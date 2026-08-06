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
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q),2);
        bufp->chgBit(oldp+1,(vlSelf->sc_dut__DOT__u_fsm__DOT__battery_connected_q));
        bufp->chgBit(oldp+2,(vlSelf->sc_dut__DOT__u_fsm__DOT__fault_flag_q));
        bufp->chgBit(oldp+3,(vlSelf->sc_dut__DOT__u_fsm__DOT__data_valid_q));
        bufp->chgCData(oldp+4,(vlSelf->sc_dut__DOT__u_fsm__DOT__check_wait_count),2);
        bufp->chgIData(oldp+5,(vlSelf->sc_dut__DOT__u_grid__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+6,(vlSelf->sc_dut__DOT__u_grid__DOT__unnamedblk2__DOT__i),32);
        bufp->chgCData(oldp+7,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state),3);
        bufp->chgBit(oldp+8,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag));
        bufp->chgCData(oldp+9,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code),2);
        bufp->chgBit(oldp+10,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.power_discharge));
        bufp->chgCData(oldp+12,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+13,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[0]),32);
        bufp->chgIData(oldp+14,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[1]),32);
        bufp->chgIData(oldp+15,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[2]),32);
        bufp->chgIData(oldp+16,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[3]),32);
        bufp->chgIData(oldp+17,(vlSelf->sc_dut__DOT__u_grid__DOT__sum_voltage),32);
        bufp->chgIData(oldp+18,(vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt),32);
        bufp->chgCData(oldp+19,(vlSelf->sc_dut__DOT__u_grid__DOT__sample_count),3);
        bufp->chgBit(oldp+20,(vlSelf->sc_dut__DOT__u_grid__DOT__data_valid));
        bufp->chgBit(oldp+21,(vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q));
    }
    bufp->chgBit(oldp+22,(vlSelf->clk));
    bufp->chgBit(oldp+23,(vlSelf->reset_n));
    bufp->chgBit(oldp+24,(vlSelf->battery_connected));
    bufp->chgBit(oldp+25,(vlSelf->battery_full));
    bufp->chgBit(oldp+26,(vlSelf->ml_predict_instability));
    bufp->chgSData(oldp+27,(vlSelf->grid_voltage_adc),16);
    bufp->chgBit(oldp+28,(vlSelf->cmd));
    bufp->chgBit(oldp+29,(vlSelf->charge_enable));
    bufp->chgBit(oldp+30,(vlSelf->power_discharge));
    bufp->chgBit(oldp+31,(vlSelf->fault_flag));
    bufp->chgCData(oldp+32,(vlSelf->current_state),3);
    bufp->chgCData(oldp+33,(vlSelf->fault_code),2);
    bufp->chgCData(oldp+34,(vlSelf->sc_dut__DOT__u_fsm__DOT__next_state),3);
    bufp->chgCData(oldp+35,(vlSelf->sc_dut__DOT__u_grid__DOT__grid_state_enum),2);
    bufp->chgCData(oldp+36,(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum),2);
    bufp->chgBit(oldp+37,(vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb));
    bufp->chgCData(oldp+38,(vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb),2);
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
