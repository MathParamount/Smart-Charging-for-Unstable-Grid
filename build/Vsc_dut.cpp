// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsc_dut__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsc_dut::Vsc_dut(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsc_dut__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset_n{vlSymsp->TOP.reset_n}
    , battery_connected{vlSymsp->TOP.battery_connected}
    , battery_full{vlSymsp->TOP.battery_full}
    , ml_predict_instability{vlSymsp->TOP.ml_predict_instability}
    , charge_enable{vlSymsp->TOP.charge_enable}
    , fault_flag{vlSymsp->TOP.fault_flag}
    , current_state{vlSymsp->TOP.current_state}
    , fault_code{vlSymsp->TOP.fault_code}
    , grid_voltage_adc{vlSymsp->TOP.grid_voltage_adc}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , __PVT__sc_dut__DOT__sc_interf_bus{vlSymsp->TOP.__PVT__sc_dut__DOT__sc_interf_bus}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsc_dut::Vsc_dut(const char* _vcname__)
    : Vsc_dut(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsc_dut::~Vsc_dut() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsc_dut___024root___eval_debug_assertions(Vsc_dut___024root* vlSelf);
#endif  // VL_DEBUG
void Vsc_dut___024root___eval_static(Vsc_dut___024root* vlSelf);
void Vsc_dut___024root___eval_initial(Vsc_dut___024root* vlSelf);
void Vsc_dut___024root___eval_settle(Vsc_dut___024root* vlSelf);
void Vsc_dut___024root___eval(Vsc_dut___024root* vlSelf);

void Vsc_dut::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsc_dut::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsc_dut___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsc_dut___024root___eval_static(&(vlSymsp->TOP));
        Vsc_dut___024root___eval_initial(&(vlSymsp->TOP));
        Vsc_dut___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsc_dut___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsc_dut::eventsPending() { return false; }

uint64_t Vsc_dut::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsc_dut::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsc_dut___024root___eval_final(Vsc_dut___024root* vlSelf);

VL_ATTR_COLD void Vsc_dut::final() {
    Vsc_dut___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsc_dut::hierName() const { return vlSymsp->name(); }
const char* Vsc_dut::modelName() const { return "Vsc_dut"; }
unsigned Vsc_dut::threads() const { return 1; }
void Vsc_dut::prepareClone() const { contextp()->prepareClone(); }
void Vsc_dut::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsc_dut::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsc_dut___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsc_dut___024root__trace_init_top(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsc_dut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsc_dut___024root*>(voidSelf);
    Vsc_dut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsc_dut___024root__trace_decl_types(tracep);
    Vsc_dut___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsc_dut___024root__trace_register(Vsc_dut___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsc_dut::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsc_dut::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsc_dut___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
