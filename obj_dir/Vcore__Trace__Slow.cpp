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
	vcdp->declBit(c+82,"clk_i",-1);
	vcdp->declBit(c+83,"n_rst_i",-1);
	vcdp->declBit(c+84,"ext_data_i",-1);
	vcdp->declBus(c+85,"result_o",-1,7,0);
	vcdp->declBit(c+86,"halt_o",-1);
	vcdp->declBit(c+82,"core clk_i",-1);
	vcdp->declBit(c+83,"core n_rst_i",-1);
	vcdp->declBit(c+84,"core ext_data_i",-1);
	vcdp->declBus(c+85,"core result_o",-1,7,0);
	vcdp->declBit(c+86,"core halt_o",-1);
	vcdp->declBus(c+1,"core mode_pc",-1,1,0);
	vcdp->declBus(c+2,"core flags_alu",-1,3,0);
	vcdp->declBus(c+3,"core func_alu",-1,2,0);
	vcdp->declBit(c+4,"core a_imm_alu",-1);
	vcdp->declBus(c+5,"core op_code",-1,5,0);
	vcdp->declBit(c+6,"core wr_en_rf",-1);
	vcdp->declBus(c+81,"core addr_pc",-1,9,0);
	vcdp->declBus(c+7,"core instruction",-1,23,0);
	vcdp->declBus(c+8,"core rd_addr",-1,4,0);
	vcdp->declBus(c+9,"core rs_addr",-1,4,0);
	vcdp->declBus(c+10,"core immediate",-1,7,0);
	vcdp->declBus(c+11,"core rs_data",-1,7,0);
	vcdp->declBus(c+12,"core rd_data",-1,7,0);
	vcdp->declBus(c+13,"core alu_result_data",-1,7,0);
	vcdp->declBus(c+1,"core dec0 mode_pc_o",-1,1,0);
	vcdp->declBus(c+5,"core dec0 op_code_i",-1,5,0);
	vcdp->declBit(c+6,"core dec0 wr_en_rf_o",-1);
	vcdp->declBit(c+4,"core dec0 a_imm_alu_o",-1);
	vcdp->declBus(c+3,"core dec0 func_alu_o",-1,2,0);
	vcdp->declBus(c+2,"core dec0 flags_alu_i",-1,3,0);
	vcdp->declBit(c+86,"core dec0 halt_core_o",-1);
	vcdp->declBit(c+82,"core pc0 clk_i",-1);
	vcdp->declBit(c+83,"core pc0 n_rst_i",-1);
	vcdp->declBus(c+1,"core pc0 mode_i",-1,1,0);
	vcdp->declBus(c+10,"core pc0 data_i",-1,7,0);
	vcdp->declBus(c+81,"core pc0 addr_o",-1,9,0);
	vcdp->declBus(c+81,"core rom0 addr_i",-1,9,0);
	vcdp->declBus(c+7,"core rom0 data_o",-1,23,0);
	// Tracing: core rom0 rom // Ignored: Wide memory > --trace-max-array ents at rom.sv:5
	vcdp->declBit(c+82,"core rf0 clk_i",-1);
	vcdp->declBit(c+6,"core rf0 wr_en_i",-1);
	vcdp->declBus(c+13,"core rf0 wd_data_i",-1,7,0);
	vcdp->declBus(c+9,"core rf0 rs_addr_i",-1,4,0);
	vcdp->declBus(c+8,"core rf0 rd_addr_i",-1,4,0);
	vcdp->declBus(c+11,"core rf0 rs_data_o",-1,7,0);
	vcdp->declBus(c+12,"core rf0 rd_data_o",-1,7,0);
	{int i; for (i=0; i<31; i++) {
		vcdp->declBus(c+50+i*1,"core rf0 regs",(i+1),7,0);}}
	{int i; for (i=0; i<32; i++) {
		vcdp->declBus(c+14+i*1,"core rf0 regs_rd",(i+0),7,0);}}
	vcdp->declBus(c+46,"core alu0 a_i",-1,7,0);
	vcdp->declBus(c+11,"core alu0 b_i",-1,7,0);
	vcdp->declBus(c+3,"core alu0 op",-1,2,0);
	vcdp->declBus(c+13,"core alu0 r_o",-1,7,0);
	vcdp->declBus(c+2,"core alu0 flags_o",-1,3,0);
	vcdp->declBit(c+47,"core alu0 sub",-1);
	vcdp->declBus(c+48,"core alu0 tmp",-1,9,0);
	vcdp->declBus(c+49,"core alu0 r_as",-1,8,0);
	vcdp->declBus(c+87,"pico A",-1,31,0);
	vcdp->declBus(c+88,"pico N",-1,31,0);
	vcdp->declBus(c+89,"pico R",-1,31,0);
    }
}

