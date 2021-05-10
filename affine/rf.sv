module rf import affine::*; 
    (input logic clk_i, 
     input logic wdual_i,
     input logic [N-1:0] ext_data_i,
     input logic signed [N-1:0] wd_data_i,
     input logic [1:0] rs_addr_i,
     input logic [1:0] rd_addr_i,
     output logic signed [N-1:0] rs_data_o, 
     output logic signed [N-1:0] rd_data_o,
	  
	  input  logic signed [N-1:0] acc2_i,
     output logic signed [N-1:0] acc1_o,
     output logic signed [N-1:0] acc2_o);
    
    logic signed [N-1:0] regs [0:3];

    always_ff @(posedge clk_i) begin : REG_POS
        if(~wdual_i && rd_addr_i != 0) begin
            regs[rd_addr_i] <= wd_data_i;
		  end else if(wdual_i) begin
            regs[2] <= wd_data_i;
		    regs[3] <= acc2_i;
		  end
		    regs[0] <= ext_data_i;
    end

    always_comb begin : OUTPUT		  
        rs_data_o = regs[rs_addr_i];
        rd_data_o = regs[rd_addr_i]; 
        // ACC outputs fixed
        acc1_o = regs[2];
        acc2_o = regs[3];
    end

endmodule
