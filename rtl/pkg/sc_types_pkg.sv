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
