// DESCRIPTION: Verilator generated C++
// Wrapper functions for DPI protected library

#include "Vsc_dut_adapted.h"
#include "verilated_dpi.h"

#include <cstdio>
#include <cstdlib>

// Container class to house verilated object and sequence number
class Vsc_dut_adapted_container: public Vsc_dut_adapted {
  public:
    long long m_seqnum;
    Vsc_dut_adapted_container(const char* scopep__V):
    Vsc_dut_adapted(scopep__V) {}
};

extern "C" {
    
    // Checks to make sure the .sv wrapper and library agree
    void new_dut_protectlib_check_hash(int protectlib_hash__V) {
        const int expected_hash__V = 2530491818U;
        if (protectlib_hash__V != expected_hash__V) {
            fprintf(stderr, "%%Error: cannot use new_dut library, Verliog (%u) and library (%u) hash values do not agree\n", protectlib_hash__V, expected_hash__V);
            std::exit(EXIT_FAILURE);
        }
    }
    
    // Creates an instance of the library module at initial-time
    // (one for each instance in the user's design) also evaluates
    // the library module's initial process
    void* new_dut_protectlib_create(const char* scopep__V) {
        Vsc_dut_adapted_container* const handlep__V = new Vsc_dut_adapted_container{scopep__V};
        return handlep__V;
    }
    
    // Updates all non-clock inputs and retrieves the results
    long long new_dut_protectlib_combo_update(
        void* vhandlep__V
        , svLogic battery_connected
        , svLogic battery_full
        , svLogic ml_predict_instability
        , svLogic* charge_enable
        , svLogic* fault_flag
        , svLogicVecVal* current_state
        , svLogicVecVal* fault_code
        , svLogicVecVal* grid_state
        , const svLogicVecVal* grid_voltage_adc
    )
    {
        Vsc_dut_adapted_container* const handlep__V = static_cast<Vsc_dut_adapted_container*>(vhandlep__V);
        handlep__V->battery_connected = battery_connected;
        handlep__V->battery_full = battery_full;
        handlep__V->ml_predict_instability = ml_predict_instability;
        handlep__V->grid_voltage_adc = VL_SET_I_SVLV(grid_voltage_adc);
        handlep__V->eval();
        for (size_t charge_enable__Vidx = 0; charge_enable__Vidx < 1; ++charge_enable__Vidx) *charge_enable = handlep__V->charge_enable;
        for (size_t fault_flag__Vidx = 0; fault_flag__Vidx < 1; ++fault_flag__Vidx) *fault_flag = handlep__V->fault_flag;
        for (size_t current_state__Vidx = 0; current_state__Vidx < 1; ++current_state__Vidx) VL_SET_SVLV_I(3, current_state + 1 * current_state__Vidx, handlep__V->current_state);
        for (size_t fault_code__Vidx = 0; fault_code__Vidx < 1; ++fault_code__Vidx) VL_SET_SVLV_I(2, fault_code + 1 * fault_code__Vidx, handlep__V->fault_code);
        for (size_t grid_state__Vidx = 0; grid_state__Vidx < 1; ++grid_state__Vidx) VL_SET_SVLV_I(2, grid_state + 1 * grid_state__Vidx, handlep__V->grid_state);
        return handlep__V->m_seqnum++;
    }
    
    // Updates all clocks and retrieves the results
    long long new_dut_protectlib_seq_update(
        void* vhandlep__V
        , svLogic clk
        , svLogic reset_n
        , svLogic* charge_enable
        , svLogic* fault_flag
        , svLogicVecVal* current_state
        , svLogicVecVal* fault_code
        , svLogicVecVal* grid_state
    )
    {
        Vsc_dut_adapted_container* const handlep__V = static_cast<Vsc_dut_adapted_container*>(vhandlep__V);
        handlep__V->clk = clk;
        handlep__V->reset_n = reset_n;
        handlep__V->eval();
        for (size_t charge_enable__Vidx = 0; charge_enable__Vidx < 1; ++charge_enable__Vidx) *charge_enable = handlep__V->charge_enable;
        for (size_t fault_flag__Vidx = 0; fault_flag__Vidx < 1; ++fault_flag__Vidx) *fault_flag = handlep__V->fault_flag;
        for (size_t current_state__Vidx = 0; current_state__Vidx < 1; ++current_state__Vidx) VL_SET_SVLV_I(3, current_state + 1 * current_state__Vidx, handlep__V->current_state);
        for (size_t fault_code__Vidx = 0; fault_code__Vidx < 1; ++fault_code__Vidx) VL_SET_SVLV_I(2, fault_code + 1 * fault_code__Vidx, handlep__V->fault_code);
        for (size_t grid_state__Vidx = 0; grid_state__Vidx < 1; ++grid_state__Vidx) VL_SET_SVLV_I(2, grid_state + 1 * grid_state__Vidx, handlep__V->grid_state);
        return handlep__V->m_seqnum++;
    }
    
    // Need to convince some simulators that the input to the module
    // must be evaluated before evaluating the clock edge
    void new_dut_protectlib_combo_ignore(
        void* vhandlep__V
        , svLogic battery_connected
        , svLogic battery_full
        , svLogic ml_predict_instability
        , const svLogicVecVal* grid_voltage_adc
    )
    { }
    
    // Evaluates the library module's final process
    void new_dut_protectlib_final(void* vhandlep__V) {
        Vsc_dut_adapted_container* const handlep__V = static_cast<Vsc_dut_adapted_container*>(vhandlep__V);
        handlep__V->final();
        delete handlep__V;
    }
    
}
