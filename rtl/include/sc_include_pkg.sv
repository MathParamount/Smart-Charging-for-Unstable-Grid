package sc_include_pkg;
//adc constants

 //parameter logic signed [15:0] MAX_CURRENT_ADC    = 16'd4000;
 //parameter logic signed [15:0] MIN_CURRENT_ADC    = 16'd10;
 
parameter logic [15:0] V_CRIT_LOW_ADC     = 18000;  // < ~80V
parameter logic [15:0] V_UNSTABLE_MIN_ADC = 20000;  // ~100V
parameter logic [15:0] V_UNSTABLE_MAX_ADC = 50000;  // ~230V
parameter logic [15:0] V_CRIT_HIGH_ADC    = 60000;  // > ~260V
 
 //obs: 1 LSB = 1mA.
/*
 parameter int V_CRIT_LOW_ADC      = 18000;
 parameter int V_UNSTABLE_MIN_ADC  = 25000;
 parameter int V_UNSTABLE_MAX_ADC  = 51000;
 parameter int V_CRIT_HIGH_ADC     = 63000;

*/

endpackage
