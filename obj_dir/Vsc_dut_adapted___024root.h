// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsc_dut_adapted.h for the primary calling header

#ifndef VERILATED_VSC_DUT_ADAPTED___024ROOT_H_
#define VERILATED_VSC_DUT_ADAPTED___024ROOT_H_  // guard

#include "verilated.h"
class Vsc_dut_adapted___024unit;
class Vsc_dut_adapted_sc_include_pkg;
class Vsc_dut_adapted_sc_interface_if;


class Vsc_dut_adapted__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsc_dut_adapted___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsc_dut_adapted_sc_include_pkg* __PVT__sc_include_pkg;
    Vsc_dut_adapted___024unit* __PVT____024unit;
    Vsc_dut_adapted_sc_interface_if* __PVT__sc_dut_adapted__DOT__sc_interf_bus;
    Vsc_dut_adapted_sc_interface_if* __PVT__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset_n,0,0);
        VL_IN8(battery_connected,0,0);
        VL_IN8(battery_full,0,0);
        VL_IN8(ml_predict_instability,0,0);
        VL_OUT8(charge_enable,0,0);
        VL_OUT8(fault_flag,0,0);
        VL_OUT8(current_state,2,0);
        VL_OUT8(fault_code,1,0);
        VL_OUT8(grid_state,1,0);
        CData/*0:0*/ sc_dut_adapted__DOT__clk;
        CData/*0:0*/ sc_dut_adapted__DOT__reset_n;
        CData/*0:0*/ sc_dut_adapted__DOT__battery_connected;
        CData/*0:0*/ sc_dut_adapted__DOT__battery_full;
        CData/*0:0*/ sc_dut_adapted__DOT__ml_predict_instability;
        CData/*0:0*/ sc_dut_adapted__DOT__charge_enable;
        CData/*0:0*/ sc_dut_adapted__DOT__fault_flag;
        CData/*2:0*/ sc_dut_adapted__DOT__current_state;
        CData/*1:0*/ sc_dut_adapted__DOT__fault_code;
        CData/*1:0*/ sc_dut_adapted__DOT__grid_state;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__clk;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__reset_n;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__battery_connected;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__battery_full;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__ml_predict_instability;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__charge_enable;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__fault_flag;
        CData/*2:0*/ sc_dut_adapted__DOT__u_top__DOT__current_state;
        CData/*1:0*/ sc_dut_adapted__DOT__u_top__DOT__fault_code;
        CData/*1:0*/ sc_dut_adapted__DOT__u_top__DOT__grid_state;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__clk;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__reset_n;
        CData/*1:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum;
        CData/*2:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__clk;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__reset_n;
        CData/*2:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state;
        CData/*1:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__fault_flag_q;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q;
        CData/*1:0*/ sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__clk;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__reset_n;
        CData/*1:0*/ sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum;
        CData/*0:0*/ sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb;
        CData/*1:0*/ sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset_n__0;
        CData/*0:0*/ __VactContinue;
        VL_IN16(grid_voltage_adc,15,0);
        SData/*15:0*/ sc_dut_adapted__DOT__grid_voltage_adc;
        SData/*15:0*/ sc_dut_adapted__DOT__u_top__DOT__grid_voltage_adc;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sum_voltage;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_sum;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_adc;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h0;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h1;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h2;
    };
    struct {
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__debug_h3;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 4> sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsc_dut_adapted__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsc_dut_adapted___024root(Vsc_dut_adapted__Syms* symsp, const char* v__name);
    ~Vsc_dut_adapted___024root();
    VL_UNCOPYABLE(Vsc_dut_adapted___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
