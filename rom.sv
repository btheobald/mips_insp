module rom import pico::*;
    (input logic [A-1:0] addr_i,
    output logic [W_INST-1:0] data_o);

    logic [W_INST-1:0] rom [0:(1<<A)-1];

    initial $readmemh("prog.hex", rom);
    
    assign data_o = rom[addr_i];
  
endmodule