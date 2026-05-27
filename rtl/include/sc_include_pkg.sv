package sc_include_pkg;
//adc constants

 //parameter logic signed [15:0] MAX_CURRENT_ADC    = 16'd4000;
 //parameter logic signed [15:0] MIN_CURRENT_ADC    = 16'd10;
 
 
//reference voltage (pike) = 180 V

parameter logic [31:0] V_CRIT_LOW_ADC     = 42000;  // < ~115V RMS
parameter logic [31:0] V_UNSTABLE_MIN_ADC = 54000;  // ~148V RMS
parameter logic [31:0] V_UNSTABLE_MAX_ADC = 75000;  // ~206V RMS
parameter logic [31:0] V_CRIT_HIGH_ADC    = 80000;  // > ~220V RMS

//normal -> above 54000 and below 75000
 
 //obs: 1 LSB = 1mA.

 //normal -> above 54000 and bellow 75000

endpackage
