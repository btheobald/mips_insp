module rom import pico::*;
    (input logic refresh_clk,
	 input logic [A-1:0] addr_i,
    output logic [W_INST-1:0] data_o);

	 
    (* ram_init_file = "prog_test.mif" *) reg [W_INST-1:0] rom [0:(1<<A)-1];
	 
	 // Initialise Altera Sync RAM and JTAG Interface
	 logic [A-1:0] scan_addr;
	 logic [W_INST-1:0] scan_data;
	 alt_rom ar0 (scan_addr, refresh_clk, scan_data);
	 
	 // Constantly update contents from Sync RAM
	 always_ff @(posedge refresh_clk) begin
		rom[scan_addr-1] <= scan_data;
		scan_addr <= scan_addr + 1;
	 end
	 
    //initial $readmemh("prog.hex", rom);
    
    assign data_o = rom[addr_i];
  
endmodule