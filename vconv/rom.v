module rom (
    clk_i,
	addr_i,
	data_o
);
    input wire clk_i;
	localparam pico_A = 10;
	input wire [9:0] addr_i;
	localparam pico_W_INST = 24;
	output wire [23:0] data_o;
	reg [23:0] rom [0:1023];
    //assign data_o = rom[addr_i];

    always @(posedge clk_i) begin
        data_o <= rom[addr_i];
    end
	
	initial $readmemh("prog.hex", rom);

endmodule