void Vcore::traceFullThis__1(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus(c+1,(vlTOPp->core__DOT__mode_pc),2);
	vcdp->fullBus(c+2,(vlTOPp->core__DOT__flags_alu),4);
	vcdp->fullBus(c+3,(vlTOPp->core__DOT__func_alu),3);
	vcdp->fullBit(c+4,((1U & (vlTOPp->core__DOT__instruction 
				  >> 0x16U))));
	vcdp->fullBus(c+5,((0x3fU & (vlTOPp->core__DOT__instruction 
				     >> 0x12U))),6);
	vcdp->fullBit(c+6,(vlTOPp->core__DOT__wr_en_rf));
	vcdp->fullBus(c+7,(vlTOPp->core__DOT__instruction),24);
	vcdp->fullBus(c+8,((0x1fU & (vlTOPp->core__DOT__instruction 
				     >> 0xdU))),5);
	vcdp->fullBus(c+9,((0x1fU & (vlTOPp->core__DOT__instruction 
				     >> 8U))),5);
	vcdp->fullBus(c+10,((0xffU & vlTOPp->core__DOT__instruction)),8);
	vcdp->fullBus(c+11,(vlTOPp->core__DOT__rs_data),8);
	vcdp->fullBus(c+12,(vlTOPp->core__DOT__rd_data),8);
	vcdp->fullBus(c+13,((0xffU & ((4U & (IData)(vlTOPp->core__DOT__func_alu))
				       ? ((2U & (IData)(vlTOPp->core__DOT__func_alu))
					   ? ((1U & (IData)(vlTOPp->core__DOT__func_alu))
					       ? (~ (IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i))
					       : ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						  ^ (IData)(vlTOPp->core__DOT__rs_data)))
					   : ((1U & (IData)(vlTOPp->core__DOT__func_alu))
					       ? ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						  | (IData)(vlTOPp->core__DOT__rs_data))
					       : ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						  & (IData)(vlTOPp->core__DOT__rs_data))))
				       : ((2U & (IData)(vlTOPp->core__DOT__func_alu))
					   ? ((1U & (IData)(vlTOPp->core__DOT__func_alu))
					       ? VL_MULS_III(8,8,8, (IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i), (IData)(vlTOPp->core__DOT__rs_data))
					       : (IData)(vlTOPp->core__DOT__alu0__DOT__r_as))
					   : ((1U & (IData)(vlTOPp->core__DOT__func_alu))
					       ? (IData)(vlTOPp->core__DOT__alu0__DOT__r_as)
					       : (IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i)))))),8);
	vcdp->fullBus(c+14,(vlTOPp->core__DOT__rf0__DOT__regs_rd[0]),8);
	vcdp->fullBus(c+15,(vlTOPp->core__DOT__rf0__DOT__regs_rd[1]),8);
	vcdp->fullBus(c+16,(vlTOPp->core__DOT__rf0__DOT__regs_rd[2]),8);
	vcdp->fullBus(c+17,(vlTOPp->core__DOT__rf0__DOT__regs_rd[3]),8);
	vcdp->fullBus(c+18,(vlTOPp->core__DOT__rf0__DOT__regs_rd[4]),8);
	vcdp->fullBus(c+19,(vlTOPp->core__DOT__rf0__DOT__regs_rd[5]),8);
	vcdp->fullBus(c+20,(vlTOPp->core__DOT__rf0__DOT__regs_rd[6]),8);
	vcdp->fullBus(c+21,(vlTOPp->core__DOT__rf0__DOT__regs_rd[7]),8);
	vcdp->fullBus(c+22,(vlTOPp->core__DOT__rf0__DOT__regs_rd[8]),8);
	vcdp->fullBus(c+23,(vlTOPp->core__DOT__rf0__DOT__regs_rd[9]),8);
	vcdp->fullBus(c+24,(vlTOPp->core__DOT__rf0__DOT__regs_rd[10]),8);
	vcdp->fullBus(c+25,(vlTOPp->core__DOT__rf0__DOT__regs_rd[11]),8);
	vcdp->fullBus(c+26,(vlTOPp->core__DOT__rf0__DOT__regs_rd[12]),8);
	vcdp->fullBus(c+27,(vlTOPp->core__DOT__rf0__DOT__regs_rd[13]),8);
	vcdp->fullBus(c+28,(vlTOPp->core__DOT__rf0__DOT__regs_rd[14]),8);
	vcdp->fullBus(c+29,(vlTOPp->core__DOT__rf0__DOT__regs_rd[15]),8);
	vcdp->fullBus(c+30,(vlTOPp->core__DOT__rf0__DOT__regs_rd[16]),8);
	vcdp->fullBus(c+31,(vlTOPp->core__DOT__rf0__DOT__regs_rd[17]),8);
	vcdp->fullBus(c+32,(vlTOPp->core__DOT__rf0__DOT__regs_rd[18]),8);
	vcdp->fullBus(c+33,(vlTOPp->core__DOT__rf0__DOT__regs_rd[19]),8);
	vcdp->fullBus(c+34,(vlTOPp->core__DOT__rf0__DOT__regs_rd[20]),8);
	vcdp->fullBus(c+35,(vlTOPp->core__DOT__rf0__DOT__regs_rd[21]),8);
	vcdp->fullBus(c+36,(vlTOPp->core__DOT__rf0__DOT__regs_rd[22]),8);
	vcdp->fullBus(c+37,(vlTOPp->core__DOT__rf0__DOT__regs_rd[23]),8);
	vcdp->fullBus(c+38,(vlTOPp->core__DOT__rf0__DOT__regs_rd[24]),8);
	vcdp->fullBus(c+39,(vlTOPp->core__DOT__rf0__DOT__regs_rd[25]),8);
	vcdp->fullBus(c+40,(vlTOPp->core__DOT__rf0__DOT__regs_rd[26]),8);
	vcdp->fullBus(c+41,(vlTOPp->core__DOT__rf0__DOT__regs_rd[27]),8);
	vcdp->fullBus(c+42,(vlTOPp->core__DOT__rf0__DOT__regs_rd[28]),8);
	vcdp->fullBus(c+43,(vlTOPp->core__DOT__rf0__DOT__regs_rd[29]),8);
	vcdp->fullBus(c+44,(vlTOPp->core__DOT__rf0__DOT__regs_rd[30]),8);
	vcdp->fullBus(c+45,(vlTOPp->core__DOT__rf0__DOT__regs_rd[31]),8);
	vcdp->fullBus(c+46,(vlTOPp->core__DOT____Vcellinp__alu0__a_i),8);
	vcdp->fullBit(c+47,(vlTOPp->core__DOT__alu0__DOT__sub));
	vcdp->fullBus(c+48,(vlTOPp->core__DOT__alu0__DOT__tmp),10);
	vcdp->fullBus(c+49,(vlTOPp->core__DOT__alu0__DOT__r_as),9);
	vcdp->fullBus(c+50,(vlTOPp->core__DOT__rf0__DOT__regs[0]),8);
	vcdp->fullBus(c+51,(vlTOPp->core__DOT__rf0__DOT__regs[1]),8);
	vcdp->fullBus(c+52,(vlTOPp->core__DOT__rf0__DOT__regs[2]),8);
	vcdp->fullBus(c+53,(vlTOPp->core__DOT__rf0__DOT__regs[3]),8);
	vcdp->fullBus(c+54,(vlTOPp->core__DOT__rf0__DOT__regs[4]),8);
	vcdp->fullBus(c+55,(vlTOPp->core__DOT__rf0__DOT__regs[5]),8);
	vcdp->fullBus(c+56,(vlTOPp->core__DOT__rf0__DOT__regs[6]),8);
	vcdp->fullBus(c+57,(vlTOPp->core__DOT__rf0__DOT__regs[7]),8);
	vcdp->fullBus(c+58,(vlTOPp->core__DOT__rf0__DOT__regs[8]),8);
	vcdp->fullBus(c+59,(vlTOPp->core__DOT__rf0__DOT__regs[9]),8);
	vcdp->fullBus(c+60,(vlTOPp->core__DOT__rf0__DOT__regs[10]),8);
	vcdp->fullBus(c+61,(vlTOPp->core__DOT__rf0__DOT__regs[11]),8);
	vcdp->fullBus(c+62,(vlTOPp->core__DOT__rf0__DOT__regs[12]),8);
	vcdp->fullBus(c+63,(vlTOPp->core__DOT__rf0__DOT__regs[13]),8);
	vcdp->fullBus(c+64,(vlTOPp->core__DOT__rf0__DOT__regs[14]),8);
	vcdp->fullBus(c+65,(vlTOPp->core__DOT__rf0__DOT__regs[15]),8);
	vcdp->fullBus(c+66,(vlTOPp->core__DOT__rf0__DOT__regs[16]),8);
	vcdp->fullBus(c+67,(vlTOPp->core__DOT__rf0__DOT__regs[17]),8);
	vcdp->fullBus(c+68,(vlTOPp->core__DOT__rf0__DOT__regs[18]),8);
	vcdp->fullBus(c+69,(vlTOPp->core__DOT__rf0__DOT__regs[19]),8);
	vcdp->fullBus(c+70,(vlTOPp->core__DOT__rf0__DOT__regs[20]),8);
	vcdp->fullBus(c+71,(vlTOPp->core__DOT__rf0__DOT__regs[21]),8);
	vcdp->fullBus(c+72,(vlTOPp->core__DOT__rf0__DOT__regs[22]),8);
	vcdp->fullBus(c+73,(vlTOPp->core__DOT__rf0__DOT__regs[23]),8);
	vcdp->fullBus(c+74,(vlTOPp->core__DOT__rf0__DOT__regs[24]),8);
	vcdp->fullBus(c+75,(vlTOPp->core__DOT__rf0__DOT__regs[25]),8);
	vcdp->fullBus(c+76,(vlTOPp->core__DOT__rf0__DOT__regs[26]),8);
	vcdp->fullBus(c+77,(vlTOPp->core__DOT__rf0__DOT__regs[27]),8);
	vcdp->fullBus(c+78,(vlTOPp->core__DOT__rf0__DOT__regs[28]),8);
	vcdp->fullBus(c+79,(vlTOPp->core__DOT__rf0__DOT__regs[29]),8);
	vcdp->fullBus(c+80,(vlTOPp->core__DOT__rf0__DOT__regs[30]),8);
	vcdp->fullBus(c+81,(vlTOPp->core__DOT__addr_pc),10);
	vcdp->fullBit(c+82,(vlTOPp->clk_i));
	vcdp->fullBit(c+83,(vlTOPp->n_rst_i));
	vcdp->fullBit(c+84,(vlTOPp->ext_data_i));
	vcdp->fullBus(c+85,(vlTOPp->result_o),8);
	vcdp->fullBit(c+86,(vlTOPp->halt_o));
	vcdp->fullBus(c+87,(0xaU),32);
	vcdp->fullBus(c+88,(8U),32);
	vcdp->fullBus(c+89,(0x20U),32);
    }
}
