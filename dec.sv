module dec import pico::*; 
    (output modePC mode_pc_o,
     input opCode op_code_i,
     output logic wr_en_rf_o,
     output logic a_imm_alu_o,
     output funcALU func_alu_o,
     input flagsALU flags_alu_i,
     output logic halt_core_o );

    always_comb begin
        mode_pc_o = INCREMENT;
        wr_en_rf_o = 1'b0;
        a_imm_alu_o = 1'b0;
        func_alu_o = op_code_i[3] ? F_SUB : op_code_i[2:0];
        halt_core_o = 1'b0;
        a_imm_alu_o = op_code_i[4]; // Check for Immediate bit

        unique case (op_code_i)
            O_ADD, O_ADDI, 
            O_SUB, O_SUBI, 
            O_MUL, O_MULI, 
            O_AND, O_ANDI, 
            O_OR,  O_ORI, 
            O_XOR, O_XORI, 
            O_NOT, O_NOTI: begin
                mode_pc_o = INCREMENT;
                wr_en_rf_o = 1'b1;
            end
            O_BEQ: begin
                mode_pc_o = flags_alu_i.Zero ? RELATIVE : INCREMENT;
            end
            O_BNE: begin
                mode_pc_o = ~flags_alu_i.Zero ? RELATIVE : INCREMENT;
            end
            O_HALT: begin
                mode_pc_o = HALTCOUNT;
                wr_en_rf_o = 1'b0;
                halt_core_o = 1'b1;
            end
            default: begin
                mode_pc_o = HALTCOUNT;
                halt_core_o = 1'b1;
                $error("Unimplemented Opcode %h", op_code_i);
            end
        endcase
    end

endmodule