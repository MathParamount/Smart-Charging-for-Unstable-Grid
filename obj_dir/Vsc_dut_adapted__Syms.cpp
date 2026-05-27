// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsc_dut_adapted__pch.h"
#include "Vsc_dut_adapted.h"
#include "Vsc_dut_adapted___024root.h"
#include "Vsc_dut_adapted_sc_include_pkg.h"
#include "Vsc_dut_adapted_sc_interface_if.h"
#include "Vsc_dut_adapted___024unit.h"

// FUNCTIONS
Vsc_dut_adapted__Syms::~Vsc_dut_adapted__Syms()
{
}

Vsc_dut_adapted__Syms::Vsc_dut_adapted__Syms(VerilatedContext* contextp, const char* namep, Vsc_dut_adapted* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
    , TOP__sc_dut_adapted__DOT__sc_interf_bus{this, Verilated::catName(namep, "sc_dut_adapted.sc_interf_bus")}
    , TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t{this, Verilated::catName(namep, "sc_dut_adapted.u_top.sc_interface_bus_t")}
    , TOP__sc_include_pkg{this, Verilated::catName(namep, "sc_include_pkg")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    TOP.__PVT__sc_dut_adapted__DOT__sc_interf_bus = &TOP__sc_dut_adapted__DOT__sc_interf_bus;
    TOP.__PVT__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t = &TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t;
    TOP.__PVT__sc_include_pkg = &TOP__sc_include_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    TOP__sc_dut_adapted__DOT__sc_interf_bus.__Vconfigure(true);
    TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.__Vconfigure(false);
    TOP__sc_include_pkg.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted.configure(this, name(), "sc_dut_adapted", "sc_dut_adapted", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__sc_interf_bus.configure(this, name(), "sc_dut_adapted.sc_interf_bus", "sc_interf_bus", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__u_top.configure(this, name(), "sc_dut_adapted.u_top", "u_top", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.configure(this, name(), "sc_dut_adapted.u_top.sc_interface_bus_t", "sc_interface_bus_t", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__u_top__u_fsm.configure(this, name(), "sc_dut_adapted.u_top.u_fsm", "u_fsm", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__u_top__u_grid.configure(this, name(), "sc_dut_adapted.u_top.u_grid", "u_grid", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__u_top__u_grid__unnamedblk1.configure(this, name(), "sc_dut_adapted.u_top.u_grid.unnamedblk1", "unnamedblk1", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__u_top__u_grid__unnamedblk2.configure(this, name(), "sc_dut_adapted.u_top.u_grid.unnamedblk2", "unnamedblk2", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_dut_adapted__u_top__u_safety.configure(this, name(), "sc_dut_adapted.u_top.u_safety", "u_safety", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_sc_include_pkg.configure(this, name(), "sc_include_pkg", "sc_include_pkg", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"battery_connected", &(TOP.battery_connected), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"battery_full", &(TOP.battery_full), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"charge_enable", &(TOP.charge_enable), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"current_state", &(TOP.current_state), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,2,0);
        __Vscope_TOP.varInsert(__Vfinal,"fault_code", &(TOP.fault_code), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"fault_flag", &(TOP.fault_flag), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"grid_state", &(TOP.grid_state), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"grid_voltage_adc", &(TOP.grid_voltage_adc), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"ml_predict_instability", &(TOP.ml_predict_instability), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset_n", &(TOP.reset_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"battery_connected", &(TOP.sc_dut_adapted__DOT__battery_connected), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"battery_full", &(TOP.sc_dut_adapted__DOT__battery_full), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"charge_enable", &(TOP.sc_dut_adapted__DOT__charge_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"clk", &(TOP.sc_dut_adapted__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"current_state", &(TOP.sc_dut_adapted__DOT__current_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"fault_code", &(TOP.sc_dut_adapted__DOT__fault_code), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"fault_flag", &(TOP.sc_dut_adapted__DOT__fault_flag), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"grid_state", &(TOP.sc_dut_adapted__DOT__grid_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"grid_voltage_adc", &(TOP.sc_dut_adapted__DOT__grid_voltage_adc), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"ml_predict_instability", &(TOP.sc_dut_adapted__DOT__ml_predict_instability), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted.varInsert(__Vfinal,"reset_n", &(TOP.sc_dut_adapted__DOT__reset_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"battery_connected", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_connected), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"battery_full", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.battery_full), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"charge_enable", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.charge_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"current_state", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.current_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"data_valid", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.data_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"fault_code", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_code), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"fault_flag", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.fault_flag), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"grid_state", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.grid_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"grid_voltage_adc", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.grid_voltage_adc), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_sc_dut_adapted__sc_interf_bus.varInsert(__Vfinal,"ml_predict_instability", &(TOP__sc_dut_adapted__DOT__sc_interf_bus.ml_predict_instability), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"battery_connected", &(TOP.sc_dut_adapted__DOT__u_top__DOT__battery_connected), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"battery_full", &(TOP.sc_dut_adapted__DOT__u_top__DOT__battery_full), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"charge_enable", &(TOP.sc_dut_adapted__DOT__u_top__DOT__charge_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"clk", &(TOP.sc_dut_adapted__DOT__u_top__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"current_state", &(TOP.sc_dut_adapted__DOT__u_top__DOT__current_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"fault_code", &(TOP.sc_dut_adapted__DOT__u_top__DOT__fault_code), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"fault_flag", &(TOP.sc_dut_adapted__DOT__u_top__DOT__fault_flag), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"grid_state", &(TOP.sc_dut_adapted__DOT__u_top__DOT__grid_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"grid_voltage_adc", &(TOP.sc_dut_adapted__DOT__u_top__DOT__grid_voltage_adc), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"ml_predict_instability", &(TOP.sc_dut_adapted__DOT__u_top__DOT__ml_predict_instability), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top.varInsert(__Vfinal,"reset_n", &(TOP.sc_dut_adapted__DOT__u_top__DOT__reset_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"battery_connected", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_connected), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"battery_full", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.battery_full), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"charge_enable", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.charge_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"current_state", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.current_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"data_valid", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.data_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"fault_code", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_code), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"fault_flag", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.fault_flag), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"grid_state", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"grid_voltage_adc", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.grid_voltage_adc), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t.varInsert(__Vfinal,"ml_predict_instability", &(TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t.ml_predict_instability), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"battery_connected_q", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__battery_connected_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"check_wait_count", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__check_wait_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"clk", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"data_valid_q", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__data_valid_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"fault_flag_q", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__fault_flag_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"grid_state_q", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__grid_state_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"next_state", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__next_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_sc_dut_adapted__u_top__u_fsm.varInsert(__Vfinal,"reset_n", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_fsm__DOT__reset_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"battery_connected_q", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__battery_connected_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"clk", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"data_valid", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__data_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"filter_volt", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__filter_volt), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"grid_state_enum", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__grid_state_enum), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"reset_n", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__reset_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"sample_count", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sample_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"sum_voltage", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__sum_voltage), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_sc_dut_adapted__u_top__u_grid.varInsert(__Vfinal,"voltage_history", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__voltage_history), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,0,3);
        __Vscope_sc_dut_adapted__u_top__u_grid__unnamedblk1.varInsert(__Vfinal,"i", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_sc_dut_adapted__u_top__u_grid__unnamedblk2.varInsert(__Vfinal,"i", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_grid__DOT__unnamedblk2__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_sc_dut_adapted__u_top__u_safety.varInsert(__Vfinal,"clk", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_safety.varInsert(__Vfinal,"fault_code_comb", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_code_comb), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top__u_safety.varInsert(__Vfinal,"fault_flag_comb", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__fault_flag_comb), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_dut_adapted__u_top__u_safety.varInsert(__Vfinal,"grid_state_enum", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__grid_state_enum), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_sc_dut_adapted__u_top__u_safety.varInsert(__Vfinal,"reset_n", &(TOP.sc_dut_adapted__DOT__u_top__DOT__u_safety__DOT__reset_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_sc_include_pkg.varInsert(__Vfinal,"V_CRIT_HIGH_ADC", const_cast<void*>(static_cast<const void*>(&(TOP__sc_include_pkg.V_CRIT_HIGH_ADC))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_sc_include_pkg.varInsert(__Vfinal,"V_CRIT_LOW_ADC", const_cast<void*>(static_cast<const void*>(&(TOP__sc_include_pkg.V_CRIT_LOW_ADC))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_sc_include_pkg.varInsert(__Vfinal,"V_UNSTABLE_MAX_ADC", const_cast<void*>(static_cast<const void*>(&(TOP__sc_include_pkg.V_UNSTABLE_MAX_ADC))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_sc_include_pkg.varInsert(__Vfinal,"V_UNSTABLE_MIN_ADC", const_cast<void*>(static_cast<const void*>(&(TOP__sc_include_pkg.V_UNSTABLE_MIN_ADC))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
    }
}
