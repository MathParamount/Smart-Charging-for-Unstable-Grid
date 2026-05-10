// DESCRIPTION: Verilator generated Verilog
// Wrapper module for DPI protected library
// This module requires libnew_dut.a or libnew_dut.so to work
// See instructions in your simulator for how to use DPI libraries

module new_dut (
        input logic clk
        , input logic reset_n
        , input logic battery_connected
        , input logic battery_full
        , input logic ml_predict_instability
        , output logic charge_enable
        , output logic fault_flag
        , output logic [2:0]  current_state
        , output logic [1:0]  fault_code
        , output logic [1:0]  grid_state
        , input logic [15:0]  grid_voltage_adc
    );
    
    // Precision of submodule (commented out to avoid requiring timescale on all modules)
    // timeunit 1ns;
    // timeprecision 1ps;
    
    // Checks to make sure the .sv wrapper and library agree
    import "DPI-C" function void new_dut_protectlib_check_hash(int protectlib_hash__V);
    
    // Creates an instance of the library module at initial-time
    // (one for each instance in the user's design) also evaluates
    // the library module's initial process
    import "DPI-C" function chandle new_dut_protectlib_create(string scope__V);
    
    // Updates all non-clock inputs and retrieves the results
    import "DPI-C" function longint new_dut_protectlib_combo_update (
        chandle handle__V
        , input logic battery_connected
        , input logic battery_full
        , input logic ml_predict_instability
        , output logic charge_enable
        , output logic fault_flag
        , output logic [2:0]  current_state
        , output logic [1:0]  fault_code
        , output logic [1:0]  grid_state
        , input logic [15:0]  grid_voltage_adc
    );
    
    // Updates all clocks and retrieves the results
    import "DPI-C" function longint new_dut_protectlib_seq_update(
        chandle handle__V
        , input logic clk
        , input logic reset_n
        , output logic charge_enable
        , output logic fault_flag
        , output logic [2:0]  current_state
        , output logic [1:0]  fault_code
        , output logic [1:0]  grid_state
    );
    
    // Need to convince some simulators that the input to the module
    // must be evaluated before evaluating the clock edge
    import "DPI-C" function void new_dut_protectlib_combo_ignore(
        chandle handle__V
        , input logic battery_connected
        , input logic battery_full
        , input logic ml_predict_instability
        , input logic [15:0]  grid_voltage_adc
    );
    
    // Evaluates the library module's final process
    import "DPI-C" function void new_dut_protectlib_final(chandle handle__V);
    
    // verilator tracing_off
    chandle handle__V;
    time last_combo_seqnum__V;
    time last_seq_seqnum__V;

    logic charge_enable_combo__V;
    logic fault_flag_combo__V;
    logic [2:0]  current_state_combo__V;
    logic [1:0]  fault_code_combo__V;
    logic [1:0]  grid_state_combo__V;
    logic charge_enable_seq__V;
    logic fault_flag_seq__V;
    logic [2:0]  current_state_seq__V;
    logic [1:0]  fault_code_seq__V;
    logic [1:0]  grid_state_seq__V;
    logic charge_enable_tmp__V;
    logic fault_flag_tmp__V;
    logic [2:0]  current_state_tmp__V;
    logic [1:0]  fault_code_tmp__V;
    logic [1:0]  grid_state_tmp__V;
    // Hash value to make sure this file and the corresponding
    // library agree
    localparam int protectlib_hash__V = 32'd2530491818;

    initial begin
        new_dut_protectlib_check_hash(protectlib_hash__V);
        handle__V = new_dut_protectlib_create($sformatf("%m"));
    end
    
    // Combinatorialy evaluate changes to inputs
    always @* begin
        last_combo_seqnum__V = new_dut_protectlib_combo_update(
            handle__V
            , battery_connected
            , battery_full
            , ml_predict_instability
            , charge_enable_combo__V
            , fault_flag_combo__V
            , current_state_combo__V
            , fault_code_combo__V
            , grid_state_combo__V
            , grid_voltage_adc
        );
    end
    
    // Evaluate clock edges
    always @(posedge clk or negedge clk, posedge reset_n or negedge reset_n) begin
        new_dut_protectlib_combo_ignore(
            handle__V
            , battery_connected
            , battery_full
            , ml_predict_instability
            , grid_voltage_adc
        );
        last_seq_seqnum__V <= new_dut_protectlib_seq_update(
            handle__V
            , clk
            , reset_n
            , charge_enable_tmp__V
            , fault_flag_tmp__V
            , current_state_tmp__V
            , fault_code_tmp__V
            , grid_state_tmp__V
        );
        charge_enable_seq__V <= charge_enable_tmp__V;
        fault_flag_seq__V <= fault_flag_tmp__V;
        current_state_seq__V <= current_state_tmp__V;
        fault_code_seq__V <= fault_code_tmp__V;
        grid_state_seq__V <= grid_state_tmp__V;
    end
    
    // Select between combinatorial and sequential results
    always @* begin
        if (last_seq_seqnum__V > last_combo_seqnum__V) begin
            charge_enable = charge_enable_seq__V;
            fault_flag = fault_flag_seq__V;
            current_state = current_state_seq__V;
            fault_code = fault_code_seq__V;
            grid_state = grid_state_seq__V;
        end
        else begin
            charge_enable = charge_enable_combo__V;
            fault_flag = fault_flag_combo__V;
            current_state = current_state_combo__V;
            fault_code = fault_code_combo__V;
            grid_state = grid_state_combo__V;
        end
    end
    
    final new_dut_protectlib_final(handle__V);
    
endmodule
