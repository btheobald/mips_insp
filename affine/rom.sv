module rom import affine::*;
    (input logic [A-1:0] addr_i,
    output logic [W_INST-1:0] data_o,
	 input logic refresh_clk);
	 
    reg [W_INST-1:0] rom [0:(1<<A)-1]; 
   
    // Dataset 1
    assign rom[0] = 28'h14014EC; // dseti (b1), (b2)		  - Dual Set Immediate
    assign rom[1] = 28'h3904060; // dfmac r0, (a21), (a22) - Dual Fractional Multiply Accumulate
    assign rom[2] = 28'h39560C0; // dfmac r1, (a11), (a21) - Dual Fractional Multiply Accumulate
    // Dataset 2
    //assign rom[0] = 28'h640050C; // dseti (b1), (b2)		  - Dual Set Immediate
    //assign rom[1] = 28'hC009060; // dfmac r0, (a21), (a22) - Dual Fractional Multiply Accumulate
    //assign rom[2] = 28'hC094090; // dfmac r1, (a11), (a21) - Dual Fractional Multiply Accumulate
    assign rom[3] = 28'h0840100; // set r1, r0		  - Set Register
    
    assign data_o = rom[addr_i];
  
endmodule
