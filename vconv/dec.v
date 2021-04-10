module dec (
	mode_pc_o,
	op_code_i,
	wr_en_rf_o,
	a_imm_alu_o,
	func_alu_o,
	flags_alu_i,
	halt_core_o,
	wfi_core_o,
	ext_int_i
);
	output reg [1:0] mode_pc_o;
	localparam pico_W_OPCODE = 6;
	input wire [5:0] op_code_i;
	output reg wr_en_rf_o;
	output reg a_imm_alu_o;
	output reg [2:0] func_alu_o;
	input wire [3:0] flags_alu_i;
	output reg halt_core_o;
	output reg wfi_core_o;
	input wire ext_int_i;
	localparam [2:0] pico_F_SUB = 3'h2;
	localparam [1:0] pico_INCREMENT = 2'h1;
	localparam [5:0] pico_O_ADD = 6'h01;
	localparam [5:0] pico_O_ADDI = 6'h11;
	localparam [5:0] pico_O_AND = 6'h04;
	localparam [5:0] pico_O_ANDI = 6'h14;
	localparam [5:0] pico_O_BEQ = 6'h08;
	localparam [5:0] pico_O_BNE = 6'h09;
	localparam [5:0] pico_O_HALT = 6'h00;
	localparam [5:0] pico_O_JSBR = 6'h30;
	localparam [5:0] pico_O_MUL = 6'h03;
	localparam [5:0] pico_O_MULI = 6'h13;
	localparam [5:0] pico_O_NOT = 6'h07;
	localparam [5:0] pico_O_NOTI = 6'h17;
	localparam [5:0] pico_O_OR = 6'h05;
	localparam [5:0] pico_O_ORI = 6'h15;
	localparam [5:0] pico_O_RSBR = 6'h31;
	localparam [5:0] pico_O_SUB = 6'h02;
	localparam [5:0] pico_O_SUBI = 6'h12;
	localparam [5:0] pico_O_WFI = 6'h3f;
	localparam [5:0] pico_O_XOR = 6'h06;
	localparam [5:0] pico_O_XORI = 6'h16;
	localparam [1:0] pico_RELATIVE = 2'h2;
	localparam [1:0] pico_RETURN = 2'h0;
	localparam [1:0] pico_SUBROUTINE = 2'h3;
	function automatic [2:0] sv2v_cast_3;
		input reg [2:0] inp;
		sv2v_cast_3 = inp;
	endfunction
	always @(*) begin
		mode_pc_o = pico_RETURN;
		wr_en_rf_o = 1'b0;
		a_imm_alu_o = 1'b0;
		func_alu_o = sv2v_cast_3((op_code_i[3] ? pico_F_SUB : op_code_i[2:0]));
		halt_core_o = 1'b0;
		a_imm_alu_o = op_code_i[4];
		case (op_code_i)
			pico_O_ADD, pico_O_ADDI, pico_O_SUB, pico_O_SUBI, pico_O_MUL, pico_O_MULI, pico_O_AND, pico_O_ANDI, pico_O_OR, pico_O_ORI, pico_O_XOR, pico_O_XORI, pico_O_NOT, pico_O_NOTI: begin
				mode_pc_o = pico_INCREMENT;
				wr_en_rf_o = 1'b1;
			end
			pico_O_BEQ: mode_pc_o = (flags_alu_i[3] ? pico_RELATIVE : pico_INCREMENT);
			pico_O_BNE: mode_pc_o = (~flags_alu_i[3] ? pico_RELATIVE : pico_INCREMENT);
			pico_O_HALT: halt_core_o = 1'b1;
			pico_O_JSBR: mode_pc_o = pico_SUBROUTINE;
			pico_O_RSBR: mode_pc_o = pico_RETURN;
			pico_O_WFI: begin
				mode_pc_o = pico_INCREMENT;
				wfi_core_o = ~ext_int_i;
			end
			default: begin
				halt_core_o = 1'b1;
				//$error("Unimplemented Opcode %h", op_code_i);
			end
		endcase
	end
endmodule
