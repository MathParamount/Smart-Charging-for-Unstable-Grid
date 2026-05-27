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

VL_ATTR_COLD void Vsc_dut___024root___stl_sequent__TOP__0(Vsc_dut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut___024root___stl_sequent__TOP__0\n"); );
    // Init
    std::string __Vtemp_1;
    std::string __Vtemp_2;
    std::string __Vtemp_3;
    std::string __Vtemp_4;
    // Body
    vlSelf->charge_enable = ((1U & (~ ((IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state) 
                                       >> 2U))) && 
                             ((1U & ((IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state) 
                                     >> 1U)) && (1U 
                                                 & (~ (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state)))));
    vlSelf->fault_flag = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_flag;
    vlSelf->fault_code = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.fault_code;
    vlSelf->current_state = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state;
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
    vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state;
    if ((4U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
        } else if (vlSelf->ml_predict_instability) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((1U & ((~ (IData)(vlSelf->reset_n)) 
                          | (~ (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__battery_connected_q))))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q)) 
                     & (~ (IData)(vlSelf->battery_full))) 
                    & (~ (IData)(vlSelf->ml_predict_instability)))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 1U;
        }
    } else if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            if ((1U & ((IData)(vlSelf->battery_full) 
                       | (~ (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__battery_connected_q))))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
            } else if (((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q)) 
                        & (~ (IData)(vlSelf->ml_predict_instability)))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 2U;
            } else if (((IData)(vlSelf->ml_predict_instability) 
                        | (2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q)))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 3U;
            }
        } else if (vlSelf->ml_predict_instability) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 3U;
        } else if ((1U & (((IData)(vlSelf->battery_full) 
                           | (~ (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__battery_connected_q))) 
                          | (~ (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__data_valid_q))))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 2U;
        }
    } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
        if (vlSelf->sc_dut__DOT__u_fsm__DOT__data_valid_q) {
            if ((3U > (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__check_wait_count))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 1U;
            } else if ((2U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 3U;
            } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 2U;
            }
        } else {
            vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 1U;
        }
    } else if ((1U & ((~ (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__battery_connected_q)) 
                      | (IData)(vlSelf->battery_full)))) {
        vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 0U;
    } else if ((1U & ((~ (IData)(vlSelf->battery_full)) 
                      & (~ (IData)(vlSelf->sc_dut__DOT__u_fsm__DOT__fault_flag_q))))) {
        vlSelf->sc_dut__DOT__u_fsm__DOT__next_state = 1U;
    }
    vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 0U;
    vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum 
        = vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state;
    if (((IData)(vlSelf->reset_n) & (0U != (IData)(vlSelf->grid_voltage_adc)))) {
        if ((4U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSelf->ml_predict_instability;
            } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSelf->ml_predict_instability;
            } else {
                if (VL_UNLIKELY((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum)))) {
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 1U;
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 3U;
                    __Vtemp_1 = Vsc_dut___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state];
                    VL_WRITEF("SAFETY: FAULT ativado! grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_1),2,(IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state));
                } else if (VL_UNLIKELY((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum)))) {
                    __Vtemp_2 = Vsc_dut___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state];
                    VL_WRITEF("SAFETY: Sem fault, grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_2),2,(IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state));
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 2U;
                } else if (VL_UNLIKELY((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum)))) {
                    __Vtemp_3 = Vsc_dut___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state];
                    VL_WRITEF("SAFETY: Sem fault, grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_3),2,(IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state));
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 1U;
                } else {
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb 
                        = vlSelf->ml_predict_instability;
                }
                if ((1U & (~ (IData)(vlSelf->reset_n)))) {
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                }
            }
        } else if ((2U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
                if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 1U;
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 3U;
                } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 2U;
                } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 1U;
                } else {
                    vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb 
                        = vlSelf->ml_predict_instability;
                }
            } else if ((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 1U;
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 1U;
            } else {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSelf->ml_predict_instability;
            }
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.current_state))) {
            if (VL_UNLIKELY((2U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum)))) {
                __Vtemp_4 = Vsc_dut___024unit::__Venumtab_enum_name0
                    [vlSymsp->TOP__sc_dut__DOT__sc_interf_bus.grid_state];
                VL_WRITEF("SAFETY: FAULT ativado! grid_state=%@\n",
                          -1,&(__Vtemp_4));
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 1U;
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 1U;
            } else {
                vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
            }
        } else {
            vlSelf->sc_dut__DOT__u_safety__DOT__fault_flag_comb = 0U;
            vlSelf->sc_dut__DOT__u_safety__DOT__fault_code_comb = 0U;
        }
    }
}
