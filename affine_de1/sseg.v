module sseg(
	input logic [3:0] hexDigit,
	output logic [6:0] segments
	);
	
	logic [6:0] s;
		
	always_comb begin
		case(hexDigit)
			4'h0: s = 7'b0111111; 
			4'h1: s = 7'b0000110;
			4'h2: s = 7'b1011011;
			4'h3: s = 7'b1001111;
			4'h4: s = 7'b1100110;
			4'h5: s = 7'b1101101;
			4'h6: s = 7'b1111101;
			4'h7: s = 7'b0000111;
			4'h8: s = 7'b1111111;
			4'h9: s = 7'b1101111;
			4'hA: s = 7'b1110111;
			4'hB: s = 7'b1111100;
			4'hC: s = 7'b0111001;
			4'hD: s = 7'b1011110;
			4'hE: s = 7'b1111001;
			4'hF: s = 7'b1110001;
		endcase
		segments = ~s;
	end

	endmodule