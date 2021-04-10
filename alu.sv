module alu import pico::*; 
    (input logic signed [N-1:0] a_i,
     input logic signed  [N-1:0] b_i,
     input funcALU op,
     output logic signed [N-1:0] r_o,
     output flagsALU flags_o);

    logic signed sub;
    logic signed [N+1:0] tmp;
    logic signed [N:0] r_as;
    always_comb begin
        sub = (op == F_SUB);
		  //tmp = sub ? - b_i : b_i;
        //r_as = a_i + tmp;
		  //r_as = sub ? (a_i - b_i) : (a_i + b_i);
        // Altera Cookbook Example 'XOR in front of Carry Chain'
        tmp = {1'b0, a_i, sub} + {sub, {N{sub}} ^ b_i, sub};
        r_as = tmp[N+1:1];
    end

    always_comb begin
        if(sub) begin
            flags_o.Carry = (a_i[7] & ~b_i[7]) | (a_i[7] & r_as[7]) | (~b_i[7] & r_as[7]);
            flags_o.Overflow = (~a_i[7] & b_i[7] & ~r_as[7]) | (a_i[7] & ~b_i[7] & r_as[7]);
        end else begin // add
            flags_o.Carry = (a_i[7] & b_i[7]) | (a_i[7] & ~r_as[7]) | (b_i[7] & ~r_as[7]);
            flags_o.Overflow = (a_i[7] & b_i[7] & ~r_as[7]) | (~a_i[7] & ~b_i[7] & r_as[7]);
        end
        flags_o.Zero = ~|r_as;
        flags_o.Negative = r_as[N-1];
    end

    always_comb begin
        unique case(op)
            F_ADD, 
            F_SUB: r_o = r_as[N-1:0];
            F_MUL: r_o = a_i * b_i;
            F_AND: r_o = a_i & b_i;
            F_OR:  r_o = a_i | b_i;
            F_XOR: r_o = a_i ^ b_i;
            F_NOT: r_o = ~ a_i;
            F_A:   r_o = a_i;
            default: r_o = 'd0;
        endcase
    end

endmodule