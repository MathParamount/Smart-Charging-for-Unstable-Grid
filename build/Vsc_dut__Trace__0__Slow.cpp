// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsc_dut__Syms.h"


VL_ATTR_COLD void Vsc_dut___024root__trace_init_sub__TOP__sc_include_pkg__0(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsc_dut___024root__trace_init_sub__TOP__0(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("sc_include_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_include_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+27,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"battery_connected",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"battery_full",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"ml_predict_instability",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"grid_voltage_adc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+33,0,"charge_enable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"fault_flag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"current_state",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"fault_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("sc_dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+27,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"battery_connected",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"battery_full",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"ml_predict_instability",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"grid_voltage_adc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+33,0,"charge_enable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"fault_flag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"current_state",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"fault_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("sc_interf_bus", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_fsm", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+27,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("fsm_bus", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("grid_bus", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+1,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"grid_state_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+7,0,"battery_connected_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"fault_flag_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"data_valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"check_wait_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_grid", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+27,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("grid_bus", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("fsm_bus", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("voltage_history", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+15,0,"sum_voltage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"filter_volt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"grid_state_enum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+17,0,"sample_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+18,0,"data_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"battery_connected_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+20,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+21,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_safety", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+27,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("safety_bus", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("grid_bus", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+3,0,"grid_state_enum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+4,0,"fault_flag_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"fault_code_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsc_dut___024root__trace_init_sub__TOP__sc_include_pkg__0(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_init_sub__TOP__sc_include_pkg__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+37,0,"V_CRIT_LOW_ADC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"V_UNSTABLE_MIN_ADC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"V_UNSTABLE_MAX_ADC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"V_CRIT_HIGH_ADC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_init_sub__TOP__sc_dut__DOT__sc_interf_bus__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+22,0,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+23,0,"fault_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+24,0,"fault_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+25,0,"charge_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"battery_connected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"battery_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"ml_predict_instability",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"grid_voltage_adc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+18,0,"data_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"grid_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vsc_dut___024root__trace_init_top(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_init_top\n"); );
    // Body
    Vsc_dut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsc_dut___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsc_dut___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsc_dut___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsc_dut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsc_dut___024root__trace_register(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vsc_dut___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsc_dut___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsc_dut___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsc_dut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsc_dut___024root__trace_const_0_sub_0(Vsc_dut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsc_dut___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_const_0\n"); );
    // Init
    Vsc_dut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsc_dut___024root*>(voidSelf);
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsc_dut___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsc_dut___024root__trace_const_0_sub_0(Vsc_dut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+37,(0xa410U),32);
    bufp->fullIData(oldp+38,(0xd2f0U),32);
    bufp->fullIData(oldp+39,(0x124f8U),32);
    bufp->fullIData(oldp+40,(0x13880U),32);
}

VL_ATTR_COLD void Vsc_dut___024root__trace_full_0_sub_0(Vsc_dut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsc_dut___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_full_0\n"); );
    // Init
    Vsc_dut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsc_dut___024root*>(voidSelf);
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsc_dut___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsc_dut___024root__trace_full_0_sub_0(Vsc_dut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->sc_dut__DOT__u_fsm__DOT__next_state),3);
    bufp->fullCData(oldp+2,(vlSelf->sc_dut__DOT__u_grid__DOT__grid_state_enum),2);
    bufp->fullCData(oldp+3,(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum),2);
    bufp->fullBit(oldp+4,(vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb));
    bufp->fullCData(oldp+5,(vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb),2);
    bufp->fullCData(oldp+6,(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q),2);
    bufp->fullBit(oldp+7,(vlSelf->sc_dut__DOT__u_fsm__DOT__battery_connected_q));
    bufp->fullBit(oldp+8,(vlSelf->sc_dut__DOT__u_fsm__DOT__fault_flag_q));
    bufp->fullBit(oldp+9,(vlSelf->sc_dut__DOT__u_fsm__DOT__data_valid_q));
    bufp->fullCData(oldp+10,(vlSelf->sc_dut__DOT__u_fsm__DOT__check_wait_count),2);
    bufp->fullIData(oldp+11,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[0]),32);
    bufp->fullIData(oldp+12,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[1]),32);
    bufp->fullIData(oldp+13,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[2]),32);
    bufp->fullIData(oldp+14,(vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[3]),32);
    bufp->fullIData(oldp+15,(vlSelf->sc_dut__DOT__u_grid__DOT__sum_voltage),32);
    bufp->fullIData(oldp+16,(vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt),32);
    bufp->fullCData(oldp+17,(vlSelf->sc_dut__DOT__u_grid__DOT__sample_count),3);
    bufp->fullBit(oldp+18,(vlSelf->sc_dut__DOT__u_grid__DOT__data_valid));
    bufp->fullBit(oldp+19,(vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q));
    bufp->fullIData(oldp+20,(vlSelf->sc_dut__DOT__u_grid__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+21,(vlSelf->sc_dut__DOT__u_grid__DOT__unnamedblk2__DOT__i),32);
    bufp->fullCData(oldp+22,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state),3);
    bufp->fullBit(oldp+23,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag));
    bufp->fullCData(oldp+24,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code),2);
    bufp->fullBit(oldp+25,(((1U & (~ ((IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state) 
                                      >> 2U))) && (
                                                   (1U 
                                                    & ((IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state) 
                                                       >> 1U)) 
                                                   && (1U 
                                                       & (~ (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state)))))));
    bufp->fullCData(oldp+26,(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state),2);
    bufp->fullBit(oldp+27,(vlSelf->clk));
    bufp->fullBit(oldp+28,(vlSelf->reset_n));
    bufp->fullBit(oldp+29,(vlSelf->battery_connected));
    bufp->fullBit(oldp+30,(vlSelf->battery_full));
    bufp->fullBit(oldp+31,(vlSelf->ml_predict_instability));
    bufp->fullSData(oldp+32,(vlSelf->grid_voltage_adc),16);
    bufp->fullBit(oldp+33,(vlSelf->charge_enable));
    bufp->fullBit(oldp+34,(vlSelf->fault_flag));
    bufp->fullCData(oldp+35,(vlSelf->current_state),3);
    bufp->fullCData(oldp+36,(vlSelf->fault_code),2);
}
