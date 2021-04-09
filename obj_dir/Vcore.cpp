// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcore.h for the primary calling header

#include "Vcore.h"
#include "Vcore__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vcore) {
    Vcore__Syms* __restrict vlSymsp = __VlSymsp = new Vcore__Syms(this, name());
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcore::__Vconfigure(Vcore__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcore::~Vcore() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vcore::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcore::eval\n"); );
    Vcore__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vcore::_eval_initial_loop(Vcore__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vcore::_initial__TOP__1(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_initial__TOP__1\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at rom.sv:7
    VL_READMEM_Q(true,24,1024, 0,2, VL_ULL(0x70726f672e686578)
		 , vlTOPp->core__DOT__rom0__DOT__rom
		 ,0,~0);
}

VL_INLINE_OPT void Vcore::_sequent__TOP__2(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__2\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__core__DOT__addr_pc = vlTOPp->core__DOT__addr_pc;
    // ALWAYS at pc.sv:8
    vlTOPp->__Vdly__core__DOT__addr_pc = (0x3ffU & 
					  ((IData)(vlTOPp->n_rst_i)
					    ? ((2U 
						& (IData)(vlTOPp->core__DOT__mode_pc))
					        ? (
						   (1U 
						    & (IData)(vlTOPp->core__DOT__mode_pc))
						    ? 
						   VL_EXTENDS_II(10,8, 
								 (0xffU 
								  & vlTOPp->core__DOT__instruction))
						    : 
						   ((IData)(vlTOPp->core__DOT__addr_pc) 
						    + 
						    VL_EXTENDS_II(10,8, 
								  (0xffU 
								   & vlTOPp->core__DOT__instruction))))
					        : (
						   (1U 
						    & (IData)(vlTOPp->core__DOT__mode_pc))
						    ? 
						   ((IData)(1U) 
						    + (IData)(vlTOPp->core__DOT__addr_pc))
						    : (IData)(vlTOPp->core__DOT__addr_pc)))
					    : 0U));
}

VL_INLINE_OPT void Vcore::_sequent__TOP__3(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__3\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__core__DOT__rf0__DOT__regs__v0,4,0);
    VL_SIG8(__Vdlyvval__core__DOT__rf0__DOT__regs__v0,7,0);
    VL_SIG8(__Vdlyvset__core__DOT__rf0__DOT__regs__v0,0,0);
    // Body
    __Vdlyvset__core__DOT__rf0__DOT__regs__v0 = 0U;
    // ALWAYS at core.sv:37
    VL_WRITEF("%x, %x, %x\n",10,vlTOPp->core__DOT__addr_pc,
	      24,vlTOPp->core__DOT__instruction,8,(0xffU 
						   & ((4U 
						       & (IData)(vlTOPp->core__DOT__func_alu))
						       ? 
						      ((2U 
							& (IData)(vlTOPp->core__DOT__func_alu))
						        ? 
						       ((1U 
							 & (IData)(vlTOPp->core__DOT__func_alu))
							 ? 
							(~ (IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i))
							 : 
							((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							 ^ (IData)(vlTOPp->core__DOT__rs_data)))
						        : 
						       ((1U 
							 & (IData)(vlTOPp->core__DOT__func_alu))
							 ? 
							((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							 | (IData)(vlTOPp->core__DOT__rs_data))
							 : 
							((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							 & (IData)(vlTOPp->core__DOT__rs_data))))
						       : 
						      ((2U 
							& (IData)(vlTOPp->core__DOT__func_alu))
						        ? 
						       ((1U 
							 & (IData)(vlTOPp->core__DOT__func_alu))
							 ? 
							VL_MULS_III(8,8,8, (IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i), (IData)(vlTOPp->core__DOT__rs_data))
							 : (IData)(vlTOPp->core__DOT__alu0__DOT__r_as))
						        : 
						       ((1U 
							 & (IData)(vlTOPp->core__DOT__func_alu))
							 ? (IData)(vlTOPp->core__DOT__alu0__DOT__r_as)
							 : (IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i))))));
    // ALWAYS at rf.sv:13
    if (((IData)(vlTOPp->core__DOT__wr_en_rf) & (0U 
						 != 
						 (0x1fU 
						  & (vlTOPp->core__DOT__instruction 
						     >> 0xdU))))) {
	vlTOPp->core__DOT__rf0__DOT____Vlvbound1 = 
	    (0xffU & ((4U & (IData)(vlTOPp->core__DOT__func_alu))
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
			       : (IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i)))));
	if (VL_LIKELY((0x1eU >= (0x1fU & ((vlTOPp->core__DOT__instruction 
					   >> 0xdU) 
					  - (IData)(1U)))))) {
	    __Vdlyvval__core__DOT__rf0__DOT__regs__v0 
		= vlTOPp->core__DOT__rf0__DOT____Vlvbound1;
	    __Vdlyvset__core__DOT__rf0__DOT__regs__v0 = 1U;
	    __Vdlyvdim0__core__DOT__rf0__DOT__regs__v0 
		= (0x1fU & ((vlTOPp->core__DOT__instruction 
			     >> 0xdU) - (IData)(1U)));
	}
    }
    // ALWAYSPOST at rf.sv:15
    if (__Vdlyvset__core__DOT__rf0__DOT__regs__v0) {
	vlTOPp->core__DOT__rf0__DOT__regs[__Vdlyvdim0__core__DOT__rf0__DOT__regs__v0] 
	    = __Vdlyvval__core__DOT__rf0__DOT__regs__v0;
    }
}

void Vcore::_settle__TOP__4(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_settle__TOP__4\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->core__DOT__instruction = vlTOPp->core__DOT__rom0__DOT__rom
	[vlTOPp->core__DOT__addr_pc];
    // ALWAYS at dec.sv:10
    vlTOPp->core__DOT__func_alu = (7U & ((0x200000U 
					  & vlTOPp->core__DOT__instruction)
					  ? 2U : (vlTOPp->core__DOT__instruction 
						  >> 0x12U)));
    // ALWAYS at rf.sv:19
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0U] = 0U;
    vlTOPp->core__DOT__rf0__DOT__regs_rd[1U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[2U] = vlTOPp->core__DOT__rf0__DOT__regs
	[1U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[3U] = vlTOPp->core__DOT__rf0__DOT__regs
	[2U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[4U] = vlTOPp->core__DOT__rf0__DOT__regs
	[3U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[5U] = vlTOPp->core__DOT__rf0__DOT__regs
	[4U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[6U] = vlTOPp->core__DOT__rf0__DOT__regs
	[5U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[7U] = vlTOPp->core__DOT__rf0__DOT__regs
	[6U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[8U] = vlTOPp->core__DOT__rf0__DOT__regs
	[7U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[9U] = vlTOPp->core__DOT__rf0__DOT__regs
	[8U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xaU] = vlTOPp->core__DOT__rf0__DOT__regs
	[9U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xbU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xaU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xcU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xbU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xdU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xcU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xeU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xdU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xfU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xeU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x10U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xfU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x11U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x10U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x12U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x11U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x13U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x12U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x14U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x13U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x15U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x14U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x16U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x15U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x17U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x16U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x18U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x17U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x19U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x18U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1aU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x19U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1bU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1aU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1cU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1bU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1dU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1cU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1eU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1dU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1fU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1eU];
    vlTOPp->core__DOT__rs_data = vlTOPp->core__DOT__rf0__DOT__regs_rd
	[(0x1fU & (vlTOPp->core__DOT__instruction >> 8U))];
    vlTOPp->core__DOT__rd_data = vlTOPp->core__DOT__rf0__DOT__regs_rd
	[(0x1fU & (vlTOPp->core__DOT__instruction >> 0xdU))];
    vlTOPp->core__DOT____Vcellinp__alu0__a_i = (0xffU 
						& ((0x400000U 
						    & vlTOPp->core__DOT__instruction)
						    ? vlTOPp->core__DOT__instruction
						    : (IData)(vlTOPp->core__DOT__rd_data)));
    // ALWAYS at alu.sv:11
    vlTOPp->core__DOT__alu0__DOT__sub = (2U == (IData)(vlTOPp->core__DOT__func_alu));
    vlTOPp->core__DOT__alu0__DOT__tmp = (0x3ffU & (
						   (((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						     << 1U) 
						    | (IData)(vlTOPp->core__DOT__alu0__DOT__sub)) 
						   + 
						   (((IData)(vlTOPp->core__DOT__alu0__DOT__sub) 
						     << 9U) 
						    | ((0x1feU 
							& ((VL_NEGATE_I((IData)((IData)(vlTOPp->core__DOT__alu0__DOT__sub))) 
							    ^ (IData)(vlTOPp->core__DOT__rs_data)) 
							   << 1U)) 
						       | (IData)(vlTOPp->core__DOT__alu0__DOT__sub)))));
    vlTOPp->core__DOT__alu0__DOT__r_as = (0x1ffU & 
					  ((IData)(vlTOPp->core__DOT__alu0__DOT__tmp) 
					   >> 1U));
    // ALWAYS at alu.sv:19
    if (vlTOPp->core__DOT__alu0__DOT__sub) {
	vlTOPp->core__DOT__flags_alu = ((0xeU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (1U & (((
						   ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						    >> 7U) 
						   & (~ 
						      ((IData)(vlTOPp->core__DOT__rs_data) 
						       >> 7U))) 
						  | (((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						      >> 7U) 
						     & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							>> 7U))) 
						 | ((~ 
						     ((IData)(vlTOPp->core__DOT__rs_data) 
						      >> 7U)) 
						    & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
						       >> 7U)))));
	vlTOPp->core__DOT__flags_alu = ((0xdU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (2U & ((0x3fffffeU 
						  & ((((~ 
							((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							 >> 7U)) 
						       << 1U) 
						      & ((IData)(vlTOPp->core__DOT__rs_data) 
							 >> 6U)) 
						     & ((~ 
							 ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							  >> 7U)) 
							<< 1U))) 
						 | (0x3fffffeU 
						    & ((((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							 >> 6U) 
							& ((~ 
							    ((IData)(vlTOPp->core__DOT__rs_data) 
							     >> 7U)) 
							   << 1U)) 
						       & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							  >> 6U))))));
    } else {
	vlTOPp->core__DOT__flags_alu = ((0xeU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (1U & (((
						   ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						    & (IData)(vlTOPp->core__DOT__rs_data)) 
						   >> 7U) 
						  | (((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						      >> 7U) 
						     & (~ 
							((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							 >> 7U)))) 
						 | (((IData)(vlTOPp->core__DOT__rs_data) 
						     >> 7U) 
						    & (~ 
						       ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							>> 7U))))));
	vlTOPp->core__DOT__flags_alu = ((0xdU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (2U & (((
						   ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						    & (IData)(vlTOPp->core__DOT__rs_data)) 
						   >> 6U) 
						  & ((~ 
						      ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
						       >> 7U)) 
						     << 1U)) 
						 | ((((~ 
						       ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							>> 7U)) 
						      & (~ 
							 ((IData)(vlTOPp->core__DOT__rs_data) 
							  >> 7U))) 
						     << 1U) 
						    & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
						       >> 6U)))));
    }
    vlTOPp->core__DOT__flags_alu = ((7U & (IData)(vlTOPp->core__DOT__flags_alu)) 
				    | (8U & ((~ (IData)(
							(0U 
							 != (IData)(vlTOPp->core__DOT__alu0__DOT__r_as)))) 
					     << 3U)));
    vlTOPp->core__DOT__flags_alu = ((0xbU & (IData)(vlTOPp->core__DOT__flags_alu)) 
				    | (4U & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
					     >> 5U)));
    // ALWAYS at dec.sv:10
    vlTOPp->core__DOT__mode_pc = 1U;
    vlTOPp->core__DOT__wr_en_rf = 0U;
    vlTOPp->halt_o = 0U;
    if (VL_UNLIKELY((0x800000U & vlTOPp->core__DOT__instruction))) {
	VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
		  64,VL_TIME_Q(),vlSymsp->name(),6,
		  (0x3fU & (vlTOPp->core__DOT__instruction 
			    >> 0x12U)));
	vlTOPp->core__DOT__mode_pc = 0U;
	vlTOPp->halt_o = 1U;
	VL_STOP_MT("dec.sv",43,"");
    } else {
	if ((0x400000U & vlTOPp->core__DOT__instruction)) {
	    if (VL_UNLIKELY((0x200000U & vlTOPp->core__DOT__instruction))) {
		vlTOPp->core__DOT__mode_pc = 0U;
		vlTOPp->halt_o = 1U;
		VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
			  64,VL_TIME_Q(),vlSymsp->name(),
			  6,(0x3fU & (vlTOPp->core__DOT__instruction 
				      >> 0x12U)));
		VL_STOP_MT("dec.sv",43,"");
	    } else {
		if ((0x100000U & vlTOPp->core__DOT__instruction)) {
		    vlTOPp->core__DOT__mode_pc = 1U;
		    vlTOPp->core__DOT__wr_en_rf = 1U;
		} else {
		    if ((0x80000U & vlTOPp->core__DOT__instruction)) {
			vlTOPp->core__DOT__mode_pc = 1U;
			vlTOPp->core__DOT__wr_en_rf = 1U;
		    } else {
			if (VL_LIKELY((0x40000U & vlTOPp->core__DOT__instruction))) {
			    vlTOPp->core__DOT__mode_pc = 1U;
			    vlTOPp->core__DOT__wr_en_rf = 1U;
			} else {
			    vlTOPp->core__DOT__mode_pc = 0U;
			    vlTOPp->halt_o = 1U;
			    VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
				      64,VL_TIME_Q(),
				      vlSymsp->name(),
				      6,(0x3fU & (vlTOPp->core__DOT__instruction 
						  >> 0x12U)));
			    VL_STOP_MT("dec.sv",43,"");
			}
		    }
		}
	    }
	} else {
	    if ((0x200000U & vlTOPp->core__DOT__instruction)) {
		if (VL_UNLIKELY((0x100000U & vlTOPp->core__DOT__instruction))) {
		    vlTOPp->core__DOT__mode_pc = 0U;
		    vlTOPp->halt_o = 1U;
		    VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
			      64,VL_TIME_Q(),vlSymsp->name(),
			      6,(0x3fU & (vlTOPp->core__DOT__instruction 
					  >> 0x12U)));
		    VL_STOP_MT("dec.sv",43,"");
		} else {
		    if (VL_UNLIKELY((0x80000U & vlTOPp->core__DOT__instruction))) {
			vlTOPp->core__DOT__mode_pc = 0U;
			vlTOPp->halt_o = 1U;
			VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
				  64,VL_TIME_Q(),vlSymsp->name(),
				  6,(0x3fU & (vlTOPp->core__DOT__instruction 
					      >> 0x12U)));
			VL_STOP_MT("dec.sv",43,"");
		    } else {
			vlTOPp->core__DOT__mode_pc 
			    = ((0x40000U & vlTOPp->core__DOT__instruction)
			        ? ((8U & (IData)(vlTOPp->core__DOT__flags_alu))
				    ? 1U : 2U) : ((8U 
						   & (IData)(vlTOPp->core__DOT__flags_alu))
						   ? 2U
						   : 1U));
		    }
		}
	    } else {
		if ((0x100000U & vlTOPp->core__DOT__instruction)) {
		    vlTOPp->core__DOT__mode_pc = 1U;
		    vlTOPp->core__DOT__wr_en_rf = 1U;
		} else {
		    if ((0x80000U & vlTOPp->core__DOT__instruction)) {
			vlTOPp->core__DOT__mode_pc = 1U;
			vlTOPp->core__DOT__wr_en_rf = 1U;
		    } else {
			if ((0x40000U & vlTOPp->core__DOT__instruction)) {
			    vlTOPp->core__DOT__mode_pc = 1U;
			    vlTOPp->core__DOT__wr_en_rf = 1U;
			} else {
			    vlTOPp->core__DOT__mode_pc = 0U;
			    vlTOPp->core__DOT__wr_en_rf = 0U;
			    vlTOPp->halt_o = 1U;
			}
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void Vcore::_sequent__TOP__5(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__5\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->core__DOT__addr_pc = vlTOPp->__Vdly__core__DOT__addr_pc;
    vlTOPp->core__DOT__instruction = vlTOPp->core__DOT__rom0__DOT__rom
	[vlTOPp->core__DOT__addr_pc];
    // ALWAYS at dec.sv:10
    vlTOPp->core__DOT__func_alu = (7U & ((0x200000U 
					  & vlTOPp->core__DOT__instruction)
					  ? 2U : (vlTOPp->core__DOT__instruction 
						  >> 0x12U)));
    // ALWAYS at rf.sv:19
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0U] = 0U;
    vlTOPp->core__DOT__rf0__DOT__regs_rd[1U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[2U] = vlTOPp->core__DOT__rf0__DOT__regs
	[1U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[3U] = vlTOPp->core__DOT__rf0__DOT__regs
	[2U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[4U] = vlTOPp->core__DOT__rf0__DOT__regs
	[3U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[5U] = vlTOPp->core__DOT__rf0__DOT__regs
	[4U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[6U] = vlTOPp->core__DOT__rf0__DOT__regs
	[5U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[7U] = vlTOPp->core__DOT__rf0__DOT__regs
	[6U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[8U] = vlTOPp->core__DOT__rf0__DOT__regs
	[7U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[9U] = vlTOPp->core__DOT__rf0__DOT__regs
	[8U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xaU] = vlTOPp->core__DOT__rf0__DOT__regs
	[9U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xbU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xaU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xcU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xbU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xdU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xcU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xeU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xdU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0xfU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xeU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x10U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0xfU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x11U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x10U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x12U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x11U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x13U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x12U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x14U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x13U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x15U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x14U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x16U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x15U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x17U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x16U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x18U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x17U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x19U] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x18U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1aU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x19U];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1bU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1aU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1cU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1bU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1dU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1cU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1eU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1dU];
    vlTOPp->core__DOT__rf0__DOT__regs_rd[0x1fU] = vlTOPp->core__DOT__rf0__DOT__regs
	[0x1eU];
    vlTOPp->core__DOT__rs_data = vlTOPp->core__DOT__rf0__DOT__regs_rd
	[(0x1fU & (vlTOPp->core__DOT__instruction >> 8U))];
    vlTOPp->core__DOT__rd_data = vlTOPp->core__DOT__rf0__DOT__regs_rd
	[(0x1fU & (vlTOPp->core__DOT__instruction >> 0xdU))];
    vlTOPp->core__DOT____Vcellinp__alu0__a_i = (0xffU 
						& ((0x400000U 
						    & vlTOPp->core__DOT__instruction)
						    ? vlTOPp->core__DOT__instruction
						    : (IData)(vlTOPp->core__DOT__rd_data)));
    // ALWAYS at alu.sv:11
    vlTOPp->core__DOT__alu0__DOT__sub = (2U == (IData)(vlTOPp->core__DOT__func_alu));
    vlTOPp->core__DOT__alu0__DOT__tmp = (0x3ffU & (
						   (((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						     << 1U) 
						    | (IData)(vlTOPp->core__DOT__alu0__DOT__sub)) 
						   + 
						   (((IData)(vlTOPp->core__DOT__alu0__DOT__sub) 
						     << 9U) 
						    | ((0x1feU 
							& ((VL_NEGATE_I((IData)((IData)(vlTOPp->core__DOT__alu0__DOT__sub))) 
							    ^ (IData)(vlTOPp->core__DOT__rs_data)) 
							   << 1U)) 
						       | (IData)(vlTOPp->core__DOT__alu0__DOT__sub)))));
    vlTOPp->core__DOT__alu0__DOT__r_as = (0x1ffU & 
					  ((IData)(vlTOPp->core__DOT__alu0__DOT__tmp) 
					   >> 1U));
    // ALWAYS at alu.sv:19
    if (vlTOPp->core__DOT__alu0__DOT__sub) {
	vlTOPp->core__DOT__flags_alu = ((0xeU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (1U & (((
						   ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						    >> 7U) 
						   & (~ 
						      ((IData)(vlTOPp->core__DOT__rs_data) 
						       >> 7U))) 
						  | (((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						      >> 7U) 
						     & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							>> 7U))) 
						 | ((~ 
						     ((IData)(vlTOPp->core__DOT__rs_data) 
						      >> 7U)) 
						    & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
						       >> 7U)))));
	vlTOPp->core__DOT__flags_alu = ((0xdU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (2U & ((0x3fffffeU 
						  & ((((~ 
							((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							 >> 7U)) 
						       << 1U) 
						      & ((IData)(vlTOPp->core__DOT__rs_data) 
							 >> 6U)) 
						     & ((~ 
							 ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							  >> 7U)) 
							<< 1U))) 
						 | (0x3fffffeU 
						    & ((((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							 >> 6U) 
							& ((~ 
							    ((IData)(vlTOPp->core__DOT__rs_data) 
							     >> 7U)) 
							   << 1U)) 
						       & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							  >> 6U))))));
    } else {
	vlTOPp->core__DOT__flags_alu = ((0xeU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (1U & (((
						   ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						    & (IData)(vlTOPp->core__DOT__rs_data)) 
						   >> 7U) 
						  | (((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						      >> 7U) 
						     & (~ 
							((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							 >> 7U)))) 
						 | (((IData)(vlTOPp->core__DOT__rs_data) 
						     >> 7U) 
						    & (~ 
						       ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
							>> 7U))))));
	vlTOPp->core__DOT__flags_alu = ((0xdU & (IData)(vlTOPp->core__DOT__flags_alu)) 
					| (2U & (((
						   ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
						    & (IData)(vlTOPp->core__DOT__rs_data)) 
						   >> 6U) 
						  & ((~ 
						      ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
						       >> 7U)) 
						     << 1U)) 
						 | ((((~ 
						       ((IData)(vlTOPp->core__DOT____Vcellinp__alu0__a_i) 
							>> 7U)) 
						      & (~ 
							 ((IData)(vlTOPp->core__DOT__rs_data) 
							  >> 7U))) 
						     << 1U) 
						    & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
						       >> 6U)))));
    }
    vlTOPp->core__DOT__flags_alu = ((7U & (IData)(vlTOPp->core__DOT__flags_alu)) 
				    | (8U & ((~ (IData)(
							(0U 
							 != (IData)(vlTOPp->core__DOT__alu0__DOT__r_as)))) 
					     << 3U)));
    vlTOPp->core__DOT__flags_alu = ((0xbU & (IData)(vlTOPp->core__DOT__flags_alu)) 
				    | (4U & ((IData)(vlTOPp->core__DOT__alu0__DOT__r_as) 
					     >> 5U)));
    // ALWAYS at dec.sv:10
    vlTOPp->core__DOT__mode_pc = 1U;
    vlTOPp->core__DOT__wr_en_rf = 0U;
    vlTOPp->halt_o = 0U;
    if (VL_UNLIKELY((0x800000U & vlTOPp->core__DOT__instruction))) {
	VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
		  64,VL_TIME_Q(),vlSymsp->name(),6,
		  (0x3fU & (vlTOPp->core__DOT__instruction 
			    >> 0x12U)));
	vlTOPp->core__DOT__mode_pc = 0U;
	vlTOPp->halt_o = 1U;
	VL_STOP_MT("dec.sv",43,"");
    } else {
	if ((0x400000U & vlTOPp->core__DOT__instruction)) {
	    if (VL_UNLIKELY((0x200000U & vlTOPp->core__DOT__instruction))) {
		vlTOPp->core__DOT__mode_pc = 0U;
		vlTOPp->halt_o = 1U;
		VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
			  64,VL_TIME_Q(),vlSymsp->name(),
			  6,(0x3fU & (vlTOPp->core__DOT__instruction 
				      >> 0x12U)));
		VL_STOP_MT("dec.sv",43,"");
	    } else {
		if ((0x100000U & vlTOPp->core__DOT__instruction)) {
		    vlTOPp->core__DOT__mode_pc = 1U;
		    vlTOPp->core__DOT__wr_en_rf = 1U;
		} else {
		    if ((0x80000U & vlTOPp->core__DOT__instruction)) {
			vlTOPp->core__DOT__mode_pc = 1U;
			vlTOPp->core__DOT__wr_en_rf = 1U;
		    } else {
			if (VL_LIKELY((0x40000U & vlTOPp->core__DOT__instruction))) {
			    vlTOPp->core__DOT__mode_pc = 1U;
			    vlTOPp->core__DOT__wr_en_rf = 1U;
			} else {
			    vlTOPp->core__DOT__mode_pc = 0U;
			    vlTOPp->halt_o = 1U;
			    VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
				      64,VL_TIME_Q(),
				      vlSymsp->name(),
				      6,(0x3fU & (vlTOPp->core__DOT__instruction 
						  >> 0x12U)));
			    VL_STOP_MT("dec.sv",43,"");
			}
		    }
		}
	    }
	} else {
	    if ((0x200000U & vlTOPp->core__DOT__instruction)) {
		if (VL_UNLIKELY((0x100000U & vlTOPp->core__DOT__instruction))) {
		    vlTOPp->core__DOT__mode_pc = 0U;
		    vlTOPp->halt_o = 1U;
		    VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
			      64,VL_TIME_Q(),vlSymsp->name(),
			      6,(0x3fU & (vlTOPp->core__DOT__instruction 
					  >> 0x12U)));
		    VL_STOP_MT("dec.sv",43,"");
		} else {
		    if (VL_UNLIKELY((0x80000U & vlTOPp->core__DOT__instruction))) {
			vlTOPp->core__DOT__mode_pc = 0U;
			vlTOPp->halt_o = 1U;
			VL_WRITEF("[%0t] %%Error: dec.sv:43: Assertion failed in %Ncore.dec0: Unimplemented Opcode %x\n",
				  64,VL_TIME_Q(),vlSymsp->name(),
				  6,(0x3fU & (vlTOPp->core__DOT__instruction 
					      >> 0x12U)));
			VL_STOP_MT("dec.sv",43,"");
		    } else {
			vlTOPp->core__DOT__mode_pc 
			    = ((0x40000U & vlTOPp->core__DOT__instruction)
			        ? ((8U & (IData)(vlTOPp->core__DOT__flags_alu))
				    ? 1U : 2U) : ((8U 
						   & (IData)(vlTOPp->core__DOT__flags_alu))
						   ? 2U
						   : 1U));
		    }
		}
	    } else {
		if ((0x100000U & vlTOPp->core__DOT__instruction)) {
		    vlTOPp->core__DOT__mode_pc = 1U;
		    vlTOPp->core__DOT__wr_en_rf = 1U;
		} else {
		    if ((0x80000U & vlTOPp->core__DOT__instruction)) {
			vlTOPp->core__DOT__mode_pc = 1U;
			vlTOPp->core__DOT__wr_en_rf = 1U;
		    } else {
			if ((0x40000U & vlTOPp->core__DOT__instruction)) {
			    vlTOPp->core__DOT__mode_pc = 1U;
			    vlTOPp->core__DOT__wr_en_rf = 1U;
			} else {
			    vlTOPp->core__DOT__mode_pc = 0U;
			    vlTOPp->core__DOT__wr_en_rf = 0U;
			    vlTOPp->halt_o = 1U;
			}
		    }
		}
	    }
	}
    }
}

void Vcore::_eval(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
	 | ((~ (IData)(vlTOPp->n_rst_i)) & (IData)(vlTOPp->__Vclklast__TOP__n_rst_i)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
	 | ((~ (IData)(vlTOPp->n_rst_i)) & (IData)(vlTOPp->__Vclklast__TOP__n_rst_i)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__n_rst_i = vlTOPp->n_rst_i;
}

void Vcore::_eval_initial(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval_initial\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__n_rst_i = vlTOPp->n_rst_i;
}

void Vcore::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::final\n"); );
    // Variables
    Vcore__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcore::_eval_settle(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval_settle\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vcore::_change_request(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_change_request\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcore::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
	Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((n_rst_i & 0xfeU))) {
	Verilated::overWidthError("n_rst_i");}
    if (VL_UNLIKELY((ext_data_i & 0xfeU))) {
	Verilated::overWidthError("ext_data_i");}
}
#endif // VL_DEBUG

void Vcore::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
    n_rst_i = VL_RAND_RESET_I(1);
    ext_data_i = VL_RAND_RESET_I(1);
    result_o = VL_RAND_RESET_I(8);
    halt_o = VL_RAND_RESET_I(1);
    core__DOT__mode_pc = VL_RAND_RESET_I(2);
    core__DOT__flags_alu = 0;
    core__DOT__func_alu = VL_RAND_RESET_I(3);
    core__DOT__wr_en_rf = VL_RAND_RESET_I(1);
    core__DOT__addr_pc = VL_RAND_RESET_I(10);
    core__DOT__instruction = VL_RAND_RESET_I(24);
    core__DOT__rs_data = VL_RAND_RESET_I(8);
    core__DOT__rd_data = VL_RAND_RESET_I(8);
    core__DOT____Vcellinp__alu0__a_i = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    core__DOT__rom0__DOT__rom[__Vi0] = VL_RAND_RESET_I(24);
    }}
    { int __Vi0=0; for (; __Vi0<31; ++__Vi0) {
	    core__DOT__rf0__DOT__regs[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    core__DOT__rf0__DOT__regs_rd[__Vi0] = VL_RAND_RESET_I(8);
    }}
    core__DOT__rf0__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    core__DOT__alu0__DOT__sub = VL_RAND_RESET_I(1);
    core__DOT__alu0__DOT__tmp = VL_RAND_RESET_I(10);
    core__DOT__alu0__DOT__r_as = VL_RAND_RESET_I(9);
    __Vdly__core__DOT__addr_pc = VL_RAND_RESET_I(10);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
