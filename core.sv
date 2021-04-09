module core import pico::*;
    (input logic clk_i, 
     input logic n_rst_i,
     input logic signed ext_data_i,
     output logic signed [N-1:0] result_o,
     output logic halt_o);

    // Control Signals
    modePC mode_pc;
    flagsALU flags_alu;
    funcALU func_alu;
    logic a_imm_alu;
    opCode op_code;
    logic wr_en_rf;

    dec dec0 (.mode_pc_o(mode_pc), .op_code_i(op_code), .wr_en_rf_o(wr_en_rf), .a_imm_alu_o(a_imm_alu), .func_alu_o(func_alu), .flags_alu_i(flags_alu), .halt_core_o(halt_o));

    // Datapath
    logic [A-1:0] addr_pc;
    logic [W_INST-1:0] instruction;
    logic [W_RADDR-1:0] rd_addr, rs_addr;
    logic signed [W_IMM-1:0] immediate;

    // Calculate instruction offsets to generate signals
    assign immediate = instruction[0               +: W_IMM];
    assign rs_addr   = instruction[W_IMM           +: W_RADDR];
    assign rd_addr   = instruction[W_IMM+W_RADDR   +: W_RADDR];
    assign op_code   = opCode'(instruction[W_IMM+2*W_RADDR +: W_OPCODE]);    

    logic signed [N-1:0] rs_data, rd_data;

    pc  pc0  (.clk_i(clk_i), .n_rst_i(n_rst_i), .mode_i(mode_pc), .data_i(immediate), .addr_o(addr_pc));
    rom rom0 (.addr_i(addr_pc), .data_o(instruction));
    rf  rf0  (.clk_i(clk_i), .wr_en_i(wr_en_rf), .wd_data_i(result_o), .rs_addr_i(rs_addr), .rd_addr_i(rd_addr), .rs_data_o(rs_data), .rd_data_o(rd_data));
    alu alu0 (.a_i(a_imm_alu ? immediate : rd_data), .b_i(rs_data), .op(func_alu), .r_o(result_o), .flags_o(flags_alu));

    always_ff @(posedge clk_i) begin        
        $display("%x, %x, %x", addr_pc, instruction, result_o);
    end

endmodule