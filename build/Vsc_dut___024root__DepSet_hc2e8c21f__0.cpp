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

VL_INLINE_OPT void Vsc_dut___024root___nba_sequent__TOP__1(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q) 
                      & (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__data_valid)) 
                     & (2U <= (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__sample_count))))) {
        VL_WRITEF("=== FILTER DEBUG ===\nADC_IN=%0#\nHIST[0]=%0#, HIST[1]=%0#, HIST[2]=%0#, HIST[3]=%0#\nSOMA (ADC+H0+H1+H2)=%0#\nFILTER (soma>>2)=%0#\nfilter_volt atual=%0#\nsample_count=%0#\n==================\n",
                  16,vlSelf->grid_voltage_adc,32,vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                  [0U],32,vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                  [1U],32,vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                  [2U],32,vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                  [3U],32,vlSelf->sc_dut__DOT__u_grid__DOT__sum_voltage,
                  32,VL_SHIFTR_III(32,32,32, vlSelf->sc_dut__DOT__u_grid__DOT__sum_voltage, 2U),
                  32,vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt,
                  3,(IData)(vlSelf->sc_dut__DOT__u_grid__DOT__sample_count));
    }
}

VL_INLINE_OPT void Vsc_dut___024root___nba_sequent__TOP__2(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v0;
    __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v0 = 0;
    IData/*31:0*/ __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v1;
    __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v1 = 0;
    IData/*31:0*/ __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v2;
    __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v2 = 0;
    IData/*31:0*/ __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v3;
    __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v3 = 0;
    // Body
    vlSelf->sc_dut__DOT__u_grid__DOT__data_valid = vlSelf->__Vdly__sc_dut__DOT__u_grid__DOT__data_valid;
    if (vlSelf->reset_n) {
        if (vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q) {
            if ((2U <= (IData)(vlSelf->sc_dut__DOT__u_grid__DOT__sample_count))) {
                vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt 
                    = VL_SHIFTR_III(32,32,32, vlSelf->sc_dut__DOT__u_grid__DOT__sum_voltage, 2U);
                vlSelf->sc_dut__DOT__u_grid__DOT__sum_voltage 
                    = ((((IData)(vlSelf->grid_voltage_adc) 
                         + vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                         [0U]) + vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                        [1U]) + vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                       [2U]);
            }
            __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v0 
                = vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                [2U];
            vlSelf->__Vdlyvset__sc_dut__DOT__u_grid__DOT__voltage_history__v0 = 1U;
            __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v1 
                = vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                [1U];
            __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v2 
                = vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history
                [0U];
            __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v3 
                = vlSelf->grid_voltage_adc;
        }
    } else {
        vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt = 0U;
        vlSelf->__Vdlyvset__sc_dut__DOT__u_grid__DOT__voltage_history__v4 = 1U;
    }
    vlSelf->sc_dut__DOT__u_grid__DOT__grid_state_enum 
        = ((IData)(vlSelf->sc_dut__DOT__u_grid__DOT__data_valid)
            ? ((((0xa410U > vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt) 
                 | (0x13880U < vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt)) 
                | (IData)(vlSelf->ml_predict_instability))
                ? 2U : (((0xd2f0U > vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt) 
                         | (0x124f8U < vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt))
                         ? 1U : (((0xd2f0U < vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt) 
                                  & (0x124f8U > vlSelf->sc_dut__DOT__u_grid__DOT__filter_volt))
                                  ? 0U : 2U))) : 0U);
    vlSelf->sc_dut__DOT__u_grid__DOT__sample_count 
        = vlSelf->__Vdly__sc_dut__DOT__u_grid__DOT__sample_count;
    if (vlSelf->__Vdlyvset__sc_dut__DOT__u_grid__DOT__voltage_history__v0) {
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[3U] 
            = __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v0;
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[2U] 
            = __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v1;
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[1U] 
            = __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v2;
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[0U] 
            = __Vdlyvval__sc_dut__DOT__u_grid__DOT__voltage_history__v3;
    }
    if (vlSelf->__Vdlyvset__sc_dut__DOT__u_grid__DOT__voltage_history__v4) {
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[0U] = 0U;
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[1U] = 0U;
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[2U] = 0U;
        vlSelf->sc_dut__DOT__u_grid__DOT__voltage_history[3U] = 0U;
    }
    vlSelf->sc_dut__DOT__u_grid__DOT__battery_connected_q 
        = ((IData)(vlSelf->reset_n) & (IData)(vlSelf->battery_connected));
}

void Vsc_dut___024root___nba_sequent__TOP__0(Vsc_dut___024root* vlSelf);

void Vsc_dut___024root___eval_nba(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsc_dut___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsc_dut___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsc_dut___024root___nba_sequent__TOP__2(vlSelf);
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
    if (VL_UNLIKELY((vlSelf->cmd & 0xfeU))) {
        Verilated::overWidthError("cmd");}
}
#endif  // VL_DEBUG
