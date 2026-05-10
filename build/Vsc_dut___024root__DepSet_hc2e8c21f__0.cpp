// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut.h for the primary calling header

#include "Vsc_dut__pch.h"
#include "Vsc_dut___024root.h"

void Vsc_dut___024root___ico_sequent__TOP__0(Vsc_dut___024root* vlSelf);

void Vsc_dut___024root___eval_ico(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vsc_dut___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vsc_dut___024root___eval_triggers__ico(Vsc_dut___024root* vlSelf);

bool Vsc_dut___024root___eval_phase__ico(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsc_dut___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vsc_dut___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsc_dut___024root___eval_act(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsc_dut___024root___nba_sequent__TOP__0(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY(vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q)) {
        VL_WRITEF("DEBUG: battery_connected_q = 1\n");
    }
    if (VL_UNLIKELY(((IData)(vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q) 
                     & (2U < (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__sample_count))))) {
        VL_WRITEF("=== FILTER DEBUG ===\nADC_IN=%0#\nHIST[0]=%0#, HIST[1]=%0#, HIST[2]=%0#, HIST[3]=%0#\nSOMA (ADC+H0+H1+H2)=%0#\n",
                  16,vlSelf->sc_dut__DOT__u_grid__DOT__debug_adc,
                  16,(IData)(vlSelf->sc_dut__DOT__u_grid__DOT__debug_h0),
                  16,vlSelf->sc_dut__DOT__u_grid__DOT__debug_h1,
                  16,(IData)(vlSelf->sc_dut__DOT__u_grid__DOT__debug_h2),
                  16,vlSelf->sc_dut__DOT__u_grid__DOT__debug_h3,
                  16,(IData)(vlSelf->sc_dut__DOT__u_grid__DOT__debug_sum));
        vlSelf->sc_dut__DOT__u_grid__DOT__debug_adc 
            = vlSelf->grid_voltage_adc;
        VL_WRITEF("FILTER (soma>>2)=%0#\n",16,(0xffffU 
                                               & VL_SHIFTR_III(16,16,32, (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__debug_sum), 2U)));
        vlSelf->sc_dut__DOT__u_grid__DOT__debug_h0 
            = vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
            [0U];
        vlSelf->sc_dut__DOT__u_grid__DOT__debug_h1 
            = vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
            [1U];
        vlSelf->sc_dut__DOT__u_grid__DOT__debug_h2 
            = vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
            [2U];
        vlSelf->sc_dut__DOT__u_grid__DOT__debug_h3 
            = vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
            [3U];
        VL_WRITEF("filter_volt atual=%0#\ndata_valid=%0#, battery_connected_q=%0#\n",
                  16,vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt,
                  1,(IData)(vlSelf->sc_dut__DOT__u_grid__DOT__data_valid),
                  1,vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q);
        vlSelf->sc_dut__DOT__u_grid__DOT__debug_sum 
            = (0xffffU & ((((IData)(vlSelf->grid_voltage_adc) 
                            + vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                            [0U]) + vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                           [1U]) + vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                          [2U]));
        VL_WRITEF("V_CRIT_LOW_ADC=18000, V_UNSTABLE_MIN_ADC=20000\n==================\n");
    }
}

void Vsc_dut___024root___nba_sequent__TOP__1(Vsc_dut___024root* vlSelf);

void Vsc_dut___024root___eval_nba(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsc_dut___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsc_dut___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vsc_dut___024root___eval_triggers__act(Vsc_dut___024root* vlSelf);

bool Vsc_dut___024root___eval_phase__act(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsc_dut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsc_dut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsc_dut___024root___eval_phase__nba(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsc_dut___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut___024root___dump_triggers__ico(Vsc_dut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut___024root___dump_triggers__nba(Vsc_dut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut___024root___dump_triggers__act(Vsc_dut___024root* vlSelf);
#endif  // VL_DEBUG

void Vsc_dut___024root___eval(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsc_dut___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("tb_wrapper/sc_dut.sv", 4, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsc_dut___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsc_dut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_wrapper/sc_dut.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsc_dut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_wrapper/sc_dut.sv", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsc_dut___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsc_dut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsc_dut___024root___eval_debug_assertions(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((vlSelf->battery_connected & 0xfeU))) {
        Verilated::overWidthError("battery_connected");}
    if (VL_UNLIKELY((vlSelf->battery_full & 0xfeU))) {
        Verilated::overWidthError("battery_full");}
    if (VL_UNLIKELY((vlSelf->ml_predict_instability 
                     & 0xfeU))) {
        Verilated::overWidthError("ml_predict_instability");}
}
#endif  // VL_DEBUG
