module rf (
	clk_i,
	wr_en_i,
	ext_data_i,
	wd_data_i,
	rs_addr_i,
	rd_addr_i,
	rs_data_o,
	rd_data_o
);
	input wire clk_i;
	input wire wr_en_i;
	localparam pico_N = 8;
	input wire [7:0] ext_data_i;
	input wire signed [7:0] wd_data_i;
	localparam pico_R = 32;
	input wire [4:0] rs_addr_i;
	input wire [4:0] rd_addr_i;
	output reg signed [7:0] rs_data_o;
	output reg signed [7:0] rd_data_o;
	reg signed [7:0] regs [0:31];
	always @(posedge clk_i) begin : REGISTER
		regs[0] <= 8'd0;
		regs[30] <= ext_data_i;
		if ((wr_en_i & (rd_addr_i != 0)) & (rd_addr_i != 30))
			regs[rd_addr_i] <= wd_data_i;
	end
	always @(*) begin : OUTPUT
		rs_data_o = regs[rs_addr_i];
		rd_data_o = regs[rd_addr_i];
	end
endmodule
