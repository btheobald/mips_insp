module rom (
	addr_i,
	data_o
);
	localparam pico_A = 10;
	input wire [9:0] addr_i;
	localparam pico_W_INST = 24;
	output wire [23:0] data_o;
	wire [23:0] rom [0:1023];
	//initial $readmemh("prog.hex", rom);
	assign data_o = rom[addr_i];
endmodule
