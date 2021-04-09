module rf import pico::*; 
    (input logic clk_i, 
     input logic wr_en_i,
     input logic signed [N-1:0] wd_data_i,
     input logic [$clog2(R)-1:0] rs_addr_i,
     input logic [$clog2(R)-1:0] rd_addr_i,
     output logic signed [N-1:0] rs_data_o, 
     output logic signed [N-1:0] rd_data_o);
    
    logic signed [N-1:0] regs [1:R-1];
    logic signed [N-1:0] regs_rd [0:R-1];

    always_ff @(posedge clk_i) begin : REGISTER
        if(wr_en_i & rd_addr_i != 0) begin
            regs[rd_addr_i] <= wd_data_i;
        end
    end

    always_comb begin : OUTPUT       
        regs_rd[0] = 8'd0;
        regs_rd[1:R-1] = regs;
        rs_data_o = regs_rd[rs_addr_i];
        rd_data_o = regs_rd[rd_addr_i]; 
    end

endmodule