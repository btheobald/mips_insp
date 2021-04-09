// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcore__Syms.h"


//======================

void Vcore::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcore* t=(Vcore*)userthis;
    Vcore__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vcore::traceChgThis(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcore::traceChgThis__2(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+1,(vlTOPp->core__DOT__mode_pc),2);
	vcdp->chgBus(c+2,(vlTOPp->core__DOT__flags_alu),4);
	vcdp->chgBus(c+3,(vlTOPp->core__DOT__func_alu),3);
	vcdp->chgBit(c+4,((1U & (vlTOPp->core__DOT__instruction 
				 >> 0x16U))));
	vcdp->chgBus(c+5,((0x3fU & (vlTOPp->core__DOT__instruction 
				    >> 0x12U))),6);
	vcdp->chgBit(c+6,(vlTOPp->core__DOT__wr_en_rf));
	vcdp->chgBus(c+7,(vlTOPp->core__DOT__instruction),24);
	vcdp->chgBus(c+8,((0x1fU & (vlTOPp->core__DOT__instruction 
				    >> 0xdU))),5);
	vcdp->chgBus(c+9,((0x1fU & (vlTOPp->core__DOT__instruction 
				    >> 8U))),5);
	vcdp->chgBus(c+10,((0xffU & vlTOPp->core__DOT__instruction)),8);
	vcdp->chgBus(c+11,(vlTOPp->core__DOT__rs_data),8);
	vcdp->chgBus(c+12,(vlTOPp->core__DOT__rd_data),8);
	vcdp->chgBus(c+13,((0xffU & ((4U & (IData)(vlTOPp->core__DOT__func_alu))
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
	vcdp->chgBus(c+14,(vlTOPp->core__DOT__rf0__DOT__regs_rd[0]),8);
	vcdp->chgBus(c+15,(vlTOPp->core__DOT__rf0__DOT__regs_rd[1]),8);
	vcdp->chgBus(c+16,(vlTOPp->core__DOT__rf0__DOT__regs_rd[2]),8);
	vcdp->chgBus(c+17,(vlTOPp->core__DOT__rf0__DOT__regs_rd[3]),8);
	vcdp->chgBus(c+18,(vlTOPp->core__DOT__rf0__DOT__regs_rd[4]),8);
	vcdp->chgBus(c+19,(vlTOPp->core__DOT__rf0__DOT__regs_rd[5]),8);
	vcdp->chgBus(c+20,(vlTOPp->core__DOT__rf0__DOT__regs_rd[6]),8);
	vcdp->chgBus(c+21,(vlTOPp->core__DOT__rf0__DOT__regs_rd[7]),8);
	vcdp->chgBus(c+22,(vlTOPp->core__DOT__rf0__DOT__regs_rd[8]),8);
	vcdp->chgBus(c+23,(vlTOPp->core__DOT__rf0__DOT__regs_rd[9]),8);
	vcdp->chgBus(c+24,(vlTOPp->core__DOT__rf0__DOT__regs_rd[10]),8);
	vcdp->chgBus(c+25,(vlTOPp->core__DOT__rf0__DOT__regs_rd[11]),8);
	vcdp->chgBus(c+26,(vlTOPp->core__DOT__rf0__DOT__regs_rd[12]),8);
	vcdp->chgBus(c+27,(vlTOPp->core__DOT__rf0__DOT__regs_rd[13]),8);
	vcdp->chgBus(c+28,(vlTOPp->core__DOT__rf0__DOT__regs_rd[14]),8);
	vcdp->chgBus(c+29,(vlTOPp->core__DOT__rf0__DOT__regs_rd[15]),8);
	vcdp->chgBus(c+30,(vlTOPp->core__DOT__rf0__DOT__regs_rd[16]),8);
	vcdp->chgBus(c+31,(vlTOPp->core__DOT__rf0__DOT__regs_rd[17]),8);
	vcdp->chgBus(c+32,(vlTOPp->core__DOT__rf0__DOT__regs_rd[18]),8);
	vcdp->chgBus(c+33,(vlTOPp->core__DOT__rf0__DOT__regs_rd[19]),8);
	vcdp->chgBus(c+34,(vlTOPp->core__DOT__rf0__DOT__regs_rd[20]),8);
	vcdp->chgBus(c+35,(vlTOPp->core__DOT__rf0__DOT__regs_rd[21]),8);
	vcdp->chgBus(c+36,(vlTOPp->core__DOT__rf0__DOT__regs_rd[22]),8);
	vcdp->chgBus(c+37,(vlTOPp->core__DOT__rf0__DOT__regs_rd[23]),8);
	vcdp->chgBus(c+38,(vlTOPp->core__DOT__rf0__DOT__regs_rd[24]),8);
	vcdp->chgBus(c+39,(vlTOPp->core__DOT__rf0__DOT__regs_rd[25]),8);
	vcdp->chgBus(c+40,(vlTOPp->core__DOT__rf0__DOT__regs_rd[26]),8);
	vcdp->chgBus(c+41,(vlTOPp->core__DOT__rf0__DOT__regs_rd[27]),8);
	vcdp->chgBus(c+42,(vlTOPp->core__DOT__rf0__DOT__regs_rd[28]),8);
	vcdp->chgBus(c+43,(vlTOPp->core__DOT__rf0__DOT__regs_rd[29]),8);
	vcdp->chgBus(c+44,(vlTOPp->core__DOT__rf0__DOT__regs_rd[30]),8);
	vcdp->chgBus(c+45,(vlTOPp->core__DOT__rf0__DOT__regs_rd[31]),8);
	vcdp->chgBus(c+46,(vlTOPp->core__DOT____Vcellinp__alu0__a_i),8);
	vcdp->chgBit(c+47,(vlTOPp->core__DOT__alu0__DOT__sub));
	vcdp->chgBus(c+48,(vlTOPp->core__DOT__alu0__DOT__tmp),10);
	vcdp->chgBus(c+49,(vlTOPp->core__DOT__alu0__DOT__r_as),9);
    }
}

void Vcore::traceChgThis__3(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+50,(vlTOPp->core__DOT__rf0__DOT__regs[0]),8);
	vcdp->chgBus(c+51,(vlTOPp->core__DOT__rf0__DOT__regs[1]),8);
	vcdp->chgBus(c+52,(vlTOPp->core__DOT__rf0__DOT__regs[2]),8);
	vcdp->chgBus(c+53,(vlTOPp->core__DOT__rf0__DOT__regs[3]),8);
	vcdp->chgBus(c+54,(vlTOPp->core__DOT__rf0__DOT__regs[4]),8);
	vcdp->chgBus(c+55,(vlTOPp->core__DOT__rf0__DOT__regs[5]),8);
	vcdp->chgBus(c+56,(vlTOPp->core__DOT__rf0__DOT__regs[6]),8);
	vcdp->chgBus(c+57,(vlTOPp->core__DOT__rf0__DOT__regs[7]),8);
	vcdp->chgBus(c+58,(vlTOPp->core__DOT__rf0__DOT__regs[8]),8);
	vcdp->chgBus(c+59,(vlTOPp->core__DOT__rf0__DOT__regs[9]),8);
	vcdp->chgBus(c+60,(vlTOPp->core__DOT__rf0__DOT__regs[10]),8);
	vcdp->chgBus(c+61,(vlTOPp->core__DOT__rf0__DOT__regs[11]),8);
	vcdp->chgBus(c+62,(vlTOPp->core__DOT__rf0__DOT__regs[12]),8);
	vcdp->chgBus(c+63,(vlTOPp->core__DOT__rf0__DOT__regs[13]),8);
	vcdp->chgBus(c+64,(vlTOPp->core__DOT__rf0__DOT__regs[14]),8);
	vcdp->chgBus(c+65,(vlTOPp->core__DOT__rf0__DOT__regs[15]),8);
	vcdp->chgBus(c+66,(vlTOPp->core__DOT__rf0__DOT__regs[16]),8);
	vcdp->chgBus(c+67,(vlTOPp->core__DOT__rf0__DOT__regs[17]),8);
	vcdp->chgBus(c+68,(vlTOPp->core__DOT__rf0__DOT__regs[18]),8);
	vcdp->chgBus(c+69,(vlTOPp->core__DOT__rf0__DOT__regs[19]),8);
	vcdp->chgBus(c+70,(vlTOPp->core__DOT__rf0__DOT__regs[20]),8);
	vcdp->chgBus(c+71,(vlTOPp->core__DOT__rf0__DOT__regs[21]),8);
	vcdp->chgBus(c+72,(vlTOPp->core__DOT__rf0__DOT__regs[22]),8);
	vcdp->chgBus(c+73,(vlTOPp->core__DOT__rf0__DOT__regs[23]),8);
	vcdp->chgBus(c+74,(vlTOPp->core__DOT__rf0__DOT__regs[24]),8);
	vcdp->chgBus(c+75,(vlTOPp->core__DOT__rf0__DOT__regs[25]),8);
	vcdp->chgBus(c+76,(vlTOPp->core__DOT__rf0__DOT__regs[26]),8);
	vcdp->chgBus(c+77,(vlTOPp->core__DOT__rf0__DOT__regs[27]),8);
	vcdp->chgBus(c+78,(vlTOPp->core__DOT__rf0__DOT__regs[28]),8);
	vcdp->chgBus(c+79,(vlTOPp->core__DOT__rf0__DOT__regs[29]),8);
	vcdp->chgBus(c+80,(vlTOPp->core__DOT__rf0__DOT__regs[30]),8);
    }
}

void Vcore::traceChgThis__4(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+81,(vlTOPp->core__DOT__addr_pc),10);
    }
}

void Vcore::traceChgThis__5(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+82,(vlTOPp->clk_i));
	vcdp->chgBit(c+83,(vlTOPp->n_rst_i));
	vcdp->chgBit(c+84,(vlTOPp->ext_data_i));
	vcdp->chgBus(c+85,(vlTOPp->result_o),8);
	vcdp->chgBit(c+86,(vlTOPp->halt_o));
    }
}
