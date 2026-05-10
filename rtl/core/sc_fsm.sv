module sc_fsm
(
  //internal signal
  input logic clk,
  input logic reset_n,
  
  //going to actuator
  sc_interface_if.fsm_connect fsm_bus,
  sc_interface_if.grid_monitor grid_bus
);

import sc_types_pkg::*;

//O grid_state só é olhado no carregamento e no check_grid

state_t next_state;

//sequential grid_stateelse if(grid_state_q == GRID_UNSTABLE) 
grid_state_t grid_state_q;

//combinational grid_state

logic battery_connected_q;

logic fault_flag_q;

logic data_valid_q;

//logic check_done;

logic [1:0] check_wait_count;

//sincronization cycle valid

always_ff @(posedge clk or negedge reset_n) begin
    if(!reset_n) begin
        data_valid_q <= 0;
        grid_state_q <= GRID_NORMAL;
        battery_connected_q <= 0;
        fsm_bus.current_state <= IDLE;
	fault_flag_q <= 0;
        check_wait_count <= 0;
     end
    else begin
        data_valid_q <= grid_bus.data_valid;
        grid_state_q <= fsm_bus.grid_state;
        battery_connected_q <= grid_bus.battery_connected;
        fsm_bus.current_state <= next_state;
        fault_flag_q <= (fsm_bus.current_state == FAULT);
	
	if(fsm_bus.current_state == CHECK_GRID && data_valid_q) begin
            if(check_wait_count < 3)
                check_wait_count <= check_wait_count + 1;
        end
        else begin
            check_wait_count <= 0;
        end
     end
end

always_comb begin
   //default
   next_state = fsm_bus.current_state;
   
   //grid_state_enum = grid_bus.grid_state;
   
   unique case(fsm_bus.current_state)
	IDLE: begin
	   if(!battery_connected_q || fsm_bus.battery_full) next_state = IDLE;
           else if(!fsm_bus.battery_full && !fault_flag_q) next_state = CHECK_GRID;
	end
	
	CHECK_GRID: begin
	    	if(!data_valid_q)  next_state = CHECK_GRID;
                
                else if (check_wait_count < 3) begin
                    next_state = CHECK_GRID;
                end
        	else begin
                
                   if(grid_state_q == GRID_CRITICAL) begin
                    next_state = FAULT;
                   end
                   else if (grid_state_q == GRID_UNSTABLE) begin
                    next_state = WAIT;
                   end
                   else if (grid_state_q == GRID_NORMAL) begin
                    next_state = CHARGING;
                   end
               end
            end
	
	CHARGING: begin
	   
	   if(fsm_bus.ml_predict_instability) begin
	        next_state = FAULT;
	   end
	   
	   else if(grid_state_q == GRID_CRITICAL) begin
	   	next_state = FAULT;
	   end
	   
	   else if(grid_state_q == GRID_UNSTABLE) begin
		next_state = WAIT;
	   end
	   
	   else if(fsm_bus.battery_full || !battery_connected_q || !data_valid_q) begin
	 	    next_state = IDLE;
	   end
	   	
	   else if (grid_state_q == GRID_NORMAL) begin
	       	   next_state = CHARGING;
	   end
	end
	
	WAIT: begin
	    if(fsm_bus.battery_full || !battery_connected_q) next_state = IDLE;
	   
	    else if(grid_state_q == GRID_NORMAL && !fsm_bus.ml_predict_instability) next_state = CHARGING;
	    
	    else if (fsm_bus.ml_predict_instability || grid_state_q == GRID_CRITICAL) next_state = FAULT;
	    
	    else if ( grid_state_q == GRID_UNSTABLE) next_state = WAIT;
	end
	
	FAULT: begin
	    if(!fsm_bus.ml_predict_instability) begin
	    	if(!reset_n || !battery_connected_q) begin
	      	    next_state = IDLE;
	    	end
	    
	    	else if (grid_state_q == GRID_NORMAL && !fsm_bus.battery_full && !fsm_bus.ml_predict_instability) begin
	      	   next_state = CHECK_GRID;
	    	end
	    end
	    else begin
	    	next_state = FAULT;
	    end
	end
	
	default: begin 
		next_state = IDLE;
	end
   endcase
end

// fsm output
always_comb begin
    // default
    fsm_bus.charge_enable = 0;

    case(fsm_bus.current_state)
        IDLE: begin
            fsm_bus.charge_enable = 0;
        end

        CHECK_GRID: begin
            fsm_bus.charge_enable = 0;
        end

        CHARGING: begin
             fsm_bus.charge_enable = 1;
        end
        
        WAIT: begin
		fsm_bus.charge_enable = 0;
	    end
	    
	FAULT: begin
	    	fsm_bus.charge_enable = 0;
	    end
	 
	default: fsm_bus.charge_enable = 0;
    endcase
end

endmodule
