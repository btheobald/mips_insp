module core (
	clk_i,
	n_rst_i,
	ext_data_i,
	ext_int_i,
	result_o,
	halt_o
);
	input wire clk_i;
	input wire n_rst_i;
	localparam pico_N = 8;
	input wire [7:0] ext_data_i;
	input wire ext_int_i;
	output wire signed [7:0] result_o;
	output wire halt_o;
	wire [1:0] mode_pc;
	wire [3:0] flags_alu;
	wire [2:0] func_alu;
	wire a_imm_alu;
	localparam pico_W_OPCODE = 6;
	wire [5:0] op_code;
	wire wr_en_rf;
	wire wfi_core;
	wire edge_trig;
	edge_detect ed0(
		.clk_i(clk_i),
		.sig_i(ext_int_i),
		.edge_o(edge_trig)
	);
	dec dec0(
		.mode_pc_o(mode_pc),
		.op_code_i(op_code),
		.wr_en_rf_o(wr_en_rf),
		.a_imm_alu_o(a_imm_alu),
		.func_alu_o(func_alu),
		.flags_alu_i(flags_alu),
		.halt_core_o(halt_o),
		.wfi_core_o(wfi_core),
		.ext_int_i(edge_trig)
	);
	localparam pico_A = 10;
	wire [9:0] addr_pc;
	localparam pico_W_INST = 24;
	wire [23:0] instruction;
	localparam pico_W_RADDR = 5;
	wire [4:0] rd_addr;
	wire [4:0] rs_addr;
	localparam pico_W_IMM = 8;
	wire signed [7:0] immediate;
	assign immediate = instruction[0+:pico_W_IMM];
	assign rs_addr = instruction[pico_W_IMM+:pico_W_RADDR];
	assign rd_addr = instruction[13+:pico_W_RADDR];
	function automatic [5:0] sv2v_cast_93DB6;
		input reg [5:0] inp;
		sv2v_cast_93DB6 = inp;
	endfunction
	assign op_code = sv2v_cast_93DB6(instruction[18+:pico_W_OPCODE]);
	wire signed [7:0] rs_data;
	wire signed [7:0] rd_data;
	pc pc0(
		.clk_i(clk_i),
		.halt_i(halt_o || wfi_core),
		.n_rst_i(n_rst_i),
		.mode_i(mode_pc),
		.data_i(immediate),
		.addr_o(addr_pc)
	);
	rom rom0(
		.addr_i(addr_pc),
		.data_o(instruction)
	);
	rf rf0(
		.clk_i(clk_i),
		.wr_en_i(wr_en_rf),
		.ext_data_i(ext_data_i),
		.wd_data_i(result_o),
		.rs_addr_i(rs_addr),
		.rd_addr_i(rd_addr),
		.rs_data_o(rs_data),
		.rd_data_o(rd_data)
	);
	alu alu0(
		.a_i((a_imm_alu ? immediate : rd_data)),
		.b_i(rs_data),
		.op(func_alu),
		.r_o(result_o),
		.flags_o(flags_alu)
	);
	always @(posedge clk_i)
		$display("%x, %x, %x", addr_pc, instruction, result_o);
endmodule
