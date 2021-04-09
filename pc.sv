module pc import pico::*; 
    (input logic clk_i, 
     input logic n_rst_i,
     input modePC mode_i,
     input logic signed [N-1:0] data_i,
     output logic [A-1:0] addr_o);

    always_ff @(posedge clk_i, negedge n_rst_i) begin
        if(~n_rst_i)
            addr_o <= '0;
        else begin
            unique case(mode_i)
                INCREMENT: addr_o <= addr_o + 1'd1;
                RELATIVE:  addr_o <= addr_o + A'(data_i);
                ABSOLUTE:  addr_o <= A'(data_i);
                HALTCOUNT: addr_o <= addr_o;
            endcase
        end
    end

endmodule
