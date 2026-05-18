package sc_include_pkg;
//adc constants

 //parameter logic signed [15:0] MAX_CURRENT_ADC    = 16'd4000;
 //parameter logic signed [15:0] MIN_CURRENT_ADC    = 16'd10;
 
 
//reference voltage (pike) = 180 V

parameter logic [31:0] V_CRIT_LOW_ADC     = 42000;  // < ~115.35V
parameter logic [31:0] V_UNSTABLE_MIN_ADC = 54000;  // ~148.31V
parameter logic [31:0] V_UNSTABLE_MAX_ADC = 75000;  // ~206V
parameter logic [31:0] V_CRIT_HIGH_ADC    = 80000;  // > ~220V
 
 //obs: 1 LSB = 1mA.

endpackage
