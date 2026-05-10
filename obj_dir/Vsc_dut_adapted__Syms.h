// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSC_DUT_ADAPTED__SYMS_H_
#define VERILATED_VSC_DUT_ADAPTED__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsc_dut_adapted.h"

// INCLUDE MODULE CLASSES
#include "Vsc_dut_adapted___024root.h"
#include "Vsc_dut_adapted_sc_include_pkg.h"
#include "Vsc_dut_adapted_sc_interface_if.h"
#include "Vsc_dut_adapted___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsc_dut_adapted__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsc_dut_adapted* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsc_dut_adapted___024root      TOP;
    Vsc_dut_adapted___024unit      TOP____024unit;
    Vsc_dut_adapted_sc_interface_if TOP__sc_dut_adapted__DOT__sc_interf_bus;
    Vsc_dut_adapted_sc_interface_if TOP__sc_dut_adapted__DOT__u_top__DOT__sc_interface_bus_t;
    Vsc_dut_adapted_sc_include_pkg TOP__sc_include_pkg;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_sc_dut_adapted;
    VerilatedScope __Vscope_sc_dut_adapted__sc_interf_bus;
    VerilatedScope __Vscope_sc_dut_adapted__u_top;
    VerilatedScope __Vscope_sc_dut_adapted__u_top__sc_interface_bus_t;
    VerilatedScope __Vscope_sc_dut_adapted__u_top__u_fsm;
    VerilatedScope __Vscope_sc_dut_adapted__u_top__u_grid;
    VerilatedScope __Vscope_sc_dut_adapted__u_top__u_grid__unnamedblk1;
    VerilatedScope __Vscope_sc_dut_adapted__u_top__u_grid__unnamedblk2;
    VerilatedScope __Vscope_sc_dut_adapted__u_top__u_safety;
    VerilatedScope __Vscope_sc_include_pkg;

    // CONSTRUCTORS
    Vsc_dut_adapted__Syms(VerilatedContext* contextp, const char* namep, Vsc_dut_adapted* modelp);
    ~Vsc_dut_adapted__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
