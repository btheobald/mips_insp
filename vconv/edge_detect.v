module edge_detect (
	clk_i,
	sig_i,
	edge_o
);
	input wire clk_i;
	input wire sig_i;
	output wire edge_o;
	reg [2:0] stages;
	assign edge_o = (stages[2] & ~stages[1]) | (~stages[2] & stages[1]);
	always @(posedge clk_i) begin
		stages[0] <= sig_i;
		stages[1] <= stages[0];
		stages[2] <= stages[1];
	end
endmodule
