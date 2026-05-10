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
        bufp->chgSData(oldp+0,(vlSelf->sc_dut__DOT__u_grid__DOT__debug_sum),16);
        bufp->chgSData(oldp+1,(vlSelf->sc_dut__DOT__u_grid__DOT__debug_adc),16);
        bufp->chgSData(oldp+2,(vlSelf->sc_dut__DOT__u_grid__DOT__debug_h0),16);
        bufp->chgSData(oldp+3,(vlSelf->sc_dut__DOT__u_grid__DOT__debug_h1),16);
        bufp->chgSData(oldp+4,(vlSelf->sc_dut__DOT__u_grid__DOT__debug_h2),16);
        bufp->chgSData(oldp+5,(vlSelf->sc_dut__DOT__u_grid__DOT__debug_h3),16);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+6,(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q),2);
        bufp->chgBit(oldp+7,(vlSelf->sc_dut__DOT__u_fsm__DOT__battery_connected_q));
        bufp->chgBit(oldp+8,(vlSelf->sc_dut__DOT__u_fsm__DOT__fault_flag_q));
        bufp->chgBit(oldp+9,(vlSelf->sc_dut__DOT__u_fsm__DOT__data_valid_q));
        bufp->chgCData(oldp+10,(vlSelf->sc_dut__DOT__u_fsm__DOT__check_wait_count),2);
        bufp->chgSData(oldp+11,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[0]),16);
        bufp->chgSData(oldp+12,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[1]),16);
        bufp->chgSData(oldp+13,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[2]),16);
        bufp->chgSData(oldp+14,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[3]),16);
        bufp->chgIData(oldp+15,(vlSelf->sc_dut__DOT__u_grid__DOT__sum_voltage),32);
        bufp->chgSData(oldp+16,(vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt),16);
        bufp->chgCData(oldp+17,(vlSelf->sc_dut__DOT__u_grid__DOT__sample_count),3);
        bufp->chgBit(oldp+18,(vlSelf->sc_dut__DOT__u_grid__DOT__data_valid));
        bufp->chgBit(oldp+19,(vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q));
        bufp->chgIData(oldp+20,(vlSelf->sc_dut__DOT__u_grid__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+21,(vlSelf->sc_dut__DOT__u_grid__DOT__unnamedblk2__DOT__i),32);
        bufp->chgCData(oldp+22,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state),3);
        bufp->chgBit(oldp+23,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag));
        bufp->chgCData(oldp+24,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code),2);
        bufp->chgBit(oldp+25,(((1U & (~ ((IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state) 
                                         >> 2U))) && 
                               ((1U & ((IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state) 
                                       >> 1U)) && (1U 
                                                   & (~ (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state)))))));
        bufp->chgCData(oldp+26,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state),2);
    }
    bufp->chgBit(oldp+27,(vlSelf->clk));
    bufp->chgBit(oldp+28,(vlSelf->reset_n));
    bufp->chgBit(oldp+29,(vlSelf->battery_connected));
    bufp->chgBit(oldp+30,(vlSelf->battery_full));
    bufp->chgBit(oldp+31,(vlSelf->ml_predict_instability));
    bufp->chgSData(oldp+32,(vlSelf->grid_voltage_adc),16);
    bufp->chgBit(oldp+33,(vlSelf->charge_enable));
    bufp->chgBit(oldp+34,(vlSelf->fault_flag));
    bufp->chgCData(oldp+35,(vlSelf->current_state),3);
    bufp->chgCData(oldp+36,(vlSelf->fault_code),2);
    bufp->chgCData(oldp+37,(vlSelf->sc_dut__DOT__u_fsm__DOT__next_state),3);
    bufp->chgCData(oldp+38,(((IData)(vlSelf->sc_dut__DOT__u_grid__DOT__data_valid)
                              ? ((((0x4650U > (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt)) 
                                   | (0xea60U < (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt))) 
                                  | (IData)(vlSelf->ml_predict_instability))
                                  ? 2U : (((0x4e20U 
                                            > (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt)) 
                                           | (0xc350U 
                                              < (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt)))
                                           ? 1U : 0U))
                              : 0U)),2);
    bufp->chgCData(oldp+39,(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum),2);
    bufp->chgBit(oldp+40,(vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb));
    bufp->chgCData(oldp+41,(vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb),2);
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
