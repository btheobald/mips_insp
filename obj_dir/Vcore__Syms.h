// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vcore__Syms_H_
#define _Vcore__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vcore.h"

// SYMS CLASS
class Vcore__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vcore*                         TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_core__dec0;
    
    // CREATORS
    Vcore__Syms(Vcore* topp, const char* namep);
    ~Vcore__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
