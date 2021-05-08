module core import affine::*;
   (input logic clk_i, 
    input logic n_rst_i,
    input logic [N-1:0] ext_data_i,
    output logic [N-1:0] ext_data_o);

    logic clk_h, halt_r, halt_flag;
    assign clk_h = halt_r ? 0 : clk_i;
    always_ff @(posedge clk_i, negedge n_rst_i) begin
        if(~n_rst_i)
            halt_r <= 0;
        else if (halt_flag);
            halt_r <= 1;
    end
    
    logic [A-1:0] pc_addr;
    pc c0 (.clk_i(clk_i), .n_rst_i(n_rst_i), .addr_o(pc_addr));

    logic [W_INST-1:0] rom_data;
    logic [2:0] rs_addr, rd_addr;
    logic [N-1:0] imm1_data, imm2_data;
    tOP alu_op;
    rom r0 (.addr_i(pc_addr), .data_o(rom_data));

    always_comb begin
        alu_op    = tOP'(rom_data[                  0 +: W_OP]);
        rs_addr   =      rom_data[               W_OP +: W_RS];
        rd_addr   =      rom_data[          W_OP+W_RS +: W_RD];
        imm1_data =      rom_data[     W_OP+W_RS+W_RD +: W_I1];
        imm2_data =      rom_data[W_OP+W_RS+W_RD+W_I1 +: W_I2];
    end

    assign halt_flag = alu_op.halt;

    logic wdual;
    logic [N-1:0] wd_data, rs_data, rd_data, acc1_data, acc2_data;

    rf f0 (.clk_i(clk_i), .wdual_i(wdual), .ext_data_i(ext_data_i), .wd_data_i(wd_data), .rs_addr_i(rs_addr), .rd_addr_i(rd_addr), .rs_data_o(rs_data), .rd_data_o(rd_data), .acc1_o(acc1_data), .acc2_o(acc2_data));

    ddralu a0 (.a(rs_data), .b(rd_data), .c(imm1_data), .d(imm2_data), .acc1_i(acc1_data), .acc2_i(acc2_data), .r(wd_data), .ctrl(alu_op), .clock_pol(clk_h));

    assign ext_data_o = n_rst_i ? acc1_data : acc2_data;

endmodule
