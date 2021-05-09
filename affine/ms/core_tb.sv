`timescale 1ns/10ps

module core_tb;
   logic clk_i, pclk_i, n_rst_i;
   logic [7:0] ext_data_i, ext_data_o;
   logic [1:0] prog_addr_o;
   logic halt_o;

   core c0 (.*);

   initial begin
     #5ns pclk_i = 0;
     forever begin
	  #10ns pclk_i = 1;
       #10ns pclk_i = 0;
     end
   end

   always begin
     #10ns clk_i = 0;
     #10ns clk_i = 1;
   end

   initial begin
     #10ns n_rst_i = 1;
     #10ns n_rst_i = 0;
     ext_data_i = 4;
     #10ns n_rst_i = 1;

     #100ns n_rst_i = 1;
     #10ns n_rst_i = 0;
     ext_data_i = 2;
     #10ns n_rst_i = 1;

     #100ns $finish();
   end

endmodule
