module rf import pico::*; 
    (input logic clk_i, 
     input logic wr_en_i,
     input logic [N-1:0] ext_data_i,
     input logic signed [N-1:0] wd_data_i,
     input logic [$clog2(R)-1:0] rs_addr_i,
     input logic [$clog2(R)-1:0] rd_addr_i,
     output logic signed [N-1:0] rs_data_o, 
     output logic signed [N-1:0] rd_data_o);
    
    logic signed [N-1:0] regs [0:R-1];

    always_ff @(posedge clk_i) begin : REGISTER
        regs[0] <= 8'd0;
        regs[30] <= ext_data_i;
        if(wr_en_i & rd_addr_i != 0 & rd_addr_i != 30) begin
            regs[rd_addr_i] <= wd_data_i;
        end
    end

    always_comb begin : OUTPUT       
        rs_data_o = regs[rs_addr_i];
        rd_data_o = regs[rd_addr_i]; 
    end

endmodule