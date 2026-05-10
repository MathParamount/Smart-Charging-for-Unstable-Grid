// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsc_dut.h for the primary calling header

#include "Vsc_dut__pch.h"
#include "Vsc_dut_sc_interface_if.h"

std::string VL_TO_STRING(const Vsc_dut_sc_interface_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vsc_dut_sc_interface_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
