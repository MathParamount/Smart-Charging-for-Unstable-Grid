// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut_adapted.h for the primary calling header

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted__Syms.h"
#include "Vsc_dut_adapted___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__ico(Vsc_dut_adapted___024root* vlSelf);
#endif  // VL_DEBUG

void Vsc_dut_adapted___024root___eval_triggers__ico(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsc_dut_adapted___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsc_dut_adapted___024root___ico_sequent__TOP__0(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___ico_sequent__TOP__0\n"); );
    // Init
    std::string __Vtemp_1;
    std::string __Vtemp_2;
    std::string __Vtemp_3;
    std::string __Vtemp_4;
    // Body
    vlSelf->sc_dut_adapted__DOT__battery_connected 
        = vlSelf->battery_connected;
    vlSelf->sc_dut_adapted__DOT__battery_full = vlSelf->battery_full;
    vlSelf->sc_dut_adapted__DOT__ml_predict_instability 
        = vlSelf->ml_predict_instability;
    vlSelf->sc_dut_adapted__DOT__grid_voltage_adc = vlSelf->grid_voltage_adc;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__battery_connected 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_connected;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__ml_predict_instability 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.ml_predict_instability;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_connected 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_connected;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.data_valid 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__grid_state 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_flag 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_flag;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_code 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_code;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__current_state 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state;
    vlSelf->sc_dut_adapted__DOT__clk = vlSelf->clk;
    vlSelf->sc_dut_adapted__DOT__reset_n = vlSelf->reset_n;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable = 0U;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable 
        = ((1U & (~ ((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state) 
                     >> 2U))) && ((1U & ((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state) 
                                         >> 1U)) && 
                                  (1U & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state)))));
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_full 
        = vlSelf->battery_full;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.grid_voltage_adc 
        = vlSelf->grid_voltage_adc;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.ml_predict_instability;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.grid_state 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__grid_state;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_flag 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_flag;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_code 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_code;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.current_state 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__current_state;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__clk = vlSelf->sc_dut_adapted__DOT__clk;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__reset_n 
        = vlSelf->sc_dut_adapted__DOT__reset_n;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__charge_enable 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__battery_full 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_full;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_full;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__grid_voltage_adc 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.grid_voltage_adc;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc 
        = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.grid_voltage_adc;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum 
        = ((IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid)
            ? ((((0x4650U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt)) 
                 | (0xea60U < (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt))) 
                | (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability))
                ? 2U : (((0x4e20U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt)) 
                         | (0xc350U < (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt)))
                         ? 1U : 0U)) : 0U);
    vlSelf->sc_dut_adapted__DOT__fault_flag = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_flag;
    vlSelf->sc_dut_adapted__DOT__fault_code = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_code;
    vlSelf->sc_dut_adapted__DOT__current_state = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.current_state;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__clk 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__clk;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__clk 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__clk;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__clk 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__clk;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__reset_n 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__reset_n;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__reset_n 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__reset_n;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__reset_n 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__reset_n;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.charge_enable 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__charge_enable;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state;
    if ((4U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
        if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if (vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((1U & ((~ (IData)(vlSelf->reset_n)) 
                          | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q))))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q)) 
                     & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full))) 
                    & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability)))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
        }
    } else if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
        if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if ((1U & ((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full) 
                       | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q))))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
            } else if (((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q)) 
                        & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability)))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 2U;
            } else if (((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability) 
                        | (2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q)))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 3U;
            }
        } else if (vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 3U;
        } else if ((1U & (((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full) 
                           | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q))) 
                          | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q))))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 2U;
        }
    } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
        if (vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q) {
            if ((3U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
            } else if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 3U;
            } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 2U;
            }
        } else {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
        }
    } else if ((1U & ((~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q)) 
                      | (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full)))) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
    } else if ((1U & ((~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full)) 
                      & (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__fault_flag_q))))) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
    }
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 0U;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 0U;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state;
    if (((IData)(vlSelf->reset_n) & (0U != (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc)))) {
        if ((4U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
            } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
            } else {
                if (VL_UNLIKELY((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
                    __Vtemp_1 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                    VL_WRITEF("SAFETY: FAULT ativado! grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_1),2,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state));
                } else if (VL_UNLIKELY((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                    __Vtemp_2 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                    VL_WRITEF("SAFETY: Sem fault, grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_2),2,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state));
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
                } else if (VL_UNLIKELY((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                    __Vtemp_3 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                    VL_WRITEF("SAFETY: Sem fault, grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_3),2,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state));
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
                } else {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
                }
                if ((1U & (~ (IData)(vlSelf->reset_n)))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                }
            }
        } else if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
                if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
                } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
                } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
                } else {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
                }
            } else if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
            } else {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
            }
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if (VL_UNLIKELY((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                __Vtemp_4 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                    [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                VL_WRITEF("SAFETY: FAULT ativado! grid_state=%@\n",
                          -1,&(__Vtemp_4));
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
            } else {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
            }
        } else {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 0U;
        }
    }
    vlSelf->sc_dut_adapted__DOT__grid_state = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum;
    vlSelf->fault_flag = vlSelf->sc_dut_adapted__DOT__fault_flag;
    vlSelf->fault_code = vlSelf->sc_dut_adapted__DOT__fault_code;
    vlSelf->current_state = vlSelf->sc_dut_adapted__DOT__current_state;
    vlSelf->sc_dut_adapted__DOT__charge_enable = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.charge_enable;
    vlSelf->grid_state = vlSelf->sc_dut_adapted__DOT__grid_state;
    vlSelf->charge_enable = vlSelf->sc_dut_adapted__DOT__charge_enable;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsc_dut_adapted___024root___dump_triggers__act(Vsc_dut_adapted___024root* vlSelf);
#endif  // VL_DEBUG

void Vsc_dut_adapted___024root___eval_triggers__act(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->reset_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__reset_n__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset_n__0 = vlSelf->reset_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsc_dut_adapted___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsc_dut_adapted___024root___nba_sequent__TOP__0(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___nba_sequent__TOP__0\n"); );
    // Init
    std::string __Vtemp_1;
    // Body
    VL_WRITEF("ADAPTER: battery_connected input = %0#\n",
              1,vlSelf->battery_connected);
    if (VL_UNLIKELY(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q)) {
        VL_WRITEF("DEBUG: battery_connected_q = 1\n");
    }
    __Vtemp_1 = Vsc_dut_adapted___024unit::__Venumtab_enum_name1
        [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state];
    VL_WRITEF("TOP: fault_flag=%1#, state=%@, charge=%1#\nTOP: reset_n=1, batt_conn=%0#, data_valid=%0#\n",
              1,vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_flag,
              -1,&(__Vtemp_1),1,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable),
              1,vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_connected,
              1,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.data_valid));
    if (VL_UNLIKELY(((IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q) 
                     & (2U < (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count))))) {
        VL_WRITEF("=== FILTER DEBUG ===\nADC_IN=%0#\nHIST[0]=%0#, HIST[1]=%0#, HIST[2]=%0#, HIST[3]=%0#\nSOMA (ADC+H0+H1+H2)=%0#\n",
                  16,vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_adc,
                  16,(IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h0),
                  16,vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h1,
                  16,(IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h2),
                  16,vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h3,
                  16,(IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_sum));
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_adc 
            = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc;
        VL_WRITEF("FILTER (soma>>2)=%0#\n",16,(0xffffU 
                                               & VL_SHIFTR_III(16,16,32, (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_sum), 2U)));
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h0 
            = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
            [0U];
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h1 
            = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
            [1U];
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h2 
            = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
            [2U];
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h3 
            = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
            [3U];
        VL_WRITEF("filter_volt atual=%0#\ndata_valid=%0#, battery_connected_q=%0#\n",
                  16,vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt,
                  1,(IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid),
                  1,vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q);
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_sum 
            = (0xffffU & ((((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc) 
                            + vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                            [0U]) + vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                           [1U]) + vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                          [2U]));
        VL_WRITEF("V_CRIT_LOW_ADC=18000, V_UNSTABLE_MIN_ADC=20000\n==================\n");
    }
}

VL_INLINE_OPT void Vsc_dut_adapted___024root___nba_sequent__TOP__1(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*2:0*/ __Vdly__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count;
    __Vdly__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count = 0;
    SData/*15:0*/ __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0;
    __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0;
    __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0 = 0;
    SData/*15:0*/ __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v1;
    __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v1 = 0;
    SData/*15:0*/ __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v2;
    __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v2 = 0;
    SData/*15:0*/ __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v3;
    __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v3 = 0;
    CData/*0:0*/ __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v4;
    __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v4 = 0;
    // Body
    __Vdly__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count;
    __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0 = 0U;
    __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v4 = 0U;
    if ((1U & (~ (IData)(vlSelf->reset_n)))) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk1__DOT__i = 1U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk1__DOT__i = 2U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk1__DOT__i = 3U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSelf->reset_n) {
        if (vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk2__DOT__i = 2U;
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk2__DOT__i = 1U;
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk2__DOT__i = 0U;
            if ((4U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count))) {
                __Vdly__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count)));
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid 
                    = (3U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count));
            } else {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid = 1U;
            }
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt 
                = (0xffffU & (vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sum_voltage 
                              >> 2U));
            __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0 
                = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                [2U];
            __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0 = 1U;
            __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v1 
                = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                [1U];
            __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v2 
                = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                [0U];
            __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v3 
                = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc;
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sum_voltage 
                = ((((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc) 
                     + vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                     [0U]) + vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                    [1U]) + vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history
                   [2U]);
        } else {
            __Vdly__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count = 0U;
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid = 0U;
        }
        vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_code 
            = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q 
            = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state;
        if (((1U == (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state)) 
             & (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q))) {
            if ((3U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count 
                    = (3U & ((IData)(1U) + (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count)));
            }
        } else {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count = 0U;
        }
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__fault_flag_q 
            = (4U == (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state));
        vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state 
            = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum;
        vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state 
            = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state;
    } else {
        vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_code = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__fault_flag_q = 0U;
        __Vdly__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt = 0U;
        vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state = 0U;
        vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state = 0U;
        __Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v4 = 1U;
    }
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q 
        = ((IData)(vlSelf->reset_n) && (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_connected));
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_flag 
        = ((IData)(vlSelf->reset_n) && (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb));
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count 
        = __Vdly__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_code 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_code;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q 
        = ((IData)(vlSelf->reset_n) && (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.data_valid));
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_flag 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_flag;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_code 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_code;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.data_valid 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_flag 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__fault_flag;
    if (__Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[3U] 
            = __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v0;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[2U] 
            = __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v1;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[1U] 
            = __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v2;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[0U] 
            = __Vdlyvval__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v3;
    }
    if (__Vdlyvset__sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history__v4) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[0U] = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[1U] = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[2U] = 0U;
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history[3U] = 0U;
    }
    vlSelf->sc_dut_adapted__DOT__fault_code = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_code;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__grid_state 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__current_state 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable = 0U;
    vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable 
        = ((1U & (~ ((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state) 
                     >> 2U))) && ((1U & ((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state) 
                                         >> 1U)) && 
                                  (1U & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state)))));
    vlSelf->sc_dut_adapted__DOT__fault_flag = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_flag;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q 
        = ((IData)(vlSelf->reset_n) & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_connected));
    vlSelf->fault_code = vlSelf->sc_dut_adapted__DOT__fault_code;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.grid_state 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__grid_state;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.current_state 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__current_state;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__charge_enable 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable;
    vlSelf->fault_flag = vlSelf->sc_dut_adapted__DOT__fault_flag;
    vlSelf->sc_dut_adapted__DOT__current_state = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.current_state;
    vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.charge_enable 
        = vlSelf->sc_dut_adapted__DOT__u_top__DOT__charge_enable;
    vlSelf->current_state = vlSelf->sc_dut_adapted__DOT__current_state;
    vlSelf->sc_dut_adapted__DOT__charge_enable = vlSymsp->TOP__sc_dut_adapted__DOT__sc_interf_bus.charge_enable;
    vlSelf->charge_enable = vlSelf->sc_dut_adapted__DOT__charge_enable;
}

