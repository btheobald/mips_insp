// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcore__Syms.h"


//======================

void Vcore::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vcore::traceInit, &Vcore::traceFull, &Vcore::traceChg, this);
}
void Vcore::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vcore* t=(Vcore*)userthis;
    Vcore__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
	VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vcore::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcore* t=(Vcore*)userthis;
    Vcore__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vcore::traceInitThis(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vcore::traceFullThis(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcore::traceInitThis__1(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit(c+35,"clk_i",-1);
	vcdp->declBit(c+36,"n_rst_i",-1);
	vcdp->declBus(c+37,"ext_data_i",-1,7,0);
	vcdp->declBus(c+38,"ext_data_o",-1,7,0);
	vcdp->declBus(c+39,"prog_addr_o",-1,1,0);
	vcdp->declBit(c+40,"halt_o",-1);
	vcdp->declBit(c+35,"core clk_i",-1);
	vcdp->declBit(c+36,"core n_rst_i",-1);
	vcdp->declBus(c+37,"core ext_data_i",-1,7,0);
	vcdp->declBus(c+38,"core ext_data_o",-1,7,0);
	vcdp->declBus(c+39,"core prog_addr_o",-1,1,0);
	vcdp->declBit(c+40,"core halt_o",-1);
	vcdp->declBit(c+5,"core clk_h",-1);
	vcdp->declBit(c+26,"core halt_r",-1);
	vcdp->declBit(c+27,"core halt_flag",-1);
	vcdp->declBus(c+28,"core pc_addr",-1,1,0);
	vcdp->declBus(c+7,"core rom_data",-1,25,0);
	vcdp->declBus(c+8,"core rs_addr",-1,1,0);
	vcdp->declBus(c+9,"core rd_addr",-1,1,0);
	vcdp->declBus(c+10,"core imm1_data",-1,7,0);
	vcdp->declBus(c+11,"core imm2_data",-1,7,0);
	vcdp->declBus(c+12,"core alu_op",-1,5,0);
	vcdp->declBus(c+13,"core wd_data",-1,7,0);
	vcdp->declBus(c+6,"core rs_data",-1,7,0);
	vcdp->declBus(c+14,"core rd_data",-1,7,0);
	vcdp->declBus(c+29,"core acc1_data",-1,7,0);
	vcdp->declBus(c+30,"core acc2_data",-1,7,0);
	vcdp->declBus(c+15,"core acc2_fb",-1,7,0);
	vcdp->declBit(c+5,"core c0 clk_i",-1);
	vcdp->declBit(c+36,"core c0 n_rst_i",-1);
	vcdp->declBus(c+28,"core c0 addr_o",-1,1,0);
	vcdp->declBus(c+28,"core r0 addr_i",-1,1,0);
	vcdp->declBus(c+7,"core r0 data_o",-1,25,0);
	vcdp->declBit(c+41,"core r0 refresh_clk",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus(c+1+i*1,"core r0 rom",(i+0),25,0);}}
	vcdp->declBit(c+5,"core f0 clk_i",-1);
	vcdp->declBit(c+16,"core f0 wdual_i",-1);
	vcdp->declBus(c+37,"core f0 ext_data_i",-1,7,0);
	vcdp->declBus(c+13,"core f0 wd_data_i",-1,7,0);
	vcdp->declBus(c+8,"core f0 rs_addr_i",-1,1,0);
	vcdp->declBus(c+9,"core f0 rd_addr_i",-1,1,0);
	vcdp->declBus(c+6,"core f0 rs_data_o",-1,7,0);
	vcdp->declBus(c+14,"core f0 rd_data_o",-1,7,0);
	vcdp->declBus(c+15,"core f0 acc2_i",-1,7,0);
	vcdp->declBus(c+29,"core f0 acc1_o",-1,7,0);
	vcdp->declBus(c+30,"core f0 acc2_o",-1,7,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus(c+31+i*1,"core f0 regs",(i+0),7,0);}}
	vcdp->declBus(c+6,"core a0 a",-1,7,0);
	vcdp->declBus(c+14,"core a0 b",-1,7,0);
	vcdp->declBus(c+10,"core a0 c",-1,7,0);
	vcdp->declBus(c+11,"core a0 d",-1,7,0);
	vcdp->declBus(c+29,"core a0 acc1_i",-1,7,0);
	vcdp->declBus(c+30,"core a0 acc2_i",-1,7,0);
	vcdp->declBus(c+13,"core a0 r1",-1,7,0);
	vcdp->declBus(c+15,"core a0 r2",-1,7,0);
	vcdp->declBus(c+12,"core a0 ctrl",-1,5,0);
	vcdp->declBus(c+17,"core a0 mul1_a",-1,7,0);
	vcdp->declBus(c+18,"core a0 mul1_b",-1,7,0);
	vcdp->declBus(c+19,"core a0 mul1_rs",-1,7,0);
	vcdp->declBus(c+20,"core a0 mul1_r",-1,15,0);
	vcdp->declBus(c+21,"core a0 mul2_a",-1,7,0);
	vcdp->declBus(c+11,"core a0 mul2_b",-1,7,0);
	vcdp->declBus(c+22,"core a0 mul2_rs",-1,7,0);
	vcdp->declBus(c+23,"core a0 mul2_r",-1,15,0);
	vcdp->declBus(c+19,"core a0 add1_a",-1,7,0);
	vcdp->declBus(c+24,"core a0 add1_b",-1,7,0);
	vcdp->declBus(c+22,"core a0 add2_a",-1,7,0);
	vcdp->declBus(c+25,"core a0 add2_b",-1,7,0);
	vcdp->declBus(c+42,"affine A",-1,31,0);
	vcdp->declBus(c+43,"affine N",-1,31,0);
	vcdp->declBus(c+44,"affine W_OP",-1,31,0);
	vcdp->declBus(c+43,"affine W_I2",-1,31,0);
	vcdp->declBus(c+43,"affine W_I1",-1,31,0);
	vcdp->declBus(c+42,"affine W_RD",-1,31,0);
	vcdp->declBus(c+42,"affine W_RS",-1,31,0);
	vcdp->declBus(c+45,"affine W_INST",-1,31,0);
    }
}

