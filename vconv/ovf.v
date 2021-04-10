module ovf (input a, input b, input r, input s, output v, output c);

    always @(*) begin
		if (s) begin
			c = ((a & ~b) | (a & r)) | (~b & r);
			v = ((~a & b) & ~r) | ((a & ~b) & r);
		end
		else begin
			c = ((a & b) | (a & ~r)) | (b & ~r);
			v = ((a & b) & ~r) | ((~a & ~b) & r);
		end

	end

endmodule
