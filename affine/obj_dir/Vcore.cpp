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

VL_INLINE_OPT void Vcore::_combo__TOP__1(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_combo__TOP__1\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->halt_o = vlTOPp->core__DOT__halt_r;
    vlTOPp->core__DOT__clk_h = (1U & ((1U & ((IData)(vlTOPp->core__DOT__halt_r) 
					     | (~ (IData)(vlTOPp->n_rst_i))))
				       ? 0U : (IData)(vlTOPp->clk_i)));
}

void Vcore::_settle__TOP__2(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_settle__TOP__2\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->halt_o = vlTOPp->core__DOT__halt_r;
    vlTOPp->core__DOT__r0__DOT__rom[0U] = 0x14014ecU;
    vlTOPp->core__DOT__r0__DOT__rom[1U] = 0x3904060U;
    vlTOPp->core__DOT__r0__DOT__rom[2U] = 0x39560c0U;
    vlTOPp->core__DOT__r0__DOT__rom[3U] = 0x840100U;
    vlTOPp->core__DOT__clk_h = (1U & ((1U & ((IData)(vlTOPp->core__DOT__halt_r) 
					     | (~ (IData)(vlTOPp->n_rst_i))))
				       ? 0U : (IData)(vlTOPp->clk_i)));
    vlTOPp->prog_addr_o = vlTOPp->core__DOT__pc_addr;
    vlTOPp->ext_data_o = ((IData)(vlTOPp->n_rst_i) ? 
			  vlTOPp->core__DOT__f0__DOT__regs
			  [2U] : vlTOPp->core__DOT__f0__DOT__regs
			  [3U]);
}

VL_INLINE_OPT void Vcore::_sequent__TOP__3(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__3\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at core.sv:12
    if (vlTOPp->n_rst_i) {
	if ((3U == (IData)(vlTOPp->core__DOT__pc_addr))) {
	    vlTOPp->core__DOT__halt_r = 1U;
	}
    } else {
	vlTOPp->core__DOT__halt_r = 0U;
    }
    // ALWAYS at pc.sv:6
    vlTOPp->core__DOT__pc_addr = (3U & ((IData)(vlTOPp->n_rst_i)
					 ? ((IData)(1U) 
					    + (IData)(vlTOPp->core__DOT__pc_addr))
					 : 0U));
    vlTOPp->prog_addr_o = vlTOPp->core__DOT__pc_addr;
}

VL_INLINE_OPT void Vcore::_sequent__TOP__4(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__4\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__core__DOT__f0__DOT__regs__v0,1,0);
    VL_SIG8(__Vdlyvval__core__DOT__f0__DOT__regs__v0,7,0);
    VL_SIG8(__Vdlyvset__core__DOT__f0__DOT__regs__v0,0,0);
    VL_SIG8(__Vdlyvval__core__DOT__f0__DOT__regs__v1,7,0);
    VL_SIG8(__Vdlyvset__core__DOT__f0__DOT__regs__v1,0,0);
    VL_SIG8(__Vdlyvval__core__DOT__f0__DOT__regs__v2,7,0);
    VL_SIG8(__Vdlyvval__core__DOT__f0__DOT__regs__v3,7,0);
    // Body
    __Vdlyvset__core__DOT__f0__DOT__regs__v0 = 0U;
    __Vdlyvset__core__DOT__f0__DOT__regs__v1 = 0U;
    // ALWAYS at rf.sv:17
    if (((~ ((IData)(vlTOPp->core__DOT__alu_op) >> 4U)) 
	 & (0U != (3U & (vlTOPp->core__DOT__rom_data 
			 >> 0x12U))))) {
	__Vdlyvval__core__DOT__f0__DOT__regs__v0 = vlTOPp->core__DOT__wd_data;
	__Vdlyvset__core__DOT__f0__DOT__regs__v0 = 1U;
	__Vdlyvdim0__core__DOT__f0__DOT__regs__v0 = 
	    (3U & (vlTOPp->core__DOT__rom_data >> 0x12U));
    } else {
	if ((0x10U & (IData)(vlTOPp->core__DOT__alu_op))) {
	    __Vdlyvval__core__DOT__f0__DOT__regs__v1 
		= vlTOPp->core__DOT__wd_data;
	    __Vdlyvset__core__DOT__f0__DOT__regs__v1 = 1U;
	    __Vdlyvval__core__DOT__f0__DOT__regs__v2 
		= (0xffU & ((IData)(vlTOPp->core__DOT__a0__DOT__mul2_rs) 
			    + (IData)(vlTOPp->core__DOT__a0__DOT__add2_b)));
	}
    }
    __Vdlyvval__core__DOT__f0__DOT__regs__v3 = vlTOPp->ext_data_i;
    // ALWAYSPOST at rf.sv:19
    if (__Vdlyvset__core__DOT__f0__DOT__regs__v0) {
	vlTOPp->core__DOT__f0__DOT__regs[__Vdlyvdim0__core__DOT__f0__DOT__regs__v0] 
	    = __Vdlyvval__core__DOT__f0__DOT__regs__v0;
    }
    if (__Vdlyvset__core__DOT__f0__DOT__regs__v1) {
	vlTOPp->core__DOT__f0__DOT__regs[2U] = __Vdlyvval__core__DOT__f0__DOT__regs__v1;
	vlTOPp->core__DOT__f0__DOT__regs[3U] = __Vdlyvval__core__DOT__f0__DOT__regs__v2;
    }
    vlTOPp->core__DOT__f0__DOT__regs[0U] = __Vdlyvval__core__DOT__f0__DOT__regs__v3;
}

