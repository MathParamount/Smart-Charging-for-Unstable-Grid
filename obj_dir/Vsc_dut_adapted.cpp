// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsc_dut_adapted__pch.h"

//============================================================
// Constructors

Vsc_dut_adapted::Vsc_dut_adapted(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsc_dut_adapted__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset_n{vlSymsp->TOP.reset_n}
    , battery_connected{vlSymsp->TOP.battery_connected}
    , battery_full{vlSymsp->TOP.battery_full}
    , ml_predict_instability{vlSymsp->TOP.ml_predict_instability}
    , charge_enable{vlSymsp->TOP.charge_enable}
    , fault_flag{vlSymsp->TOP.fault_flag}
    , current_state{vlSymsp->TOP.current_state}
    , fault_code{vlSymsp->TOP.fault_code}
    , grid_state{vlSymsp->TOP.grid_state}
    , grid_voltage_adc{vlSymsp->TOP.grid_voltage_adc}
    , __PVT__sc_include_pkg{vlSymsp->TOP.__PVT__sc_include_pkg}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , __PVT__sc_dut_adapted__DOT__sc_interf_bus{vlSymsp->TOP.__PVT__sc_dut_adapted__DOT__sc_interf_bus}
    , __PVT__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t{vlSymsp->TOP.__PVT__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsc_dut_adapted::Vsc_dut_adapted(const char* _vcname__)
    : Vsc_dut_adapted(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsc_dut_adapted::~Vsc_dut_adapted() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsc_dut_adapted___024root___eval_debug_assertions(Vsc_dut_adapted___024root* vlSelf);
#endif  // VL_DEBUG
void Vsc_dut_adapted___024root___eval_static(Vsc_dut_adapted___024root* vlSelf);
void Vsc_dut_adapted___024root___eval_initial(Vsc_dut_adapted___024root* vlSelf);
void Vsc_dut_adapted___024root___eval_settle(Vsc_dut_adapted___024root* vlSelf);
void Vsc_dut_adapted___024root___eval(Vsc_dut_adapted___024root* vlSelf);

void Vsc_dut_adapted::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsc_dut_adapted::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsc_dut_adapted___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsc_dut_adapted___024root___eval_static(&(vlSymsp->TOP));
        Vsc_dut_adapted___024root___eval_initial(&(vlSymsp->TOP));
        Vsc_dut_adapted___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsc_dut_adapted___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsc_dut_adapted::eventsPending() { return false; }

uint64_t Vsc_dut_adapted::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsc_dut_adapted::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsc_dut_adapted___024root___eval_final(Vsc_dut_adapted___024root* vlSelf);

VL_ATTR_COLD void Vsc_dut_adapted::final() {
    Vsc_dut_adapted___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsc_dut_adapted::hierName() const { return vlSymsp->name(); }
const char* Vsc_dut_adapted::modelName() const { return "Vsc_dut_adapted"; }
unsigned Vsc_dut_adapted::threads() const { return 1; }
void Vsc_dut_adapted::prepareClone() const { contextp()->prepareClone(); }
void Vsc_dut_adapted::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vsc_dut_adapted::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsc_dut_adapted::trace()' called on model that was Verilated without --trace option");
}