VL_INLINE_OPT void Vsc_dut_adapted___024root___nba_sequent__TOP__2(Vsc_dut_adapted___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsc_dut_adapted__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsc_dut_adapted___024root___nba_sequent__TOP__2\n"); );
    // Init
    std::string __Vtemp_1;
    std::string __Vtemp_2;
    std::string __Vtemp_3;
    std::string __Vtemp_4;
    // Body
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum 
        = ((IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid)
            ? ((((0x4650U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt)) 
                 | (0xea60U < (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt))) 
                | (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability))
                ? 2U : (((0x4e20U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt)) 
                         | (0xc350U < (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt)))
                         ? 1U : 0U)) : 0U);
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state;
    if ((4U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
        if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if (vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((1U & ((~ (IData)(vlSelf->reset_n)) 
                          | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q))))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q)) 
                     & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full))) 
                    & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability)))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
        }
    } else if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
        if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if ((1U & ((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full) 
                       | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q))))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
            } else if (((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q)) 
                        & (~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability)))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 2U;
            } else if (((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability) 
                        | (2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q)))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 3U;
            }
        } else if (vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
        } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 3U;
        } else if ((1U & (((IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full) 
                           | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q))) 
                          | (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q))))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
        } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 2U;
        }
    } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
        if (vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q) {
            if ((3U > (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
            } else if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 4U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 3U;
            } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 2U;
            }
        } else {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
        }
    } else if ((1U & ((~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q)) 
                      | (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full)))) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 0U;
    } else if ((1U & ((~ (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full)) 
                      & (~ (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__fault_flag_q))))) {
        vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state = 1U;
    }
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 0U;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 0U;
    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum 
        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state;
    if (((IData)(vlSelf->reset_n) & (0U != (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc)))) {
        if ((4U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
            } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
            } else {
                if (VL_UNLIKELY((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
                    __Vtemp_1 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                    VL_WRITEF("SAFETY: FAULT ativado! grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_1),2,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state));
                } else if (VL_UNLIKELY((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                    __Vtemp_2 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                    VL_WRITEF("SAFETY: Sem fault, grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_2),2,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state));
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
                } else if (VL_UNLIKELY((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                    __Vtemp_3 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                        [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                    VL_WRITEF("SAFETY: Sem fault, grid_state=%@ (%1#)\n",
                              -1,&(__Vtemp_3),2,(IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state));
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
                } else {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
                }
                if ((1U & (~ (IData)(vlSelf->reset_n)))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                }
            }
        } else if ((2U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
                if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
                } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
                } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
                } else {
                    vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                        = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
                }
            } else if ((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
            } else {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb 
                    = vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability;
            }
        } else if ((1U & (IData)(vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state))) {
            if (VL_UNLIKELY((2U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum)))) {
                __Vtemp_4 = Vsc_dut_adapted___024unit::__Venumtab_enum_name0
                    [vlSymsp->TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state];
                VL_WRITEF("SAFETY: FAULT ativado! grid_state=%@\n",
                          -1,&(__Vtemp_4));
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 1U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 3U;
            } else if ((1U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 2U;
            } else if ((0U == (IData)(vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum))) {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 1U;
            } else {
                vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
            }
        } else {
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb = 0U;
            vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb = 0U;
        }
    }
    vlSelf->sc_dut_adapted__DOT__grid_state = vlSelf->sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum;
    vlSelf->grid_state = vlSelf->sc_dut_adapted__DOT__grid_state;
}
