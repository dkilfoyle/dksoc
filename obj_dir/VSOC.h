// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSOC_H_
#define _VSOC_H_  // guard

#include "verilated_heavy.h"

//==========

class VSOC__Syms;

//----------

VL_MODULE(VSOC) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(RESET,0,0);
    VL_OUT8(LEDS,4,0);
    VL_IN8(RXD,0,0);
    VL_OUT8(TXD,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ SOC__DOT__resetn;
    CData/*3:0*/ SOC__DOT__mem_wmask;
    CData/*0:0*/ SOC__DOT__uart_valid;
    CData/*0:0*/ SOC__DOT__uart_ready;
    CData/*0:0*/ SOC__DOT__CPU__DOT__isLoad;
    CData/*0:0*/ SOC__DOT__CPU__DOT__isStore;
    CData/*0:0*/ SOC__DOT__CPU__DOT__isSYSTEM;
    CData/*4:0*/ SOC__DOT__CPU__DOT__rs2Id;
    CData/*4:0*/ SOC__DOT__CPU__DOT__rs1Id;
    CData/*4:0*/ SOC__DOT__CPU__DOT__rdId;
    CData/*0:0*/ SOC__DOT__CPU__DOT__writeBackEn;
    CData/*0:0*/ SOC__DOT__CPU__DOT__LT;
    CData/*0:0*/ SOC__DOT__CPU__DOT__takeBranch;
    CData/*0:0*/ SOC__DOT__CPU__DOT__LOAD_sign;
    CData/*2:0*/ SOC__DOT__CPU__DOT__state;
    CData/*4:0*/ SOC__DOT__UART__DOT__cnt;
    SData/*15:0*/ SOC__DOT__CPU__DOT__LOAD_halfword;
    SData/*15:0*/ SOC__DOT__CPU__DOT__LOAD_byte;
    SData/*9:0*/ SOC__DOT__UART__DOT__data;
    SData/*15:0*/ SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt;
    IData/*31:0*/ SOC__DOT__mem_addr;
    IData/*31:0*/ SOC__DOT__mem_rdata;
    IData/*31:0*/ SOC__DOT__mem_wdata;
    IData/*31:0*/ SOC__DOT__RAM_rdata;
    IData/*31:0*/ SOC__DOT__CPU__DOT__PC;
    IData/*31:0*/ SOC__DOT__CPU__DOT__instr;
    IData/*31:0*/ SOC__DOT__CPU__DOT__Iimm;
    IData/*31:0*/ SOC__DOT__CPU__DOT__rs1;
    IData/*31:0*/ SOC__DOT__CPU__DOT__rs2;
    IData/*31:0*/ SOC__DOT__CPU__DOT__writeBackData;
    IData/*31:0*/ SOC__DOT__CPU__DOT__aluIn2;
    IData/*31:0*/ SOC__DOT__CPU__DOT__aluPlus;
    IData/*31:0*/ SOC__DOT__CPU__DOT__shifter;
    IData/*31:0*/ SOC__DOT__CPU__DOT__shifter_in;
    IData/*31:0*/ SOC__DOT__CPU__DOT__leftshift;
    IData/*31:0*/ SOC__DOT__CPU__DOT__PCplusImm;
    IData/*31:0*/ SOC__DOT__CPU__DOT__nextPC;
    IData/*31:0*/ SOC__DOT__CPU__DOT__loadstore_addr;
    QData/*32:0*/ SOC__DOT__CPU__DOT__aluMinus;
    IData/*31:0*/ SOC__DOT__CPU__DOT__RegisterBank[32];
    IData/*31:0*/ SOC__DOT__RAM__DOT__MEM[1536];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*3:0*/ SOC__DOT____Vcellinp__RAM__mem_wmask;
    CData/*7:0*/ SOC__DOT__RAM__DOT____Vlvbound1;
    CData/*7:0*/ SOC__DOT__RAM__DOT____Vlvbound2;
    CData/*7:0*/ SOC__DOT__RAM__DOT____Vlvbound3;
    CData/*7:0*/ SOC__DOT__RAM__DOT____Vlvbound4;
    CData/*5:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__CLK;
    CData/*0:0*/ __Vclklast__TOP__RESET;
    SData/*15:0*/ __Vdly__SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt;
    IData/*31:0*/ __Vfunc_SOC__DOT__CPU__DOT__flip32__0__Vfuncout;
    IData/*31:0*/ __Vfunc_SOC__DOT__CPU__DOT__flip32__0__x;
    IData/*31:0*/ __Vfunc_SOC__DOT__CPU__DOT__flip32__1__Vfuncout;
    IData/*31:0*/ __Vfunc_SOC__DOT__CPU__DOT__flip32__1__x;
    static CData/*0:0*/ __Vtable1_SOC__DOT__CPU__DOT__takeBranch[64];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSOC__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSOC);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VSOC(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VSOC();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VSOC__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VSOC__Syms* symsp, bool first);
  private:
    static QData _change_request(VSOC__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VSOC__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSOC__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSOC__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VSOC__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VSOC__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(VSOC__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(VSOC__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(VSOC__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
