module pc import affine::*; 
    (input logic clk_i, 
     input logic n_rst_i,
     output logic [A-1:0] addr_o);

    always_ff @(posedge clk_i, negedge n_rst_i) begin
        if(~n_rst_i) begin
            addr_o <= '0;
        end else begin
            addr_o <= addr_o + 1'd1;
        end
    end

endmodule