VL_INLINE_OPT void Vcore::_settle__TOP__5(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_settle__TOP__5\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->core__DOT__rom_data = vlTOPp->core__DOT__r0__DOT__rom
	[vlTOPp->core__DOT__pc_addr];
    // ALWAYS at rf.sv:27
    vlTOPp->core__DOT__rd_data = vlTOPp->core__DOT__f0__DOT__regs
	[(3U & (vlTOPp->core__DOT__rom_data >> 0x12U))];
    // ALWAYS at core.sv:31
    vlTOPp->core__DOT__alu_op = ((0x1fU & (IData)(vlTOPp->core__DOT__alu_op)) 
				 | (0x20U & (vlTOPp->core__DOT__rom_data 
					     >> 0x14U)));
    vlTOPp->core__DOT__alu_op = ((0x2fU & (IData)(vlTOPp->core__DOT__alu_op)) 
				 | (0x10U & (vlTOPp->core__DOT__rom_data 
					     >> 0x14U)));
    vlTOPp->core__DOT__alu_op = ((0x33U & (IData)(vlTOPp->core__DOT__alu_op)) 
				 | (0xcU & (vlTOPp->core__DOT__rom_data 
					    >> 0x14U)));
    vlTOPp->core__DOT__alu_op = ((0x3cU & (IData)(vlTOPp->core__DOT__alu_op)) 
				 | (3U & (vlTOPp->core__DOT__rom_data 
					  >> 0x14U)));
    // ALWAYS at dalu.sv:54
    if ((0U == (1U & (IData)(vlTOPp->core__DOT__alu_op)))) {
	vlTOPp->core__DOT__a0__DOT__add2_b = 0U;
    } else {
	if ((1U == (1U & (IData)(vlTOPp->core__DOT__alu_op)))) {
	    vlTOPp->core__DOT__a0__DOT__add2_b = vlTOPp->core__DOT__f0__DOT__regs
		[3U];
	}
    }
    // ALWAYS at dalu.sv:16
    if ((0U == (3U & ((IData)(vlTOPp->core__DOT__alu_op) 
		      >> 2U)))) {
	vlTOPp->core__DOT__a0__DOT__mul1_a = 0U;
    } else {
	if ((1U == (3U & ((IData)(vlTOPp->core__DOT__alu_op) 
			  >> 2U)))) {
	    vlTOPp->core__DOT__a0__DOT__mul1_a = 1U;
	} else {
	    if ((2U == (2U & ((IData)(vlTOPp->core__DOT__alu_op) 
			      >> 2U)))) {
		vlTOPp->core__DOT__a0__DOT__mul1_a 
		    = vlTOPp->core__DOT__f0__DOT__regs
		    [(3U & (vlTOPp->core__DOT__rom_data 
			    >> 0x10U))];
	    }
	}
    }
    // ALWAYS at dalu.sv:27
    if ((0U == (3U & ((IData)(vlTOPp->core__DOT__alu_op) 
		      >> 2U)))) {
	vlTOPp->core__DOT__a0__DOT__mul2_a = 0U;
    } else {
	if ((1U == (3U & ((IData)(vlTOPp->core__DOT__alu_op) 
			  >> 2U)))) {
	    vlTOPp->core__DOT__a0__DOT__mul2_a = 1U;
	} else {
	    if ((2U == (2U & ((IData)(vlTOPp->core__DOT__alu_op) 
			      >> 2U)))) {
		vlTOPp->core__DOT__a0__DOT__mul2_a 
		    = vlTOPp->core__DOT__rd_data;
	    }
	}
    }
    // ALWAYS at dalu.sv:36
    vlTOPp->core__DOT__a0__DOT__mul1_r = (0xffffU & 
					  VL_MULS_III(16,16,16, 
						      (0xffffU 
						       & VL_EXTENDS_II(16,8, (IData)(vlTOPp->core__DOT__a0__DOT__mul1_a))), 
						      (0xffffU 
						       & VL_EXTENDS_II(16,8, 
								       (0xffU 
									& ((3U 
									    == 
									    (3U 
									     & ((IData)(vlTOPp->core__DOT__alu_op) 
										>> 2U)))
									    ? (IData)(vlTOPp->core__DOT__rd_data)
									    : 
									   (vlTOPp->core__DOT__rom_data 
									    >> 8U)))))));
    vlTOPp->core__DOT__a0__DOT__mul1_rs = (0xffU & 
					   ((0x20U 
					     & (IData)(vlTOPp->core__DOT__alu_op))
					     ? ((IData)(vlTOPp->core__DOT__a0__DOT__mul1_r) 
						>> 7U)
					     : (IData)(vlTOPp->core__DOT__a0__DOT__mul1_r)));
    // ALWAYS at dalu.sv:36
    vlTOPp->core__DOT__a0__DOT__mul2_r = (0xffffU & 
					  VL_MULS_III(16,16,16, 
						      (0xffffU 
						       & VL_EXTENDS_II(16,8, (IData)(vlTOPp->core__DOT__a0__DOT__mul2_a))), 
						      (0xffffU 
						       & VL_EXTENDS_II(16,8, 
								       (0xffU 
									& vlTOPp->core__DOT__rom_data)))));
    vlTOPp->core__DOT__a0__DOT__mul2_rs = (0xffU & 
					   ((0x20U 
					     & (IData)(vlTOPp->core__DOT__alu_op))
					     ? ((IData)(vlTOPp->core__DOT__a0__DOT__mul2_r) 
						>> 7U)
					     : (IData)(vlTOPp->core__DOT__a0__DOT__mul2_r)));
    // ALWAYS at dalu.sv:44
    if ((0U == (3U & (IData)(vlTOPp->core__DOT__alu_op)))) {
	vlTOPp->core__DOT__a0__DOT__add1_b = 0U;
    } else {
	if ((1U == (3U & (IData)(vlTOPp->core__DOT__alu_op)))) {
	    vlTOPp->core__DOT__a0__DOT__add1_b = vlTOPp->core__DOT__f0__DOT__regs
		[2U];
	} else {
	    if ((2U == (2U & (IData)(vlTOPp->core__DOT__alu_op)))) {
		vlTOPp->core__DOT__a0__DOT__add1_b 
		    = vlTOPp->core__DOT__a0__DOT__mul2_rs;
	    }
	}
    }
    vlTOPp->core__DOT__wd_data = (0xffU & ((IData)(vlTOPp->core__DOT__a0__DOT__mul1_rs) 
					   + (IData)(vlTOPp->core__DOT__a0__DOT__add1_b)));
}

