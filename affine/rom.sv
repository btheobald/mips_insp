module rom import affine::*;
    (input logic [A-1:0] addr_i,
    output logic [W_INST-1:0] data_o,
	 input logic refresh_clk);
	 
    reg [W_INST-1:0] rom [0:(1<<A)-1]; 
   
    assign rom[0] = 28'h64014EC; // dseti (b1), (b2)		  - Dual Set Immediate
    assign rom[1] = 28'hC004060; // dfmac r0, (a21), (a22) - Dual Fractional Multiply Accumulate
    assign rom[2] = 28'hC0960C0; // dfmac r1, (a11), (a21) - Dual Fractional Multiply Accumulate
    assign rom[3] = 28'h0480100; // addi  r1, r0, (0)		  - Add Immediate
    
    assign data_o = rom[addr_i];
  
endmodule
