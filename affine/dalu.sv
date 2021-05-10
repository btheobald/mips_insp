module dalu import affine::*;
   (input  logic [N-1:0] a,
    input  logic [N-1:0] b,
    input  logic [N-1:0] c,
    input  logic [N-1:0] d,
    input  logic [N-1:0] acc1_i,
    input  logic [N-1:0] acc2_i,
    output logic [N-1:0] r1,
	 output logic [N-1:0] r2,

    // Control
    input tOP ctrl);

    logic signed [7:0] mul1_a, mul1_b, mul1_rs;
    logic signed [15:0] mul1_r;
    always_comb begin : MUL1_SEL
        casex(ctrl.mul_a_sel)
		   2'b00 : mul1_a = 0;
           2'b01 : mul1_a = 1;
           2'b1x : mul1_a = a;
		endcase
        mul1_b = (ctrl.mul_a_sel == 2'b11) ? b : c;
    end : MUL1_SEL

    logic signed [7:0] mul2_a, mul2_b, mul2_rs;
    logic signed [15:0] mul2_r;
    always_comb begin : MUL2_SEL
        casex(ctrl.mul_a_sel)
           2'b00 : mul2_a = 0;
		   2'b01 : mul2_a = 1;
           2'b1x : mul2_a = b;
		  endcase
        mul2_b = d;
    end : MUL2_SEL

    always_comb begin : MUL
        mul1_r = mul1_a * mul1_b;
        mul2_r = mul2_a * mul2_b;
        mul1_rs = ctrl.frac_c ? mul1_r[14:7] : mul1_r[7:0];
        mul2_rs = ctrl.frac_c ? mul2_r[14:7] : mul2_r[7:0];
    end : MUL

    logic signed [7:0] add1_a, add1_b;
    always_comb begin : ADD1_SEL
        add1_a = mul1_rs;
		  casex(ctrl.add_b_sel)
           2'b00 : add1_b = 0;       // Multiplier Mode
		   2'b01 : add1_b = acc1_i;  // Accumulator Mode
           2'b1x : add1_b = mul2_rs; // Adder Mode
		  endcase
    end : ADD1_SEL

    logic signed [7:0] add2_a, add2_b;
    always_comb begin : ADD2_SEL 
        add2_a = mul2_rs;
        casex(ctrl.add_b_sel)
           2'bx0 : add2_b = 0;       // Multiplier Mode
		   2'bx1 : add2_b = acc2_i;  // Accumulator Mode
		  endcase
    end : ADD2_SEL

    assign r1 = add1_a + add1_b;
	assign r2 = add2_a + add2_b;

endmodule
