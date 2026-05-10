// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut.h for the primary calling header

#include "Vsc_dut__pch.h"
#include "Vsc_dut__Syms.h"
#include "Vsc_dut___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut___024root___dump_triggers__ico(Vsc_dut___024root* vlSelf);
#endif  // VL_DEBUG

void Vsc_dut___024root___eval_triggers__ico(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsc_dut___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsc_dut___024root___ico_sequent__TOP__0(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 0U;
    vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft = vlSelf->grid_state;
    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state;
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
    vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum 
        = vlSelf->grid_state;
    if ((4U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                = vlSelf->ml_predict_instability;
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
            vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum = 0U;
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                = vlSelf->ml_predict_instability;
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
            vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum = 0U;
        } else {
            if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 1U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 3U;
            } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 1U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
            }
            if ((1U & (~ (IData)(vlSelf->reset_n)))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
            }
            if ((1U & (~ (IData)(vlSelf->ml_predict_instability)))) {
                if ((1U & ((~ (IData)(vlSelf->reset_n)) 
                           | (~ (IData)(vlSelf->battery_connected))))) {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
                } else if (((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                            & (~ (IData)(vlSelf->battery_full)))) {
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 2U;
                }
            }
        }
    } else if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            if (((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft)) 
                 | (0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft)))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
            }
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 1U;
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state 
                = ((1U & ((IData)(vlSelf->battery_full) 
                          | (~ (IData)(vlSelf->battery_connected))))
                    ? 0U : (((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                             & (~ (IData)(vlSelf->ml_predict_instability)))
                             ? 2U : (((IData)(vlSelf->ml_predict_instability) 
                                      | (2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)))
                                      ? 4U : 3U)));
        } else {
            if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 1U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 1U;
            } else {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                    = vlSelf->ml_predict_instability;
            }
            if ((2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U & (~ (IData)(vlSelf->ml_predict_instability)))) {
                if ((1U & ((IData)(vlSelf->battery_full) 
                           | (~ (IData)(vlSelf->battery_connected))))) {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
                } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum))) {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 1U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 3U;
                } else {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 1U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 1U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 2U;
                }
            }
        }
    } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 1U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 3U;
        } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
        } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 1U;
        } else {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                = vlSelf->ml_predict_instability;
        }
        vlSelf->sc_dut__DOT__u_fsm__DOT__next_state 
            = ((IData)(vlSelf->battery_connected) ? 
               (((2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                 | (IData)(vlSelf->ml_predict_instability))
                 ? 4U : (((1U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                          & (~ (IData)(vlSelf->ml_predict_instability)))
                          ? 3U : 2U)) : 0U);
    } else {
        vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
        vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 0U;
        vlSelf->sc_dut__DOT__u_fsm__DOT__next_state 
            = (((IData)(vlSelf->battery_connected) 
                & (~ (IData)(vlSelf->battery_full)))
                ? 1U : 0U);
    }
    vlSelf->fault_flag = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag;
    vlSelf->fault_code = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code;
    vlSelf->charge_enable = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable;
    vlSelf->relay_active = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut___024root___dump_triggers__act(Vsc_dut___024root* vlSelf);
#endif  // VL_DEBUG

void Vsc_dut___024root___eval_triggers__act(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->reset_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__reset_n__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset_n__0 = vlSelf->reset_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsc_dut___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsc_dut___024root___nba_sequent__TOP__0(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state 
        = ((IData)(vlSelf->reset_n) ? (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__next_state)
            : 0U);
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 0U;
    vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft = vlSelf->grid_state;
    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state;
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
    vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum 
        = vlSelf->grid_state;
    if ((4U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                = vlSelf->ml_predict_instability;
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
            vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum = 0U;
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                = vlSelf->ml_predict_instability;
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
            vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum = 0U;
        } else {
            if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 1U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 3U;
            } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 1U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
            }
            if ((1U & (~ (IData)(vlSelf->reset_n)))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
            }
            if ((1U & (~ (IData)(vlSelf->ml_predict_instability)))) {
                if ((1U & ((~ (IData)(vlSelf->reset_n)) 
                           | (~ (IData)(vlSelf->battery_connected))))) {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
                } else if (((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                            & (~ (IData)(vlSelf->battery_full)))) {
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 2U;
                }
            }
        }
    } else if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            if (((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft)) 
                 | (0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft)))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
            }
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 1U;
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state 
                = ((1U & ((IData)(vlSelf->battery_full) 
                          | (~ (IData)(vlSelf->battery_connected))))
                    ? 0U : (((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                             & (~ (IData)(vlSelf->ml_predict_instability)))
                             ? 2U : (((IData)(vlSelf->ml_predict_instability) 
                                      | (2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)))
                                      ? 4U : 3U)));
        } else {
            if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 1U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 1U;
            } else {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                    = vlSelf->ml_predict_instability;
            }
            if ((2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum))) {
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U & (~ (IData)(vlSelf->ml_predict_instability)))) {
                if ((1U & ((IData)(vlSelf->battery_full) 
                           | (~ (IData)(vlSelf->battery_connected))))) {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 0U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
                } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum))) {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 0U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 1U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 3U;
                } else {
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation = 1U;
                    vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable = 1U;
                    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 2U;
                }
            }
        }
    } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 1U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 3U;
        } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 2U;
        } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grd_saft))) {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 1U;
        } else {
            vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag 
                = vlSelf->ml_predict_instability;
        }
        vlSelf->sc_dut__DOT__u_fsm__DOT__next_state 
            = ((IData)(vlSelf->battery_connected) ? 
               (((2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                 | (IData)(vlSelf->ml_predict_instability))
                 ? 4U : (((1U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_enum)) 
                          & (~ (IData)(vlSelf->ml_predict_instability)))
                          ? 3U : 2U)) : 0U);
    } else {
        vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag = 0U;
        vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code = 0U;
        vlSelf->sc_dut__DOT__u_fsm__DOT__next_state 
            = (((IData)(vlSelf->battery_connected) 
                & (~ (IData)(vlSelf->battery_full)))
                ? 1U : 0U);
    }
    vlSelf->fault_flag = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag;
    vlSelf->fault_code = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code;
    vlSelf->charge_enable = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.charge_enable;
    vlSelf->relay_active = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.relay_activation;
}
