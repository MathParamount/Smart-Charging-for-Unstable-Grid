// sc_top.sv
module sc_fpga_top
(
input logic clk, 
input logic reset_n,
output logic [3:0] led
);

	logic reset;
	logic count;
	
	//interface declarations
	sc_interface_if sc_interface_bus_t();
	
	//state_t current_state;
	
	//dut declarations
	sc_grid_monitor u_grid (
        .clk(clk),
        .reset_n(reset_n),
        .grid_bus(sc_interface_bus_t.grid_monitor),
	.fsm_bus(sc_interface_bus_t.fsm_connect)
    	);
	
	sc_fsm u_fsm
	(
	  .clk(clk),
	  .reset_n(reset_n),
	  .fsm_bus(sc_interface_bus_t.fsm_connect),
	  .grid_bus(sc_interface_bus_t.grid_monitor)
	);
	
	sc_safety_monitor u_safety
	(
	  .clk(clk),
	  .reset_n(reset_n),
	  .safety_bus(sc_interface_bus_t.safety),
	  .grid_bus(sc_interface_bus_t.grid_monitor)
	);
	
	//grid state condition and battery_full tests
	always_ff @(posedge clk) begin
	   count <= count + 1;
	   
	   if (count <= 10) begin
	   	grid_state <= GRID_NORMAL;
	   end
	   else if(count <= 20) begin
		grid_state <= GRID_UNSTABLE;
	   end
	   
	   else if(count <= 30) begin
	   	grid_state <= GRID_CRITICAL;
	   end
	   
	   else begin
	   	grid_state <= GRID_NORMAL;
	   	fsm_bus.battery_full <= 1;
	   end
	end
	
	//sequential test
	
	always_ff @(posedge clk or negedge reset_n) 
	begin
	   if(!reset)
	   begin
	   	fsm_bus.charge_enable <= 0;
	   	fsm_bus.current_state <= IDLE;
	   	safety_bus.fault_flag <= 0;
		safety_bus.fault_code <= '0;
		grid_bus.battery_connected <= 0;
		fsm_bus.battery_full <= 0;
	   end
	   
	   else begin		
	   	grid_bus.battery_connected <= 1;
	   	
	   	unique case(fsm_bus.current_state) begin
	   	    IDLE: begin
	   	    	if(!grid_bus.battery_connected || fsm_bus.battery_full) next_state = IDLE;
           		else if(!fsm_bus.battery_full && !safety_bus.fault_flag) next_state = CHECK_GRID;
	   	    end
	   	    
	   	    CHECK_GRID: begin
	   	    	
	   	    	if(grid_state == GRID_CRITICAL) begin
                    		fsm_bus.current_state <= FAULT;
                   	end
                   	else if (grid_state == GRID_UNSTABLE) begin
                    		fsm_bus.current_state <= WAIT;
                   	end
                   	else if (grid_state == GRID_NORMAL) begin
                    		fsm_bus.current_state <= CHARGING;
                   	end
	   	    end
	   	    
	   	    CHARGING: begin
	   	    	
	   	    	if(grid_state_q == GRID_CRITICAL) begin
	   			fsm_bus.current_state <= FAULT;
	   		end
	   
	   		else if(grid_state_q == GRID_UNSTABLE) begin
				fsm_bus.current_state <= WAIT;
	   		end
	   	    	
	   		fsm_bus.charge_enable <= 1;
	   		safety_bus.fault_code <= 4'b0010;
	   		
	   		if(fsm_bus.battery_full) fsm_bus.current_state <= IDLE;
	   	    
	   	    end
	   	    
	   	    WAIT: begin
	   		safety_bus.fault_code <= 4'b1001;
	   		
	   		if(grid_state == GRID_NORMAL) begin
	   		   fsm_bus.current_state <= CHARGING;
	   		end
	   	    end
	   	    
	   	    FAULT: begin
	   		fsm_bus.charge_enable <= 0;
	   		safety_bus.fault_flag <= 1;
	   		safety_bus.fault_code <= 4'b0100;
	   		
			if(grid_state == GRID_NORMAL) begin
			   safety_bus.fault_flag <= 0;	
	   		   fsm_bus.current_state <= CHARGING;
	   		end
	   	    end
	   	    
	   	    default: fsm_bus.current_state <= IDLE;
	   	    
	   	endcase
	    end
	 end
	
	//assertions
	assign reset = ~reset_n;
	assign grid_state = sc_interface_bus_t.grid_state;
	
	//assign new_clk = clk[24];	//fast clock kick, thus I divided clk/24
	
	assign led[0] = clk;
	assign led[1] = grid_bus.battery_connected;
	assign led[2] = fsm_bus.charge_enable;
	assign led[4] = fsm_bus.battery_full;
	assign led[5] = safety_bus.fault_flag;
	assign led[6] = count;
	assign led[7] = fsm_bus.current_state;
	
endmodule
