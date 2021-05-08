module rf import affine::*; 
    (input logic clk_i, 
     input logic wdual_i,
     input logic [N-1:0] ext_data_i,
     input logic signed [N-1:0] wd_data_i,
     input logic [2:0] rs_addr_i,
     input logic [2:0] rd_addr_i,
     output logic signed [N-1:0] rs_data_o, 
     output logic signed [N-1:0] rd_data_o,
     output logic signed [N-1:0] acc1_o,
     output logic signed [N-1:0] acc2_o);
    
    logic signed [N-1:0] regs [0:1];
    logic signed [N-1:0] acc1;
    logic signed [N-1:0] acc2;
    
    logic signed [N-1:0] regs_read [0:4];

    // External Input Register
    always_ff @(posedge clk_i) begin : REG_EXT
        regs[0] <= ext_data_i;
    end

    // Single Temporary Register
    always_ff @(posedge clk_i) begin : REG_POS
        if(~wdual_i && rd_addr_i == 1)
            regs[1] <= wd_data_i;
    end

    // Secondary accumulator clock is inverted
    always_ff @(posedge clk_i) begin : ACC_POS
        if(~wdual_i && rd_addr_i == 2)
            acc1 <= wd_data_i;            
        if(wdual_i)
            acc1 <= wd_data_i;
    end

    // Secondary accumulator clock is inverted
    always_ff @(negedge clk_i) begin : ACC_NEG
        if(~wdual_i && rd_addr_i == 4)
            acc2 <= wd_data_i;            
        if(wdual_i)
            acc2 <= wd_data_i;
    end

    always_comb begin : OUTPUT
        regs_read = '{regs[0], regs[1], acc1, 0, acc2};

        rs_data_o = regs_read[rs_addr_i];
        rd_data_o = regs_read[rd_addr_i]; 
        // ACC outputs fixed
        acc1_o = acc1;
        acc2_o = acc2;
    end

endmodule
