module pc (
	clk_i,
	halt_i,
	n_rst_i,
	mode_i,
	data_i,
	addr_o
);
	input wire clk_i;
	input wire halt_i;
	input wire n_rst_i;
	input wire [1:0] mode_i;
	localparam pico_N = 8;
	input wire signed [7:0] data_i;
	localparam pico_A = 10;
	output reg [9:0] addr_o;
	reg [9:0] rtn_addr;
	localparam [1:0] pico_INCREMENT = 2'h1;
	localparam [1:0] pico_RELATIVE = 2'h2;
	localparam [1:0] pico_RETURN = 2'h0;
	localparam [1:0] pico_SUBROUTINE = 2'h3;
	function automatic signed [9:0] sv2v_cast_10_signed;
		input reg signed [9:0] inp;
		sv2v_cast_10_signed = inp;
	endfunction
	always @(posedge clk_i or negedge n_rst_i)
		if (~n_rst_i) begin
			addr_o <= {10 {1'sb0}};
			rtn_addr <= {10 {1'sb0}};
		end
		else if (~halt_i)
			case (mode_i)
				pico_INCREMENT: addr_o <= addr_o + 1'd1;
				pico_RELATIVE: addr_o <= addr_o + sv2v_cast_10_signed(data_i);
				pico_SUBROUTINE: begin
					rtn_addr <= addr_o + 1'd1;
					addr_o <= sv2v_cast_10_signed(data_i);
				end
				pico_RETURN: begin
					addr_o <= rtn_addr;
					rtn_addr <= {10 {1'sb0}};
				end
			endcase
		else
			addr_o <= addr_o;
endmodule
