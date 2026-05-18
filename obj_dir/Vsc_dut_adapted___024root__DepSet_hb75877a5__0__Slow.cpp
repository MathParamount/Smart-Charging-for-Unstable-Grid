// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut_adapted.h for the primary calling header

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted___024root.h"

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_static(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_initial__TOP(Vsc_dut_adapted___024root* vlSelf);

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_initial(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_initial\n"); );
    // Body
    Vsc_dut_adapted___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset_n__0 = vlSelf->reset_n;
}

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_final(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__stl(Vsc_dut_adapted___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsc_dut_adapted___024root___eval_phase__stl(Vsc_dut_adapted___024root* vlSelf);

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_settle(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsc_dut_adapted___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("dll_interface/sc_dut_adapted.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsc_dut_adapted___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__stl(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vsc_dut_adapted___024root___ico_sequent__TOP__0(Vsc_dut_adapted___024root* vlSelf);

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_stl(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsc_dut_adapted___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vsc_dut_adapted___024root___eval_triggers__stl(Vsc_dut_adapted___024root* vlSelf);

VL_ATTR_COLD bool Vsc_dut_adapted___024root___eval_phase__stl(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsc_dut_adapted___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vsc_dut_adapted___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__ico(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__act(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or negedge reset_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__nba(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or negedge reset_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsc_dut_adapted___024root___ctor_var_reset(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset_n = VL_RAND_RESET_I(1);
    vlSelf->battery_connected = VL_RAND_RESET_I(1);
    vlSelf->battery_full = VL_RAND_RESET_I(1);
    vlSelf->ml_predict_instability = VL_RAND_RESET_I(1);
    vlSelf->grid_voltage_adc = VL_RAND_RESET_I(16);
    vlSelf->charge_enable = VL_RAND_RESET_I(1);
    vlSelf->fault_flag = VL_RAND_RESET_I(1);
    vlSelf->current_state = VL_RAND_RESET_I(3);
    vlSelf->fault_code = VL_RAND_RESET_I(2);
    vlSelf->grid_state = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__reset_n = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__battery_connected = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__battery_full = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__ml_predict_instability = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__grid_voltage_adc = VL_RAND_RESET_I(16);
    vlSelf->sc_dut_adapted__DOT__charge_enable = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__fault_flag = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__current_state = VL_RAND_RESET_I(3);
    vlSelf->sc_dut_adapted__DOT__fault_code = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__grid_state = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__reset_n = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__battery_connected = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__battery_full = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__ml_predict_instability = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__grid_voltage_adc = VL_RAND_RESET_I(16);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__charge_enable = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_flag = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__current_state = VL_RAND_RESET_I(3);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_code = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__grid_state = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__reset_n = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sum_voltage = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count = VL_RAND_RESET_I(3);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_sum = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_adc = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h0 = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h1 = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h2 = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h3 = VL_RAND_RESET_I(32);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__reset_n = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__fault_flag_q = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__reset_n = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum = VL_RAND_RESET_I(2);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = VL_RAND_RESET_I(1);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset_n__0 = VL_RAND_RESET_I(1);
}
