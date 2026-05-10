# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vsc_dut_adapted.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vsc_dut_adapted \
	Vsc_dut_adapted___024root__DepSet_h4eb495f3__0 \
	Vsc_dut_adapted___024root__DepSet_hb75877a5__0 \
	Vsc_dut_adapted_sc_interface_if__DepSet_h929590c1__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vsc_dut_adapted___024root__Slow \
	Vsc_dut_adapted___024root__DepSet_h4eb495f3__0__Slow \
	Vsc_dut_adapted___024root__DepSet_hb75877a5__0__Slow \
	Vsc_dut_adapted_sc_include_pkg__Slow \
	Vsc_dut_adapted_sc_include_pkg__DepSet_hfb59466e__0__Slow \
	Vsc_dut_adapted_sc_interface_if__Slow \
	Vsc_dut_adapted_sc_interface_if__DepSet_h929590c1__0__Slow \
	Vsc_dut_adapted___024unit__Slow \
	Vsc_dut_adapted___024unit__DepSet_he1709b15__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vsc_dut_adapted__Dpi \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vsc_dut_adapted__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
