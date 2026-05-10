<<<<<<< HEAD
`timescale 1ns/1ps

package sc_types_pkg;
  
  typedef enum logic [1:0] {
     GRID_NORMAL = 2'b00,
     GRID_UNSTABLE = 2'b01,
     GRID_CRITICAL = 2'b10
  } grid_state_t;

  typedef enum logic [2:0] {
     IDLE = 3'b000,
     CHECK_GRID = 3'b001,
     CHARGING = 3'b010,
     WAIT = 3'b011,
     FAULT = 3'b100
  } state_t;
endpackage
=======
package sc_types_pkg;
  
  typedef enum logic [1:0] {
     GRID_NORMAL,
     GRID_UNSTABLE,
     GRID_CRITICAL
  } grid_state_t;

  typedef enum logic [2:0] {
     IDLE,
     CHECK_GRID,
     CHARGING,
     WAIT,
     FAULT
  } state_t;
endpackage
>>>>>>> cc3f88259f336a35c3ba70f2c756ca125d91aee8
