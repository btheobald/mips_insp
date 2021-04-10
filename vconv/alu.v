module alu (
	a_i,
	b_i,
	op,
	r_o,
	flags_o
);
	localparam pico_N = 8;
	input wire signed [7:0] a_i;
	input wire signed [7:0] b_i;
	input wire [2:0] op;
	output reg signed [7:0] r_o;
	output reg [3:0] flags_o;
	reg signed sub;
	wire signed [9:0] tmp;
	reg signed [pico_N:0] r_as;
	localparam [2:0] pico_F_SUB = 3'h2;
	always @(*) begin
		sub = op == pico_F_SUB;
		r_as = (sub ? a_i - b_i : a_i + b_i);
		flags_o[3] = ~|r_as;
		flags_o[2] = r_as[7];
	end

    ovf ov0 (a_i[7], b_i[7], r_as[7], sub, flags_o[1], flags_o[0]);

	localparam [2:0] pico_F_A = 3'h0;
	localparam [2:0] pico_F_ADD = 3'h1;
	localparam [2:0] pico_F_AND = 3'h4;
	localparam [2:0] pico_F_MUL = 3'h3;
	localparam [2:0] pico_F_NOT = 3'h7;
	localparam [2:0] pico_F_OR = 3'h5;
	localparam [2:0] pico_F_XOR = 3'h6;
	always @(*)
		case (op)
			pico_F_ADD, pico_F_SUB: r_o = r_as[7:0];
			pico_F_MUL: r_o = a_i * b_i;
			pico_F_AND: r_o = a_i & b_i;
			pico_F_OR: r_o = a_i | b_i;
			pico_F_XOR: r_o = a_i ^ b_i;
			pico_F_NOT: r_o = ~a_i;
			pico_F_A: r_o = a_i;
			default: r_o = 'd0;
		endcase
endmodule
