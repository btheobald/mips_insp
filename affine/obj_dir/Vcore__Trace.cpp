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
	if (VL_UNLIKELY((1U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 3U)) | (vlTOPp->__Vm_traceActivity 
					      >> 4U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 4U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
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
	vcdp->chgBus(c+1,(vlTOPp->core__DOT__r0__DOT__rom[0]),26);
	vcdp->chgBus(c+2,(vlTOPp->core__DOT__r0__DOT__rom[1]),26);
	vcdp->chgBus(c+3,(vlTOPp->core__DOT__r0__DOT__rom[2]),26);
	vcdp->chgBus(c+4,(vlTOPp->core__DOT__r0__DOT__rom[3]),26);
    }
}

void Vcore::traceChgThis__3(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+5,(vlTOPp->core__DOT__clk_h));
    }
}

void Vcore::traceChgThis__4(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+6,(vlTOPp->core__DOT__f0__DOT__regs
			  [(3U & (vlTOPp->core__DOT__rom_data 
				  >> 0x10U))]),8);
    }
}

void Vcore::traceChgThis__5(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+7,(vlTOPp->core__DOT__rom_data),26);
	vcdp->chgBus(c+8,((3U & (vlTOPp->core__DOT__rom_data 
				 >> 0x10U))),2);
	vcdp->chgBus(c+9,((3U & (vlTOPp->core__DOT__rom_data 
				 >> 0x12U))),2);
	vcdp->chgBus(c+10,((0xffU & (vlTOPp->core__DOT__rom_data 
				     >> 8U))),8);
	vcdp->chgBus(c+11,((0xffU & vlTOPp->core__DOT__rom_data)),8);
	vcdp->chgBus(c+12,(vlTOPp->core__DOT__alu_op),6);
	vcdp->chgBus(c+13,(vlTOPp->core__DOT__wd_data),8);
	vcdp->chgBus(c+14,(vlTOPp->core__DOT__rd_data),8);
	vcdp->chgBus(c+15,((0xffU & ((IData)(vlTOPp->core__DOT__a0__DOT__mul2_rs) 
				     + (IData)(vlTOPp->core__DOT__a0__DOT__add2_b)))),8);
	vcdp->chgBit(c+16,((1U & ((IData)(vlTOPp->core__DOT__alu_op) 
				  >> 4U))));
	vcdp->chgBus(c+17,(vlTOPp->core__DOT__a0__DOT__mul1_a),8);
	vcdp->chgBus(c+18,((0xffU & ((3U == (3U & ((IData)(vlTOPp->core__DOT__alu_op) 
						   >> 2U)))
				      ? (IData)(vlTOPp->core__DOT__rd_data)
				      : (vlTOPp->core__DOT__rom_data 
					 >> 8U)))),8);
	vcdp->chgBus(c+19,(vlTOPp->core__DOT__a0__DOT__mul1_rs),8);
	vcdp->chgBus(c+20,(vlTOPp->core__DOT__a0__DOT__mul1_r),16);
	vcdp->chgBus(c+21,(vlTOPp->core__DOT__a0__DOT__mul2_a),8);
	vcdp->chgBus(c+22,(vlTOPp->core__DOT__a0__DOT__mul2_rs),8);
	vcdp->chgBus(c+23,(vlTOPp->core__DOT__a0__DOT__mul2_r),16);
	vcdp->chgBus(c+24,(vlTOPp->core__DOT__a0__DOT__add1_b),8);
	vcdp->chgBus(c+25,(vlTOPp->core__DOT__a0__DOT__add2_b),8);
    }
}

void Vcore::traceChgThis__6(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+26,(vlTOPp->core__DOT__halt_r));
	vcdp->chgBit(c+27,((3U == (IData)(vlTOPp->core__DOT__pc_addr))));
	vcdp->chgBus(c+28,(vlTOPp->core__DOT__pc_addr),2);
    }
}

void Vcore::traceChgThis__7(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+29,(vlTOPp->core__DOT__f0__DOT__regs
			   [2U]),8);
	vcdp->chgBus(c+30,(vlTOPp->core__DOT__f0__DOT__regs
			   [3U]),8);
	vcdp->chgBus(c+31,(vlTOPp->core__DOT__f0__DOT__regs[0]),8);
	vcdp->chgBus(c+32,(vlTOPp->core__DOT__f0__DOT__regs[1]),8);
	vcdp->chgBus(c+33,(vlTOPp->core__DOT__f0__DOT__regs[2]),8);
	vcdp->chgBus(c+34,(vlTOPp->core__DOT__f0__DOT__regs[3]),8);
    }
}

void Vcore::traceChgThis__8(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+35,(vlTOPp->clk_i));
	vcdp->chgBit(c+36,(vlTOPp->n_rst_i));
	vcdp->chgBus(c+37,(vlTOPp->ext_data_i),8);
	vcdp->chgBus(c+38,(vlTOPp->ext_data_o),8);
	vcdp->chgBus(c+39,(vlTOPp->prog_addr_o),2);
	vcdp->chgBit(c+40,(vlTOPp->halt_o));
    }
}