void Vcore::traceFullThis__1(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus(c+1,(vlTOPp->core__DOT__r0__DOT__rom[0]),26);
	vcdp->fullBus(c+2,(vlTOPp->core__DOT__r0__DOT__rom[1]),26);
	vcdp->fullBus(c+3,(vlTOPp->core__DOT__r0__DOT__rom[2]),26);
	vcdp->fullBus(c+4,(vlTOPp->core__DOT__r0__DOT__rom[3]),26);
	vcdp->fullBit(c+5,(vlTOPp->core__DOT__clk_h));
	vcdp->fullBus(c+6,(vlTOPp->core__DOT__f0__DOT__regs
			   [(3U & (vlTOPp->core__DOT__rom_data 
				   >> 0x10U))]),8);
	vcdp->fullBus(c+7,(vlTOPp->core__DOT__rom_data),26);
	vcdp->fullBus(c+8,((3U & (vlTOPp->core__DOT__rom_data 
				  >> 0x10U))),2);
	vcdp->fullBus(c+9,((3U & (vlTOPp->core__DOT__rom_data 
				  >> 0x12U))),2);
	vcdp->fullBus(c+10,((0xffU & (vlTOPp->core__DOT__rom_data 
				      >> 8U))),8);
	vcdp->fullBus(c+11,((0xffU & vlTOPp->core__DOT__rom_data)),8);
	vcdp->fullBus(c+12,(vlTOPp->core__DOT__alu_op),6);
	vcdp->fullBus(c+13,(vlTOPp->core__DOT__wd_data),8);
	vcdp->fullBus(c+14,(vlTOPp->core__DOT__rd_data),8);
	vcdp->fullBus(c+15,((0xffU & ((IData)(vlTOPp->core__DOT__a0__DOT__mul2_rs) 
				      + (IData)(vlTOPp->core__DOT__a0__DOT__add2_b)))),8);
	vcdp->fullBit(c+16,((1U & ((IData)(vlTOPp->core__DOT__alu_op) 
				   >> 4U))));
	vcdp->fullBus(c+17,(vlTOPp->core__DOT__a0__DOT__mul1_a),8);
	vcdp->fullBus(c+18,((0xffU & ((3U == (3U & 
					      ((IData)(vlTOPp->core__DOT__alu_op) 
					       >> 2U)))
				       ? (IData)(vlTOPp->core__DOT__rd_data)
				       : (vlTOPp->core__DOT__rom_data 
					  >> 8U)))),8);
	vcdp->fullBus(c+19,(vlTOPp->core__DOT__a0__DOT__mul1_rs),8);
	vcdp->fullBus(c+20,(vlTOPp->core__DOT__a0__DOT__mul1_r),16);
	vcdp->fullBus(c+21,(vlTOPp->core__DOT__a0__DOT__mul2_a),8);
	vcdp->fullBus(c+22,(vlTOPp->core__DOT__a0__DOT__mul2_rs),8);
	vcdp->fullBus(c+23,(vlTOPp->core__DOT__a0__DOT__mul2_r),16);
	vcdp->fullBus(c+24,(vlTOPp->core__DOT__a0__DOT__add1_b),8);
	vcdp->fullBus(c+25,(vlTOPp->core__DOT__a0__DOT__add2_b),8);
	vcdp->fullBit(c+26,(vlTOPp->core__DOT__halt_r));
	vcdp->fullBit(c+27,((3U == (IData)(vlTOPp->core__DOT__pc_addr))));
	vcdp->fullBus(c+28,(vlTOPp->core__DOT__pc_addr),2);
	vcdp->fullBus(c+29,(vlTOPp->core__DOT__f0__DOT__regs
			    [2U]),8);
	vcdp->fullBus(c+30,(vlTOPp->core__DOT__f0__DOT__regs
			    [3U]),8);
	vcdp->fullBus(c+31,(vlTOPp->core__DOT__f0__DOT__regs[0]),8);
	vcdp->fullBus(c+32,(vlTOPp->core__DOT__f0__DOT__regs[1]),8);
	vcdp->fullBus(c+33,(vlTOPp->core__DOT__f0__DOT__regs[2]),8);
	vcdp->fullBus(c+34,(vlTOPp->core__DOT__f0__DOT__regs[3]),8);
	vcdp->fullBit(c+35,(vlTOPp->clk_i));
	vcdp->fullBit(c+36,(vlTOPp->n_rst_i));
	vcdp->fullBus(c+37,(vlTOPp->ext_data_i),8);
	vcdp->fullBus(c+38,(vlTOPp->ext_data_o),8);
	vcdp->fullBus(c+39,(vlTOPp->prog_addr_o),2);
	vcdp->fullBit(c+40,(vlTOPp->halt_o));
	vcdp->fullBit(c+41,(vlTOPp->core__DOT__r0__DOT__refresh_clk));
	vcdp->fullBus(c+42,(2U),32);
	vcdp->fullBus(c+43,(8U),32);
	vcdp->fullBus(c+44,(6U),32);
	vcdp->fullBus(c+45,(0x1aU),32);
    }
}
