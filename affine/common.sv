// Common Defines for ELEC6234 PicoMIPS Core
// Written by Byron Theobald - April 2021

package affine;

parameter A = 2;  // Memory Address Width
parameter N = 8;  // Data Bus Width

parameter W_OP = 6;
parameter W_I2 = 8;
parameter W_I1 = 8;
parameter W_RD = 3;
parameter W_RS = 3;
parameter W_INST = W_OP+W_I2+W_I1+W_RD+W_RS;

// ALU Control
typedef struct packed {
    logic frac_c;
	 logic wdual;	
	 logic [1:0] mul_a_sel;
    logic [1:0] add_b_sel;
} tOP;

endpackage