VL_INLINE_OPT void Vcore::_combo__TOP__7(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_combo__TOP__7\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ext_data_o = ((IData)(vlTOPp->n_rst_i) ? 
			  vlTOPp->core__DOT__f0__DOT__regs
			  [2U] : vlTOPp->core__DOT__f0__DOT__regs
			  [3U]);
}

void Vcore::_eval(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if ((((IData)(vlTOPp->core__DOT__clk_h) & (~ (IData)(vlTOPp->__Vclklast__TOP__core__DOT__clk_h))) 
	 | ((~ (IData)(vlTOPp->n_rst_i)) & (IData)(vlTOPp->__Vclklast__TOP__n_rst_i)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->core__DOT__clk_h) & (~ (IData)(vlTOPp->__Vclklast__TOP__core__DOT__clk_h)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
	vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->core__DOT__clk_h) & (~ (IData)(vlTOPp->__Vclklast__TOP__core__DOT__clk_h))) 
	 | ((~ (IData)(vlTOPp->n_rst_i)) & (IData)(vlTOPp->__Vclklast__TOP__n_rst_i)))) {
	vlTOPp->_settle__TOP__5(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__core__DOT__clk_h = vlTOPp->core__DOT__clk_h;
    vlTOPp->__Vclklast__TOP__n_rst_i = vlTOPp->n_rst_i;
}

void Vcore::_eval_initial(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval_initial\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__core__DOT__clk_h = vlTOPp->core__DOT__clk_h;
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
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

VL_INLINE_OPT QData Vcore::_change_request(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_change_request\n"); );
    Vcore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->core__DOT__halt_r ^ vlTOPp->__Vchglast__TOP__core__DOT__halt_r));
    VL_DEBUG_IF( if(__req && ((vlTOPp->core__DOT__halt_r ^ vlTOPp->__Vchglast__TOP__core__DOT__halt_r))) VL_DBG_MSGF("        CHANGE: core.sv:9: core.halt_r\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__core__DOT__halt_r = vlTOPp->core__DOT__halt_r;
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
}
#endif // VL_DEBUG

void Vcore::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
    n_rst_i = VL_RAND_RESET_I(1);
    ext_data_i = VL_RAND_RESET_I(8);
    ext_data_o = VL_RAND_RESET_I(8);
    prog_addr_o = VL_RAND_RESET_I(2);
    halt_o = VL_RAND_RESET_I(1);
    core__DOT__clk_h = VL_RAND_RESET_I(1);
    core__DOT__halt_r = VL_RAND_RESET_I(1);
    core__DOT__pc_addr = VL_RAND_RESET_I(2);
    core__DOT__rom_data = VL_RAND_RESET_I(26);
    core__DOT__alu_op = 0;
    core__DOT__wd_data = VL_RAND_RESET_I(8);
    core__DOT__rd_data = VL_RAND_RESET_I(8);
    core__DOT__r0__DOT__refresh_clk = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    core__DOT__r0__DOT__rom[__Vi0] = VL_RAND_RESET_I(26);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    core__DOT__f0__DOT__regs[__Vi0] = VL_RAND_RESET_I(8);
    }}
    core__DOT__a0__DOT__mul1_a = VL_RAND_RESET_I(8);
    core__DOT__a0__DOT__mul1_rs = VL_RAND_RESET_I(8);
    core__DOT__a0__DOT__mul1_r = VL_RAND_RESET_I(16);
    core__DOT__a0__DOT__mul2_a = VL_RAND_RESET_I(8);
    core__DOT__a0__DOT__mul2_rs = VL_RAND_RESET_I(8);
    core__DOT__a0__DOT__mul2_r = VL_RAND_RESET_I(16);
    core__DOT__a0__DOT__add1_b = VL_RAND_RESET_I(8);
    core__DOT__a0__DOT__add2_b = VL_RAND_RESET_I(8);
    __Vchglast__TOP__core__DOT__halt_r = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
