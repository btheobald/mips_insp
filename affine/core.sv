module core import affine::*;
   (input logic clk_i,
    input logic n_rst_i,
    input logic [N-1:0] ext_data_i,
    output logic [N-1:0] ext_data_o,
    output logic [1:0] prog_addr_o,
	 output logic halt_o);
/* verilator lint_off UNOPTFLAT */
    logic clk_h, halt_r, halt_flag;
/* verilator lint_on UNOPTFLAT */
    assign clk_h = (halt_r || ~n_rst_i) ? 0 : clk_i;
    always_ff @(posedge clk_h, negedge n_rst_i) begin
        if(~n_rst_i)
            halt_r <= 0;
        else if (halt_flag)
            halt_r <= 1;
    end
    
    logic [A-1:0] pc_addr;
    pc c0 (.clk_i(clk_h), .n_rst_i(n_rst_i), .addr_o(pc_addr));
    assign halt_flag = &pc_addr; // Halt if next cycle overflows
    assign halt_o = halt_r;
	 assign prog_addr_o = pc_addr;
	 
    logic [W_INST-1:0] rom_data;
    logic [1:0] rs_addr, rd_addr;
    logic [N-1:0] imm1_data, imm2_data;
    tOP alu_op;
    rom r0 (.addr_i(pc_addr), .data_o(rom_data));

    always_comb begin // Instruction Format
        alu_op.frac_c    = rom_data[25];
		alu_op.wdual     = rom_data[24];
		alu_op.mul_a_sel = rom_data[23:22];
		alu_op.add_b_sel = rom_data[21:20];
        rd_addr          = rom_data[19:18];
        rs_addr   		 = rom_data[17:16];
        imm1_data 		 = rom_data[15:8];
        imm2_data 		 = rom_data[7:0];
    end

    logic [N-1:0] wd_data, rs_data, rd_data, acc1_data, acc2_data, acc2_fb;

    rf f0 (.clk_i(clk_h), .wdual_i(alu_op.wdual), .ext_data_i(ext_data_i), .wd_data_i(wd_data), .rs_addr_i(rs_addr), .rd_addr_i(rd_addr), .rs_data_o(rs_data), .rd_data_o(rd_data), .acc2_i(acc2_fb), .acc1_o(acc1_data), .acc2_o(acc2_data));

    dalu a0 (.a(rs_data), .b(rd_data), .c(imm1_data), .d(imm2_data), .acc1_i(acc1_data), .acc2_i(acc2_data), .r1(wd_data), .r2(acc2_fb), .ctrl(alu_op));

    assign ext_data_o = n_rst_i ? acc1_data : acc2_data;

endmodule
