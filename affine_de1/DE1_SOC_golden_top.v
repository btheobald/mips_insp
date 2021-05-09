module picoMIPS4test import affine::*;
 (input logic CLOCK_50,  // 50MHz Altera DE0 clock
  input logic [9:0] SW, // Switches SW0..SW9
  input logic [3:0] KEY, // Keys KEY0..KEY4
  output logic [9:0] LEDR,
  output logic [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5); // LEDs


//=======================================================
//  REG/WIRE declarations
//=======================================================
logic [7:0] result_display;
logic [7:0] input_display;
logic slow_clk, halt_r;
logic [1:0] prog_addr;

//=======================================================
//  Structural coding
//=======================================================

counter ctr (.fastclk(CLOCK_50), .clk(slow_clk));

core core0 (.clk_i(slow_clk), .n_rst_i(KEY[0]), .ext_data_i(input_display), .ext_data_o(result_display), .prog_addr_o(prog_addr));
assign input_display = SW[7:0];
assign LEDR[7:0] = result_display;

sseg s0 (result_display[3:0],HEX0);
sseg s1 (result_display[7:4],HEX1);
sseg s2 (input_display[3:0],HEX2);
sseg s3 (input_display[7:4],HEX3);
sseg s4 ({2'b00, prog_addr[1:0]},HEX4);
sseg s5 (4'h0,HEX5);


endmodule
