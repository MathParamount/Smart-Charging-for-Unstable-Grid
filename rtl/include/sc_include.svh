`ifndef SC_INCLUDE.SVH
`define SC_INCLUDE.SVH

//Grid conditions

typedef enum logic [1:0] {
	GRID_NORMAL,
	GRID_UNSTABLE,
	GRID_CRITICAL
} grid_state_t;

//System states

typedef enum logic [2:0] {
	IDLE,
	CHECK_GRID,
	CHARGING,
	WAIT,
	FAULT
} state_t;

//adc constants

`define ADC_FULL_SCALE     4096
`define MAX_CURRENT_ADC    2048
`define V_CRIT_LOW_ADC     1200
`define V_CRIT_HIGH_ADC    2800
`define V_UNSTABLE_MIN_ADC 1400
`define V_UNSTABLE_MAX_ADC 2600

`endif
