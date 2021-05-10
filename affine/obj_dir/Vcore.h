// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vcore_H_
#define _Vcore_H_

#include "verilated.h"

class Vcore__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vcore) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(n_rst_i,0,0);
    VL_IN8(clk_i,0,0);
    VL_IN8(ext_data_i,7,0);
    VL_OUT8(ext_data_o,7,0);
    VL_OUT8(prog_addr_o,1,0);
    VL_OUT8(halt_o,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(core__DOT__clk_h,0,0);
    VL_SIG8(core__DOT__halt_r,0,0);
    VL_SIG8(core__DOT__pc_addr,1,0);
    VL_SIG8(core__DOT__alu_op,5,0);
    VL_SIG8(core__DOT__wd_data,7,0);
    VL_SIG8(core__DOT__rd_data,7,0);
    VL_SIG8(core__DOT__r0__DOT__refresh_clk,0,0);
    VL_SIG8(core__DOT__a0__DOT__mul1_a,7,0);
    VL_SIG8(core__DOT__a0__DOT__mul1_rs,7,0);
    VL_SIG8(core__DOT__a0__DOT__mul2_a,7,0);
    VL_SIG8(core__DOT__a0__DOT__mul2_rs,7,0);
    VL_SIG8(core__DOT__a0__DOT__add1_b,7,0);
    VL_SIG8(core__DOT__a0__DOT__add2_b,7,0);
    VL_SIG16(core__DOT__a0__DOT__mul1_r,15,0);
    VL_SIG16(core__DOT__a0__DOT__mul2_r,15,0);
    VL_SIG(core__DOT__rom_data,25,0);
    VL_SIG(core__DOT__r0__DOT__rom[4],25,0);
    VL_SIG8(core__DOT__f0__DOT__regs[4],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__core__DOT__clk_h,0,0);
    VL_SIG8(__Vclklast__TOP__n_rst_i,0,0);
    VL_SIG8(__Vchglast__TOP__core__DOT__halt_r,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcore__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcore);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcore(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcore();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcore__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcore__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcore__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vcore__Syms* __restrict vlSymsp);
    static void _combo__TOP__7(Vcore__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vcore__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vcore__Syms* __restrict vlSymsp);
    static void _eval_settle(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vcore__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vcore__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vcore__Syms* __restrict vlSymsp);
    static void traceChgThis(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vcore__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
