module picoMIPS4test import pico::*;
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
logic slow_clk;

// Program Memory Interconnect
logic [A-1:0] prog_addr;
logic [W_INST-1:0] prog_data;


//=======================================================
//  Structural coding
//=======================================================

counter (.fastclk(CLOCK_50), .clk(slow_clk));
rom rom0 (.refresh_clk(CLOCK_50), .addr_i(prog_addr), .data_o(prog_data));
core c0 (.clk_i(SW[9] ? KEY[0] : slow_clk), .n_rst_i(KEY[1]), .prog_addr(prog_addr), .prog_data(prog_data), .ext_data_i(input_display), .ext_int_i(SW[8]), .result_o(result_display), .halt_o(LEDR[9]), .wfi_o(LEDR[8]));
assign input_display = SW[7:0];
assign LEDR[7:0] = result_display;

sseg s0 (result_display[3:0],HEX0);
sseg s1 (result_display[7:4],HEX1);
sseg s2 (input_display[3:0],HEX2);
sseg s3 (input_display[7:4],HEX3);
sseg s4 (prog_addr[3:0],HEX4);
//sseg s5 (prog_addr[7:4],HEX5);
sseg s5 (4'h0,HEX5);


endmodule
