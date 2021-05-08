module ddralu import affine::*;
   (input  logic [N-1:0] a,
    input  logic [N-1:0] b,
    input  logic [N-1:0] c,
    input  logic [N-1:0] d,
    input  logic [N-1:0] acc1_i,
    input  logic [N-1:0] acc2_i,
    output logic [N-1:0] r,
    
    // Control
    input tOP ctrl,
    
    // Clock used for reference
    input logic clock_pol
);

    logic signed [7:0] mul1_a, mul1_b, mul1_r;
    always_comb begin : MUL1_SEL
        if(ctrl.mul_a_sel[0] == 0)
            mul1_a = a;
        if(ctrl.mul_a_sel[0] == 1)
            mul1_a = 0;
        if(ctrl.mul_a_sel[1] == 1)
            mul1_a = 1;
        mul1_b = c;
    end : MUL1_SEL

    logic signed [7:0] mul2_a, mul2_b, mul2_r;
    always_comb begin : MUL2_SEL
        if(ctrl.mul_a_sel[0] == 0)
            mul2_b = b;
        if(ctrl.mul_a_sel[0] == 1)
            mul2_b = 0;
        if(ctrl.mul_a_sel[1] == 1)
            mul2_b = 1;
        mul2_b = d;
    end : MUL2_SEL

    always_comb begin : MUL
        mul1_r = mul1_a * mul1_b;
        mul2_r = mul2_a * mul2_b;
    end : MUL

    always_comb begin : ADD1_SEL
        add1_a = mul1_r;
        if(ctrl.add_b_sel[0] == 0)
            add1_b = acc1_i; // Accumulator Mode
        if(ctrl.add_b_sel[0] == 1)
            add1_b = 0;      // Multiplier Mode
        if(ctrl.add_b_sel[1] == 1)
            add1_b = mul2_r; // Adder Mode
    end : ADD1_SEL

    always_comb begin : ADD2_SEL
        add2_a = mul2_r;
        if(ctrl.add_b_sel[0] == 0)
            add2_b = acc2_i; // Accumulator Mode
        if(ctrl.add_b_sel[0] == 1)
            add2_b = 0;      // Multiplier Mode
        if(ctrl.add_b_sel[1] == 1)
            add2_b = mul1_r; // Adder Mode
    end : ADD2_SEL

    logic signed [7:0] add1_a, add1_b;
    logic signed [7:0] add2_a, add2_b;
    logic signed [7:0] add_a, add_b;
    always_comb begin : ADD
        if(clock_pol) begin
            add_a = add1_a;
            add_b = add1_b;
        end else begin
            add_a = add2_a;
            add_b = add2_b;
        end
    end : ADD
    
    assign r = add_a + add_b;

endmodule
