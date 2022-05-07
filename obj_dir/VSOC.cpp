// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSOC.h for the primary calling header

#include "VSOC.h"
#include "VSOC__Syms.h"

//==========
CData/*0:0*/ VSOC::__Vtable1_SOC__DOT__CPU__DOT__takeBranch[64];

VL_CTOR_IMP(VSOC) {
    VSOC__Syms* __restrict vlSymsp = __VlSymsp = new VSOC__Syms(this, name());
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VSOC::__Vconfigure(VSOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VSOC::~VSOC() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VSOC::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSOC::eval\n"); );
    VSOC__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("soc.v", 294, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSOC::_eval_initial_loop(VSOC__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
            VL_FATAL_MT("soc.v", 294, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSOC::_initial__TOP__1(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_initial__TOP__1\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    // Body
    vlTOPp->SOC__DOT__CPU__DOT__PC = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[1U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[2U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[3U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[4U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[5U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[6U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[7U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[8U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[9U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0xaU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0xbU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0xcU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0xdU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0xeU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0xfU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x10U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x11U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x12U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x13U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x14U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x15U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x16U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x17U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x18U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x19U] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x1aU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x1bU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x1cU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x1dU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x1eU] = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[0x1fU] = 0U;
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x77617265U;
    __Vtemp1[2U] = 0x6669726dU;
    VL_READMEM_N(true, 32, 1536, 0, VL_CVT_PACK_STR_NW(3, __Vtemp1)
                 , vlTOPp->SOC__DOT__RAM__DOT__MEM, 0
                 , ~VL_ULL(0));
    vlTOPp->SOC__DOT__UART__DOT__cnt = 0U;
    vlTOPp->SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt = 0U;
    vlTOPp->SOC__DOT__CPU__DOT__state = 0U;
}

VL_INLINE_OPT void VSOC::_sequent__TOP__2(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_sequent__TOP__2\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt 
        = vlTOPp->SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt;
    vlTOPp->__Vdly__SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt 
        = ((IData)(vlTOPp->RESET) ? 0U : (0xffffU & 
                                          ((IData)(vlTOPp->SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt) 
                                           + (1U & 
                                              (~ (IData)(vlTOPp->SOC__DOT__resetn))))));
}

VL_INLINE_OPT void VSOC::_sequent__TOP__3(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_sequent__TOP__3\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__SOC__DOT__CPU__DOT__state;
    CData/*4:0*/ __Vdlyvdim0__SOC__DOT__CPU__DOT__RegisterBank__v0;
    CData/*0:0*/ __Vdlyvset__SOC__DOT__CPU__DOT__RegisterBank__v0;
    CData/*4:0*/ __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v0;
    CData/*7:0*/ __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v0;
    CData/*0:0*/ __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v0;
    CData/*4:0*/ __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v1;
    CData/*7:0*/ __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v1;
    CData/*0:0*/ __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v1;
    CData/*4:0*/ __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v2;
    CData/*7:0*/ __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v2;
    CData/*0:0*/ __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v2;
    CData/*4:0*/ __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v3;
    CData/*7:0*/ __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v3;
    CData/*0:0*/ __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v3;
    CData/*0:0*/ __Vdly__SOC__DOT__uart_ready;
    CData/*4:0*/ __Vdly__SOC__DOT__UART__DOT__cnt;
    SData/*10:0*/ __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v0;
    SData/*10:0*/ __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v1;
    SData/*10:0*/ __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v2;
    SData/*10:0*/ __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v3;
    IData/*31:0*/ __Vdlyvval__SOC__DOT__CPU__DOT__RegisterBank__v0;
    // Body
    __Vdly__SOC__DOT__UART__DOT__cnt = vlTOPp->SOC__DOT__UART__DOT__cnt;
    __Vdly__SOC__DOT__uart_ready = vlTOPp->SOC__DOT__uart_ready;
    __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v0 = 0U;
    __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v1 = 0U;
    __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v2 = 0U;
    __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v3 = 0U;
    __Vdlyvset__SOC__DOT__CPU__DOT__RegisterBank__v0 = 0U;
    __Vdly__SOC__DOT__CPU__DOT__state = vlTOPp->SOC__DOT__CPU__DOT__state;
    if (VL_UNLIKELY(vlTOPp->SOC__DOT__uart_valid)) {
        VL_WRITEF("%c",8,(0xffU & vlTOPp->SOC__DOT__mem_wdata));
        if (0x80000001U) { fflush(VL_CVT_I_FP(0x80000001U)); }
    }
    if ((((vlTOPp->SOC__DOT__mem_addr >> 0x16U) & (0U 
                                                   != (IData)(vlTOPp->SOC__DOT__mem_wmask))) 
         & (vlTOPp->SOC__DOT__mem_addr >> 2U))) {
        vlTOPp->LEDS = (0x1fU & vlTOPp->SOC__DOT__mem_wdata);
    }
    if ((1U & (((IData)(vlTOPp->SOC__DOT__UART__DOT__cnt) 
                >> 4U) & (~ (IData)((0U != (IData)(vlTOPp->SOC__DOT__UART__DOT__data))))))) {
        __Vdly__SOC__DOT__uart_ready = 1U;
    } else {
        if (((IData)(vlTOPp->SOC__DOT__uart_valid) 
             & (IData)(vlTOPp->SOC__DOT__uart_ready))) {
            __Vdly__SOC__DOT__uart_ready = 0U;
        }
    }
    __Vdly__SOC__DOT__UART__DOT__cnt = ((1U & ((IData)(vlTOPp->SOC__DOT__uart_ready) 
                                               | ((IData)(vlTOPp->SOC__DOT__UART__DOT__cnt) 
                                                  >> 4U)))
                                         ? 0xaU : (0x1fU 
                                                   & ((IData)(vlTOPp->SOC__DOT__UART__DOT__cnt) 
                                                      - (IData)(1U))));
    if ((0x10U & (IData)(vlTOPp->SOC__DOT__UART__DOT__cnt))) {
        vlTOPp->SOC__DOT__UART__DOT__data = (0x1ffU 
                                             & ((IData)(vlTOPp->SOC__DOT__UART__DOT__data) 
                                                >> 1U));
    } else {
        if (((IData)(vlTOPp->SOC__DOT__uart_valid) 
             & (IData)(vlTOPp->SOC__DOT__uart_ready))) {
            vlTOPp->SOC__DOT__UART__DOT__data = (0x200U 
                                                 | (0x1feU 
                                                    & (vlTOPp->SOC__DOT__mem_wdata 
                                                       << 1U)));
        }
    }
    if (((~ (vlTOPp->SOC__DOT__mem_addr >> 0x16U)) 
         & ((0U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)) 
            | (4U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))))) {
        vlTOPp->SOC__DOT__RAM_rdata = ((0x5ffU >= (0x7ffU 
                                                   & (vlTOPp->SOC__DOT__mem_addr 
                                                      >> 2U)))
                                        ? vlTOPp->SOC__DOT__RAM__DOT__MEM
                                       [(0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                                                   >> 2U))]
                                        : 0U);
    }
    if ((1U & (IData)(vlTOPp->SOC__DOT____Vcellinp__RAM__mem_wmask))) {
        vlTOPp->SOC__DOT__RAM__DOT____Vlvbound1 = (0xffU 
                                                   & vlTOPp->SOC__DOT__mem_wdata);
        if ((0x5ffU >= (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                                  >> 2U)))) {
            __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v0 
                = vlTOPp->SOC__DOT__RAM__DOT____Vlvbound1;
            __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v0 = 1U;
            __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v0 = 0U;
            __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v0 
                = (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                             >> 2U));
        }
    }
    if ((2U & (IData)(vlTOPp->SOC__DOT____Vcellinp__RAM__mem_wmask))) {
        vlTOPp->SOC__DOT__RAM__DOT____Vlvbound2 = (0xffU 
                                                   & (vlTOPp->SOC__DOT__mem_wdata 
                                                      >> 8U));
        if ((0x5ffU >= (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                                  >> 2U)))) {
            __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v1 
                = vlTOPp->SOC__DOT__RAM__DOT____Vlvbound2;
            __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v1 = 1U;
            __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v1 = 8U;
            __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v1 
                = (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                             >> 2U));
        }
    }
    if ((4U & (IData)(vlTOPp->SOC__DOT____Vcellinp__RAM__mem_wmask))) {
        vlTOPp->SOC__DOT__RAM__DOT____Vlvbound3 = (0xffU 
                                                   & (vlTOPp->SOC__DOT__mem_wdata 
                                                      >> 0x10U));
        if ((0x5ffU >= (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                                  >> 2U)))) {
            __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v2 
                = vlTOPp->SOC__DOT__RAM__DOT____Vlvbound3;
            __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v2 = 1U;
            __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v2 = 0x10U;
            __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v2 
                = (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                             >> 2U));
        }
    }
    if ((8U & (IData)(vlTOPp->SOC__DOT____Vcellinp__RAM__mem_wmask))) {
        vlTOPp->SOC__DOT__RAM__DOT____Vlvbound4 = (0xffU 
                                                   & (vlTOPp->SOC__DOT__mem_wdata 
                                                      >> 0x18U));
        if ((0x5ffU >= (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                                  >> 2U)))) {
            __Vdlyvval__SOC__DOT__RAM__DOT__MEM__v3 
                = vlTOPp->SOC__DOT__RAM__DOT____Vlvbound4;
            __Vdlyvset__SOC__DOT__RAM__DOT__MEM__v3 = 1U;
            __Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v3 = 0x18U;
            __Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v3 
                = (0x7ffU & (vlTOPp->SOC__DOT__mem_addr 
                             >> 2U));
        }
    }
    if ((0xffffU == (IData)(vlTOPp->SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt))) {
        if ((0U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))) {
            __Vdly__SOC__DOT__CPU__DOT__state = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))) {
                vlTOPp->SOC__DOT__CPU__DOT__instr = vlTOPp->SOC__DOT__mem_rdata;
                __Vdly__SOC__DOT__CPU__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))) {
                    vlTOPp->SOC__DOT__CPU__DOT__rs1 
                        = vlTOPp->SOC__DOT__CPU__DOT__RegisterBank
                        [vlTOPp->SOC__DOT__CPU__DOT__rs1Id];
                    __Vdly__SOC__DOT__CPU__DOT__state = 3U;
                    vlTOPp->SOC__DOT__CPU__DOT__rs2 
                        = vlTOPp->SOC__DOT__CPU__DOT__RegisterBank
                        [vlTOPp->SOC__DOT__CPU__DOT__rs2Id];
                } else {
                    if ((3U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))) {
                        if (VL_UNLIKELY(vlTOPp->SOC__DOT__CPU__DOT__isSYSTEM)) {
                            VL_FINISH_MT("soc.v", 251, "");
                        }
                        if ((1U & (~ (IData)(vlTOPp->SOC__DOT__CPU__DOT__isSYSTEM)))) {
                            vlTOPp->SOC__DOT__CPU__DOT__PC 
                                = vlTOPp->SOC__DOT__CPU__DOT__nextPC;
                        }
                        __Vdly__SOC__DOT__CPU__DOT__state 
                            = ((IData)(vlTOPp->SOC__DOT__CPU__DOT__isLoad)
                                ? 4U : ((IData)(vlTOPp->SOC__DOT__CPU__DOT__isStore)
                                         ? 6U : 0U));
                    } else {
                        if ((4U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))) {
                            __Vdly__SOC__DOT__CPU__DOT__state = 5U;
                        } else {
                            if ((5U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))) {
                                __Vdly__SOC__DOT__CPU__DOT__state = 0U;
                            } else {
                                if ((6U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state))) {
                                    __Vdly__SOC__DOT__CPU__DOT__state = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (((IData)(vlTOPp->SOC__DOT__CPU__DOT__writeBackEn) 
             & (0U != (IData)(vlTOPp->SOC__DOT__CPU__DOT__rdId)))) {
            __Vdlyvval__SOC__DOT__CPU__DOT__RegisterBank__v0 
                = vlTOPp->SOC__DOT__CPU__DOT__writeBackData;
            __Vdlyvset__SOC__DOT__CPU__DOT__RegisterBank__v0 = 1U;
            __Vdlyvdim0__SOC__DOT__CPU__DOT__RegisterBank__v0 
                = vlTOPp->SOC__DOT__CPU__DOT__rdId;
        }
    } else {
        vlTOPp->SOC__DOT__CPU__DOT__PC = 0U;
        __Vdly__SOC__DOT__CPU__DOT__state = 0U;
    }
    vlTOPp->SOC__DOT__UART__DOT__cnt = __Vdly__SOC__DOT__UART__DOT__cnt;
    vlTOPp->SOC__DOT__uart_ready = __Vdly__SOC__DOT__uart_ready;
    if (__Vdlyvset__SOC__DOT__RAM__DOT__MEM__v0) {
        vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v0))) 
                & vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v0]) 
               | ((IData)(__Vdlyvval__SOC__DOT__RAM__DOT__MEM__v0) 
                  << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v0)));
    }
    if (__Vdlyvset__SOC__DOT__RAM__DOT__MEM__v1) {
        vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v1))) 
                & vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v1]) 
               | ((IData)(__Vdlyvval__SOC__DOT__RAM__DOT__MEM__v1) 
                  << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v1)));
    }
    if (__Vdlyvset__SOC__DOT__RAM__DOT__MEM__v2) {
        vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v2))) 
                & vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v2]) 
               | ((IData)(__Vdlyvval__SOC__DOT__RAM__DOT__MEM__v2) 
                  << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v2)));
    }
    if (__Vdlyvset__SOC__DOT__RAM__DOT__MEM__v3) {
        vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v3))) 
                & vlTOPp->SOC__DOT__RAM__DOT__MEM[__Vdlyvdim0__SOC__DOT__RAM__DOT__MEM__v3]) 
               | ((IData)(__Vdlyvval__SOC__DOT__RAM__DOT__MEM__v3) 
                  << (IData)(__Vdlyvlsb__SOC__DOT__RAM__DOT__MEM__v3)));
    }
    if (__Vdlyvset__SOC__DOT__CPU__DOT__RegisterBank__v0) {
        vlTOPp->SOC__DOT__CPU__DOT__RegisterBank[__Vdlyvdim0__SOC__DOT__CPU__DOT__RegisterBank__v0] 
            = __Vdlyvval__SOC__DOT__CPU__DOT__RegisterBank__v0;
    }
    vlTOPp->SOC__DOT__CPU__DOT__state = __Vdly__SOC__DOT__CPU__DOT__state;
    vlTOPp->TXD = (1U & ((IData)(vlTOPp->SOC__DOT__UART__DOT__data) 
                         | (~ (IData)((0U != (IData)(vlTOPp->SOC__DOT__UART__DOT__data))))));
    vlTOPp->SOC__DOT__mem_wdata = ((0xffffff00U & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xffU & vlTOPp->SOC__DOT__CPU__DOT__rs2));
    vlTOPp->SOC__DOT__CPU__DOT__isLoad = (3U == (0x7fU 
                                                 & vlTOPp->SOC__DOT__CPU__DOT__instr));
    vlTOPp->SOC__DOT__CPU__DOT__isStore = (0x23U == 
                                           (0x7fU & vlTOPp->SOC__DOT__CPU__DOT__instr));
    vlTOPp->SOC__DOT__CPU__DOT__isSYSTEM = (0x73U == 
                                            (0x7fU 
                                             & vlTOPp->SOC__DOT__CPU__DOT__instr));
    vlTOPp->SOC__DOT__CPU__DOT__rs2Id = (0x1fU & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                  >> 0x14U));
    vlTOPp->SOC__DOT__CPU__DOT__rs1Id = (0x1fU & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                  >> 0xfU));
    vlTOPp->SOC__DOT__CPU__DOT__rdId = (0x1fU & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                 >> 7U));
    vlTOPp->SOC__DOT__CPU__DOT__writeBackEn = (((((3U 
                                                   == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)) 
                                                  & (0x63U 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr))) 
                                                 & (0x23U 
                                                    != 
                                                    (0x7fU 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr))) 
                                                & (3U 
                                                   != 
                                                   (0x7fU 
                                                    & vlTOPp->SOC__DOT__CPU__DOT__instr))) 
                                               | (5U 
                                                  == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)));
    vlTOPp->SOC__DOT__CPU__DOT__PCplusImm = (vlTOPp->SOC__DOT__CPU__DOT__PC 
                                             + ((8U 
                                                 & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                 ? 
                                                ((0xfff00000U 
                                                  & (VL_NEGATE_I((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                             >> 0x1fU)))) 
                                                     << 0x14U)) 
                                                 | ((0xff000U 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr) 
                                                    | ((0x800U 
                                                        & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                             >> 0x14U)))))
                                                 : 
                                                ((0x10U 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                  ? 
                                                 (0xfffff000U 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                  : 
                                                 ((0xfffff000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                              >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                              >> 7U))))))));
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
        = vlTOPp->SOC__DOT__CPU__DOT__rs1;
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__Vfuncout 
        = ((0x80000000U & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                           << 0x1fU)) | ((0x40000000U 
                                          & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                             << 0x1dU)) 
                                         | ((0x20000000U 
                                             & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                << 0x1bU)) 
                                            | ((0x10000000U 
                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                   << 0x19U)) 
                                               | ((0x8000000U 
                                                   & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                      << 0x17U)) 
                                                  | ((0x4000000U 
                                                      & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                         << 0x15U)) 
                                                     | ((0x2000000U 
                                                         & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                            << 0x13U)) 
                                                        | ((0x1000000U 
                                                            & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                               << 0x11U)) 
                                                           | ((0x800000U 
                                                               & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                  << 0xfU)) 
                                                              | ((0x400000U 
                                                                  & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                     << 0xdU)) 
                                                                 | ((0x200000U 
                                                                     & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                        << 0xbU)) 
                                                                    | ((0x100000U 
                                                                        & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                           << 9U)) 
                                                                       | ((0x80000U 
                                                                           & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                              << 7U)) 
                                                                          | ((0x40000U 
                                                                              & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                << 5U)) 
                                                                             | ((0x20000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                << 3U)) 
                                                                                | ((0x10000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                << 1U)) 
                                                                                | ((0x8000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 1U)) 
                                                                                | ((0x4000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 3U)) 
                                                                                | ((0x2000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))));
    vlTOPp->SOC__DOT__CPU__DOT__shifter_in = ((1U == 
                                               (7U 
                                                & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                   >> 0xcU)))
                                               ? vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__Vfuncout
                                               : vlTOPp->SOC__DOT__CPU__DOT__rs1);
    vlTOPp->SOC__DOT__CPU__DOT__Iimm = ((0xfffff800U 
                                         & (VL_NEGATE_I((IData)(
                                                                (1U 
                                                                 & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                    >> 0x1fU)))) 
                                            << 0xbU)) 
                                        | (0x7ffU & 
                                           (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                            >> 0x14U)));
    vlTOPp->SOC__DOT__CPU__DOT__aluIn2 = (((0x33U == 
                                            (0x7fU 
                                             & vlTOPp->SOC__DOT__CPU__DOT__instr)) 
                                           | (0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)))
                                           ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                           : vlTOPp->SOC__DOT__CPU__DOT__Iimm);
    vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr = (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                  + 
                                                  ((0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                    ? 
                                                   ((0xfffff800U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                                >> 0x1fU)))) 
                                                        << 0xbU)) 
                                                    | ((0x7e0U 
                                                        & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                           >> 0x14U)) 
                                                       | (0x1fU 
                                                          & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                             >> 7U))))
                                                    : vlTOPp->SOC__DOT__CPU__DOT__Iimm));
    vlTOPp->SOC__DOT__CPU__DOT__aluPlus = (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                           + vlTOPp->SOC__DOT__CPU__DOT__aluIn2);
    vlTOPp->SOC__DOT__CPU__DOT__shifter = (IData)((VL_ULL(0x1ffffffff) 
                                                   & VL_SHIFTRS_QQI(33,33,5, 
                                                                    (((QData)((IData)(
                                                                                (1U 
                                                                                & ((vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                                >> 0x1eU) 
                                                                                & (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                                                >> 0x1fU))))) 
                                                                      << 0x20U) 
                                                                     | (QData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__shifter_in))), 
                                                                    (0x1fU 
                                                                     & vlTOPp->SOC__DOT__CPU__DOT__aluIn2))));
    vlTOPp->SOC__DOT__CPU__DOT__aluMinus = (VL_ULL(0x1ffffffff) 
                                            & (VL_ULL(1) 
                                               + ((VL_ULL(0x100000000) 
                                                   | (QData)((IData)(
                                                                     (~ vlTOPp->SOC__DOT__CPU__DOT__aluIn2)))) 
                                                  + (QData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__rs1)))));
    vlTOPp->SOC__DOT__mem_wdata = ((0xffff00ffU & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xff00U & (((1U 
                                                   & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                                   ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                                   : 
                                                  (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                   >> 8U)) 
                                                 << 8U)));
    vlTOPp->SOC__DOT__mem_wdata = ((0xff00ffffU & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xff0000U & (
                                                   ((2U 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                                     ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                                     : 
                                                    (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                     >> 0x10U)) 
                                                   << 0x10U)));
    vlTOPp->SOC__DOT__mem_wdata = ((0xffffffU & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xff000000U & 
                                      (((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                         ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                         : ((2U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                             ? (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                >> 8U)
                                             : (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                >> 0x18U))) 
                                       << 0x18U)));
    vlTOPp->SOC__DOT__mem_wmask = (VL_NEGATE_I((IData)(
                                                       (6U 
                                                        == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)))) 
                                   & ((0U == (3U & 
                                              (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                               >> 0xcU)))
                                       ? ((2U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                           ? ((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                               ? 8U
                                               : 4U)
                                           : ((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                               ? 2U
                                               : 1U))
                                       : ((1U == (3U 
                                                  & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                     >> 0xcU)))
                                           ? ((2U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                               ? 0xcU
                                               : 3U)
                                           : 0xfU)));
    vlTOPp->SOC__DOT__mem_addr = (((1U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)) 
                                   | (0U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)))
                                   ? vlTOPp->SOC__DOT__CPU__DOT__PC
                                   : vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr);
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
        = vlTOPp->SOC__DOT__CPU__DOT__shifter;
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__Vfuncout 
        = ((0x80000000U & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                           << 0x1fU)) | ((0x40000000U 
                                          & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                             << 0x1dU)) 
                                         | ((0x20000000U 
                                             & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                << 0x1bU)) 
                                            | ((0x10000000U 
                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                   << 0x19U)) 
                                               | ((0x8000000U 
                                                   & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                      << 0x17U)) 
                                                  | ((0x4000000U 
                                                      & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                         << 0x15U)) 
                                                     | ((0x2000000U 
                                                         & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                            << 0x13U)) 
                                                        | ((0x1000000U 
                                                            & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                               << 0x11U)) 
                                                           | ((0x800000U 
                                                               & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                  << 0xfU)) 
                                                              | ((0x400000U 
                                                                  & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                     << 0xdU)) 
                                                                 | ((0x200000U 
                                                                     & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                        << 0xbU)) 
                                                                    | ((0x100000U 
                                                                        & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                           << 9U)) 
                                                                       | ((0x80000U 
                                                                           & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                              << 7U)) 
                                                                          | ((0x40000U 
                                                                              & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                << 5U)) 
                                                                             | ((0x20000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                << 3U)) 
                                                                                | ((0x10000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                << 1U)) 
                                                                                | ((0x8000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 1U)) 
                                                                                | ((0x4000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 3U)) 
                                                                                | ((0x2000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))));
    vlTOPp->SOC__DOT__CPU__DOT__leftshift = vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__Vfuncout;
    vlTOPp->SOC__DOT__CPU__DOT__LT = (1U & ((0x80000000U 
                                             & (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                ^ vlTOPp->SOC__DOT__CPU__DOT__aluIn2))
                                             ? (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                >> 0x1fU)
                                             : (IData)(
                                                       (vlTOPp->SOC__DOT__CPU__DOT__aluMinus 
                                                        >> 0x20U))));
    vlTOPp->SOC__DOT____Vcellinp__RAM__mem_wmask = 
        (VL_NEGATE_I((IData)((1U & (~ (vlTOPp->SOC__DOT__mem_addr 
                                       >> 0x16U))))) 
         & (IData)(vlTOPp->SOC__DOT__mem_wmask));
    vlTOPp->SOC__DOT__uart_valid = (((vlTOPp->SOC__DOT__mem_addr 
                                      >> 0x16U) & (0U 
                                                   != (IData)(vlTOPp->SOC__DOT__mem_wmask))) 
                                    & (vlTOPp->SOC__DOT__mem_addr 
                                       >> 3U));
    vlTOPp->SOC__DOT__mem_rdata = ((0x400000U & vlTOPp->SOC__DOT__mem_addr)
                                    ? ((0x10U & vlTOPp->SOC__DOT__mem_addr)
                                        ? (0x200U & 
                                           ((~ (IData)(vlTOPp->SOC__DOT__uart_ready)) 
                                            << 9U))
                                        : 0U) : vlTOPp->SOC__DOT__RAM_rdata);
    vlTOPp->__Vtableidx1 = (((0U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__aluMinus)) 
                             << 5U) | (((IData)(vlTOPp->SOC__DOT__CPU__DOT__LT) 
                                        << 4U) | ((8U 
                                                   & ((IData)(
                                                              (vlTOPp->SOC__DOT__CPU__DOT__aluMinus 
                                                               >> 0x20U)) 
                                                      << 3U)) 
                                                  | (7U 
                                                     & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                        >> 0xcU)))));
    vlTOPp->SOC__DOT__CPU__DOT__takeBranch = vlTOPp->__Vtable1_SOC__DOT__CPU__DOT__takeBranch
        [vlTOPp->__Vtableidx1];
    vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword = (0xffffU 
                                                 & ((2U 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                                     ? 
                                                    (vlTOPp->SOC__DOT__mem_rdata 
                                                     >> 0x10U)
                                                     : vlTOPp->SOC__DOT__mem_rdata));
    vlTOPp->SOC__DOT__CPU__DOT__nextPC = ((((0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->SOC__DOT__CPU__DOT__instr)) 
                                            & (IData)(vlTOPp->SOC__DOT__CPU__DOT__takeBranch)) 
                                           | (0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)))
                                           ? vlTOPp->SOC__DOT__CPU__DOT__PCplusImm
                                           : ((0x67U 
                                               == (0x7fU 
                                                   & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                               ? (0xfffffffeU 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__aluPlus)
                                               : ((IData)(4U) 
                                                  + vlTOPp->SOC__DOT__CPU__DOT__PC)));
    vlTOPp->SOC__DOT__CPU__DOT__LOAD_byte = ((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                              ? (0xffU 
                                                 & ((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword) 
                                                    >> 8U))
                                              : (0xffU 
                                                 & (IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword)));
    vlTOPp->SOC__DOT__CPU__DOT__LOAD_sign = (1U & (
                                                   (~ 
                                                    (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                     >> 0xeU)) 
                                                   & ((0U 
                                                       == 
                                                       (3U 
                                                        & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_byte) 
                                                       >> 7U)
                                                       : 
                                                      ((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword) 
                                                       >> 0xfU))));
    vlTOPp->SOC__DOT__CPU__DOT__writeBackData = (((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SOC__DOT__CPU__DOT__instr)) 
                                                  | (0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr)))
                                                  ? 
                                                 ((IData)(4U) 
                                                  + vlTOPp->SOC__DOT__CPU__DOT__PC)
                                                  : 
                                                 ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                   : 
                                                  ((0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                    ? vlTOPp->SOC__DOT__CPU__DOT__PCplusImm
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                     ? (IData)(
                                                               ((0U 
                                                                 == 
                                                                 (3U 
                                                                  & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                     >> 0xcU)))
                                                                 ? 
                                                                (((QData)((IData)(
                                                                                (0xffffffU 
                                                                                & VL_NEGATE_I((IData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_sign)))))) 
                                                                  << 0x10U) 
                                                                 | (QData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_byte)))
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (3U 
                                                                   & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                      >> 0xcU)))
                                                                  ? (QData)((IData)(
                                                                                ((0xffff0000U 
                                                                                & (VL_NEGATE_I((IData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_sign))) 
                                                                                << 0x10U)) 
                                                                                | (IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword))))
                                                                  : (QData)((IData)(vlTOPp->SOC__DOT__mem_rdata)))))
                                                     : 
                                                    ((0x4000U 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                      ? 
                                                     ((0x2000U 
                                                       & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                       ? 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? 
                                                       (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__aluIn2)
                                                        : 
                                                       (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                        | vlTOPp->SOC__DOT__CPU__DOT__aluIn2))
                                                       : 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? vlTOPp->SOC__DOT__CPU__DOT__shifter
                                                        : 
                                                       (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                        ^ vlTOPp->SOC__DOT__CPU__DOT__aluIn2)))
                                                      : 
                                                     ((0x2000U 
                                                       & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                       ? 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? 
                                                       (1U 
                                                        & (IData)(
                                                                  (vlTOPp->SOC__DOT__CPU__DOT__aluMinus 
                                                                   >> 0x20U)))
                                                        : (IData)(vlTOPp->SOC__DOT__CPU__DOT__LT))
                                                       : 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? vlTOPp->SOC__DOT__CPU__DOT__leftshift
                                                        : 
                                                       ((1U 
                                                         & ((vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                             >> 0x1eU) 
                                                            & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                               >> 5U)))
                                                         ? (IData)(vlTOPp->SOC__DOT__CPU__DOT__aluMinus)
                                                         : vlTOPp->SOC__DOT__CPU__DOT__aluPlus))))))));
}

void VSOC::_settle__TOP__4(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_settle__TOP__4\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SOC__DOT__CPU__DOT__isLoad = (3U == (0x7fU 
                                                 & vlTOPp->SOC__DOT__CPU__DOT__instr));
    vlTOPp->SOC__DOT__CPU__DOT__isStore = (0x23U == 
                                           (0x7fU & vlTOPp->SOC__DOT__CPU__DOT__instr));
    vlTOPp->SOC__DOT__CPU__DOT__isSYSTEM = (0x73U == 
                                            (0x7fU 
                                             & vlTOPp->SOC__DOT__CPU__DOT__instr));
    vlTOPp->SOC__DOT__CPU__DOT__rs2Id = (0x1fU & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                  >> 0x14U));
    vlTOPp->SOC__DOT__CPU__DOT__rs1Id = (0x1fU & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                  >> 0xfU));
    vlTOPp->SOC__DOT__CPU__DOT__rdId = (0x1fU & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                 >> 7U));
    vlTOPp->TXD = (1U & ((IData)(vlTOPp->SOC__DOT__UART__DOT__data) 
                         | (~ (IData)((0U != (IData)(vlTOPp->SOC__DOT__UART__DOT__data))))));
    vlTOPp->SOC__DOT__mem_wdata = ((0xffffff00U & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xffU & vlTOPp->SOC__DOT__CPU__DOT__rs2));
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
        = vlTOPp->SOC__DOT__CPU__DOT__rs1;
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__Vfuncout 
        = ((0x80000000U & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                           << 0x1fU)) | ((0x40000000U 
                                          & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                             << 0x1dU)) 
                                         | ((0x20000000U 
                                             & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                << 0x1bU)) 
                                            | ((0x10000000U 
                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                   << 0x19U)) 
                                               | ((0x8000000U 
                                                   & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                      << 0x17U)) 
                                                  | ((0x4000000U 
                                                      & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                         << 0x15U)) 
                                                     | ((0x2000000U 
                                                         & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                            << 0x13U)) 
                                                        | ((0x1000000U 
                                                            & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                               << 0x11U)) 
                                                           | ((0x800000U 
                                                               & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                  << 0xfU)) 
                                                              | ((0x400000U 
                                                                  & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                     << 0xdU)) 
                                                                 | ((0x200000U 
                                                                     & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                        << 0xbU)) 
                                                                    | ((0x100000U 
                                                                        & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                           << 9U)) 
                                                                       | ((0x80000U 
                                                                           & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                              << 7U)) 
                                                                          | ((0x40000U 
                                                                              & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                << 5U)) 
                                                                             | ((0x20000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                << 3U)) 
                                                                                | ((0x10000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                << 1U)) 
                                                                                | ((0x8000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 1U)) 
                                                                                | ((0x4000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 3U)) 
                                                                                | ((0x2000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__x 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))));
    vlTOPp->SOC__DOT__CPU__DOT__shifter_in = ((1U == 
                                               (7U 
                                                & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                   >> 0xcU)))
                                               ? vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__0__Vfuncout
                                               : vlTOPp->SOC__DOT__CPU__DOT__rs1);
    vlTOPp->SOC__DOT__CPU__DOT__Iimm = ((0xfffff800U 
                                         & (VL_NEGATE_I((IData)(
                                                                (1U 
                                                                 & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                    >> 0x1fU)))) 
                                            << 0xbU)) 
                                        | (0x7ffU & 
                                           (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                            >> 0x14U)));
    vlTOPp->SOC__DOT__CPU__DOT__PCplusImm = (vlTOPp->SOC__DOT__CPU__DOT__PC 
                                             + ((8U 
                                                 & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                 ? 
                                                ((0xfff00000U 
                                                  & (VL_NEGATE_I((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                             >> 0x1fU)))) 
                                                     << 0x14U)) 
                                                 | ((0xff000U 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr) 
                                                    | ((0x800U 
                                                        & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                             >> 0x14U)))))
                                                 : 
                                                ((0x10U 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                  ? 
                                                 (0xfffff000U 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                  : 
                                                 ((0xfffff000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                              >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                              >> 7U))))))));
    vlTOPp->SOC__DOT__resetn = (0xffffU == (IData)(vlTOPp->SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt));
    vlTOPp->SOC__DOT__CPU__DOT__writeBackEn = (((((3U 
                                                   == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)) 
                                                  & (0x63U 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr))) 
                                                 & (0x23U 
                                                    != 
                                                    (0x7fU 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr))) 
                                                & (3U 
                                                   != 
                                                   (0x7fU 
                                                    & vlTOPp->SOC__DOT__CPU__DOT__instr))) 
                                               | (5U 
                                                  == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)));
    vlTOPp->SOC__DOT__CPU__DOT__aluIn2 = (((0x33U == 
                                            (0x7fU 
                                             & vlTOPp->SOC__DOT__CPU__DOT__instr)) 
                                           | (0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)))
                                           ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                           : vlTOPp->SOC__DOT__CPU__DOT__Iimm);
    vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr = (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                  + 
                                                  ((0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                    ? 
                                                   ((0xfffff800U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                                >> 0x1fU)))) 
                                                        << 0xbU)) 
                                                    | ((0x7e0U 
                                                        & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                           >> 0x14U)) 
                                                       | (0x1fU 
                                                          & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                             >> 7U))))
                                                    : vlTOPp->SOC__DOT__CPU__DOT__Iimm));
    vlTOPp->SOC__DOT__CPU__DOT__aluPlus = (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                           + vlTOPp->SOC__DOT__CPU__DOT__aluIn2);
    vlTOPp->SOC__DOT__CPU__DOT__shifter = (IData)((VL_ULL(0x1ffffffff) 
                                                   & VL_SHIFTRS_QQI(33,33,5, 
                                                                    (((QData)((IData)(
                                                                                (1U 
                                                                                & ((vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                                >> 0x1eU) 
                                                                                & (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                                                >> 0x1fU))))) 
                                                                      << 0x20U) 
                                                                     | (QData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__shifter_in))), 
                                                                    (0x1fU 
                                                                     & vlTOPp->SOC__DOT__CPU__DOT__aluIn2))));
    vlTOPp->SOC__DOT__CPU__DOT__aluMinus = (VL_ULL(0x1ffffffff) 
                                            & (VL_ULL(1) 
                                               + ((VL_ULL(0x100000000) 
                                                   | (QData)((IData)(
                                                                     (~ vlTOPp->SOC__DOT__CPU__DOT__aluIn2)))) 
                                                  + (QData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__rs1)))));
    vlTOPp->SOC__DOT__mem_wdata = ((0xffff00ffU & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xff00U & (((1U 
                                                   & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                                   ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                                   : 
                                                  (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                   >> 8U)) 
                                                 << 8U)));
    vlTOPp->SOC__DOT__mem_wdata = ((0xff00ffffU & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xff0000U & (
                                                   ((2U 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                                     ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                                     : 
                                                    (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                     >> 0x10U)) 
                                                   << 0x10U)));
    vlTOPp->SOC__DOT__mem_wdata = ((0xffffffU & vlTOPp->SOC__DOT__mem_wdata) 
                                   | (0xff000000U & 
                                      (((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                         ? vlTOPp->SOC__DOT__CPU__DOT__rs2
                                         : ((2U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                             ? (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                >> 8U)
                                             : (vlTOPp->SOC__DOT__CPU__DOT__rs2 
                                                >> 0x18U))) 
                                       << 0x18U)));
    vlTOPp->SOC__DOT__mem_wmask = (VL_NEGATE_I((IData)(
                                                       (6U 
                                                        == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)))) 
                                   & ((0U == (3U & 
                                              (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                               >> 0xcU)))
                                       ? ((2U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                           ? ((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                               ? 8U
                                               : 4U)
                                           : ((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                               ? 2U
                                               : 1U))
                                       : ((1U == (3U 
                                                  & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                     >> 0xcU)))
                                           ? ((2U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                               ? 0xcU
                                               : 3U)
                                           : 0xfU)));
    vlTOPp->SOC__DOT__mem_addr = (((1U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)) 
                                   | (0U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__state)))
                                   ? vlTOPp->SOC__DOT__CPU__DOT__PC
                                   : vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr);
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
        = vlTOPp->SOC__DOT__CPU__DOT__shifter;
    vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__Vfuncout 
        = ((0x80000000U & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                           << 0x1fU)) | ((0x40000000U 
                                          & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                             << 0x1dU)) 
                                         | ((0x20000000U 
                                             & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                << 0x1bU)) 
                                            | ((0x10000000U 
                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                   << 0x19U)) 
                                               | ((0x8000000U 
                                                   & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                      << 0x17U)) 
                                                  | ((0x4000000U 
                                                      & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                         << 0x15U)) 
                                                     | ((0x2000000U 
                                                         & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                            << 0x13U)) 
                                                        | ((0x1000000U 
                                                            & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                               << 0x11U)) 
                                                           | ((0x800000U 
                                                               & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                  << 0xfU)) 
                                                              | ((0x400000U 
                                                                  & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                     << 0xdU)) 
                                                                 | ((0x200000U 
                                                                     & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                        << 0xbU)) 
                                                                    | ((0x100000U 
                                                                        & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                           << 9U)) 
                                                                       | ((0x80000U 
                                                                           & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                              << 7U)) 
                                                                          | ((0x40000U 
                                                                              & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                << 5U)) 
                                                                             | ((0x20000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                << 3U)) 
                                                                                | ((0x10000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                << 1U)) 
                                                                                | ((0x8000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 1U)) 
                                                                                | ((0x4000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 3U)) 
                                                                                | ((0x2000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__x 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))));
    vlTOPp->SOC__DOT__CPU__DOT__leftshift = vlTOPp->__Vfunc_SOC__DOT__CPU__DOT__flip32__1__Vfuncout;
    vlTOPp->SOC__DOT__CPU__DOT__LT = (1U & ((0x80000000U 
                                             & (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                ^ vlTOPp->SOC__DOT__CPU__DOT__aluIn2))
                                             ? (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                >> 0x1fU)
                                             : (IData)(
                                                       (vlTOPp->SOC__DOT__CPU__DOT__aluMinus 
                                                        >> 0x20U))));
    vlTOPp->SOC__DOT____Vcellinp__RAM__mem_wmask = 
        (VL_NEGATE_I((IData)((1U & (~ (vlTOPp->SOC__DOT__mem_addr 
                                       >> 0x16U))))) 
         & (IData)(vlTOPp->SOC__DOT__mem_wmask));
    vlTOPp->SOC__DOT__uart_valid = (((vlTOPp->SOC__DOT__mem_addr 
                                      >> 0x16U) & (0U 
                                                   != (IData)(vlTOPp->SOC__DOT__mem_wmask))) 
                                    & (vlTOPp->SOC__DOT__mem_addr 
                                       >> 3U));
    vlTOPp->SOC__DOT__mem_rdata = ((0x400000U & vlTOPp->SOC__DOT__mem_addr)
                                    ? ((0x10U & vlTOPp->SOC__DOT__mem_addr)
                                        ? (0x200U & 
                                           ((~ (IData)(vlTOPp->SOC__DOT__uart_ready)) 
                                            << 9U))
                                        : 0U) : vlTOPp->SOC__DOT__RAM_rdata);
    vlTOPp->__Vtableidx1 = (((0U == (IData)(vlTOPp->SOC__DOT__CPU__DOT__aluMinus)) 
                             << 5U) | (((IData)(vlTOPp->SOC__DOT__CPU__DOT__LT) 
                                        << 4U) | ((8U 
                                                   & ((IData)(
                                                              (vlTOPp->SOC__DOT__CPU__DOT__aluMinus 
                                                               >> 0x20U)) 
                                                      << 3U)) 
                                                  | (7U 
                                                     & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                        >> 0xcU)))));
    vlTOPp->SOC__DOT__CPU__DOT__takeBranch = vlTOPp->__Vtable1_SOC__DOT__CPU__DOT__takeBranch
        [vlTOPp->__Vtableidx1];
    vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword = (0xffffU 
                                                 & ((2U 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                                     ? 
                                                    (vlTOPp->SOC__DOT__mem_rdata 
                                                     >> 0x10U)
                                                     : vlTOPp->SOC__DOT__mem_rdata));
    vlTOPp->SOC__DOT__CPU__DOT__nextPC = ((((0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->SOC__DOT__CPU__DOT__instr)) 
                                            & (IData)(vlTOPp->SOC__DOT__CPU__DOT__takeBranch)) 
                                           | (0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__instr)))
                                           ? vlTOPp->SOC__DOT__CPU__DOT__PCplusImm
                                           : ((0x67U 
                                               == (0x7fU 
                                                   & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                               ? (0xfffffffeU 
                                                  & vlTOPp->SOC__DOT__CPU__DOT__aluPlus)
                                               : ((IData)(4U) 
                                                  + vlTOPp->SOC__DOT__CPU__DOT__PC)));
    vlTOPp->SOC__DOT__CPU__DOT__LOAD_byte = ((1U & vlTOPp->SOC__DOT__CPU__DOT__loadstore_addr)
                                              ? (0xffU 
                                                 & ((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword) 
                                                    >> 8U))
                                              : (0xffU 
                                                 & (IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword)));
    vlTOPp->SOC__DOT__CPU__DOT__LOAD_sign = (1U & (
                                                   (~ 
                                                    (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                     >> 0xeU)) 
                                                   & ((0U 
                                                       == 
                                                       (3U 
                                                        & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_byte) 
                                                       >> 7U)
                                                       : 
                                                      ((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword) 
                                                       >> 0xfU))));
    vlTOPp->SOC__DOT__CPU__DOT__writeBackData = (((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SOC__DOT__CPU__DOT__instr)) 
                                                  | (0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr)))
                                                  ? 
                                                 ((IData)(4U) 
                                                  + vlTOPp->SOC__DOT__CPU__DOT__PC)
                                                  : 
                                                 ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                   : 
                                                  ((0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                    ? vlTOPp->SOC__DOT__CPU__DOT__PCplusImm
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr))
                                                     ? (IData)(
                                                               ((0U 
                                                                 == 
                                                                 (3U 
                                                                  & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                     >> 0xcU)))
                                                                 ? 
                                                                (((QData)((IData)(
                                                                                (0xffffffU 
                                                                                & VL_NEGATE_I((IData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_sign)))))) 
                                                                  << 0x10U) 
                                                                 | (QData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_byte)))
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (3U 
                                                                   & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                                      >> 0xcU)))
                                                                  ? (QData)((IData)(
                                                                                ((0xffff0000U 
                                                                                & (VL_NEGATE_I((IData)((IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_sign))) 
                                                                                << 0x10U)) 
                                                                                | (IData)(vlTOPp->SOC__DOT__CPU__DOT__LOAD_halfword))))
                                                                  : (QData)((IData)(vlTOPp->SOC__DOT__mem_rdata)))))
                                                     : 
                                                    ((0x4000U 
                                                      & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                      ? 
                                                     ((0x2000U 
                                                       & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                       ? 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? 
                                                       (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__aluIn2)
                                                        : 
                                                       (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                        | vlTOPp->SOC__DOT__CPU__DOT__aluIn2))
                                                       : 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? vlTOPp->SOC__DOT__CPU__DOT__shifter
                                                        : 
                                                       (vlTOPp->SOC__DOT__CPU__DOT__rs1 
                                                        ^ vlTOPp->SOC__DOT__CPU__DOT__aluIn2)))
                                                      : 
                                                     ((0x2000U 
                                                       & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                       ? 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? 
                                                       (1U 
                                                        & (IData)(
                                                                  (vlTOPp->SOC__DOT__CPU__DOT__aluMinus 
                                                                   >> 0x20U)))
                                                        : (IData)(vlTOPp->SOC__DOT__CPU__DOT__LT))
                                                       : 
                                                      ((0x1000U 
                                                        & vlTOPp->SOC__DOT__CPU__DOT__instr)
                                                        ? vlTOPp->SOC__DOT__CPU__DOT__leftshift
                                                        : 
                                                       ((1U 
                                                         & ((vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                             >> 0x1eU) 
                                                            & (vlTOPp->SOC__DOT__CPU__DOT__instr 
                                                               >> 5U)))
                                                         ? (IData)(vlTOPp->SOC__DOT__CPU__DOT__aluMinus)
                                                         : vlTOPp->SOC__DOT__CPU__DOT__aluPlus))))))));
}

VL_INLINE_OPT void VSOC::_sequent__TOP__5(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_sequent__TOP__5\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt 
        = vlTOPp->__Vdly__SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt;
    vlTOPp->SOC__DOT__resetn = (0xffffU == (IData)(vlTOPp->SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt));
}

void VSOC::_eval(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_eval\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
         | ((IData)(vlTOPp->RESET) & (~ (IData)(vlTOPp->__Vclklast__TOP__RESET))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
         | ((IData)(vlTOPp->RESET) & (~ (IData)(vlTOPp->__Vclklast__TOP__RESET))))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__RESET = vlTOPp->RESET;
}

void VSOC::_eval_initial(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_eval_initial\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__RESET = vlTOPp->RESET;
}

void VSOC::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::final\n"); );
    // Variables
    VSOC__Syms* __restrict vlSymsp = this->__VlSymsp;
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VSOC::_eval_settle(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_eval_settle\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData VSOC::_change_request(VSOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_change_request\n"); );
    VSOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSOC::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RESET & 0xfeU))) {
        Verilated::overWidthError("RESET");}
    if (VL_UNLIKELY((RXD & 0xfeU))) {
        Verilated::overWidthError("RXD");}
}
#endif  // VL_DEBUG

void VSOC::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSOC::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    RESET = VL_RAND_RESET_I(1);
    LEDS = VL_RAND_RESET_I(5);
    RXD = VL_RAND_RESET_I(1);
    TXD = VL_RAND_RESET_I(1);
    SOC__DOT__resetn = VL_RAND_RESET_I(1);
    SOC__DOT__mem_addr = VL_RAND_RESET_I(32);
    SOC__DOT__mem_rdata = VL_RAND_RESET_I(32);
    SOC__DOT__mem_wdata = VL_RAND_RESET_I(32);
    SOC__DOT__mem_wmask = VL_RAND_RESET_I(4);
    SOC__DOT__RAM_rdata = VL_RAND_RESET_I(32);
    SOC__DOT____Vcellinp__RAM__mem_wmask = VL_RAND_RESET_I(4);
    SOC__DOT__uart_valid = VL_RAND_RESET_I(1);
    SOC__DOT__uart_ready = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__PC = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__instr = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__isLoad = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__isStore = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__isSYSTEM = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__rs2Id = VL_RAND_RESET_I(5);
    SOC__DOT__CPU__DOT__rs1Id = VL_RAND_RESET_I(5);
    SOC__DOT__CPU__DOT__rdId = VL_RAND_RESET_I(5);
    SOC__DOT__CPU__DOT__Iimm = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            SOC__DOT__CPU__DOT__RegisterBank[__Vi0] = VL_RAND_RESET_I(32);
    }}
    SOC__DOT__CPU__DOT__rs1 = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__rs2 = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__writeBackData = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__writeBackEn = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__aluIn2 = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__aluPlus = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__aluMinus = VL_RAND_RESET_Q(33);
    SOC__DOT__CPU__DOT__LT = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__shifter = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__shifter_in = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__leftshift = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__takeBranch = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__PCplusImm = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__nextPC = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__loadstore_addr = VL_RAND_RESET_I(32);
    SOC__DOT__CPU__DOT__LOAD_halfword = VL_RAND_RESET_I(16);
    SOC__DOT__CPU__DOT__LOAD_byte = VL_RAND_RESET_I(16);
    SOC__DOT__CPU__DOT__LOAD_sign = VL_RAND_RESET_I(1);
    SOC__DOT__CPU__DOT__state = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<1536; ++__Vi0) {
            SOC__DOT__RAM__DOT__MEM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    SOC__DOT__RAM__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    SOC__DOT__RAM__DOT____Vlvbound2 = VL_RAND_RESET_I(8);
    SOC__DOT__RAM__DOT____Vlvbound3 = VL_RAND_RESET_I(8);
    SOC__DOT__RAM__DOT____Vlvbound4 = VL_RAND_RESET_I(8);
    SOC__DOT__UART__DOT__cnt = VL_RAND_RESET_I(5);
    SOC__DOT__UART__DOT__data = VL_RAND_RESET_I(10);
    SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt = VL_RAND_RESET_I(16);
    __Vfunc_SOC__DOT__CPU__DOT__flip32__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_SOC__DOT__CPU__DOT__flip32__0__x = VL_RAND_RESET_I(32);
    __Vfunc_SOC__DOT__CPU__DOT__flip32__1__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_SOC__DOT__CPU__DOT__flip32__1__x = VL_RAND_RESET_I(32);
    __Vtableidx1 = 0;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[0] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[1] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[2] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[3] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[4] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[5] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[6] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[7] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[8] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[9] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[10] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[11] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[12] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[13] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[14] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[15] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[16] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[17] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[18] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[19] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[20] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[21] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[22] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[23] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[24] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[25] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[26] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[27] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[28] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[29] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[30] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[31] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[32] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[33] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[34] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[35] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[36] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[37] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[38] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[39] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[40] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[41] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[42] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[43] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[44] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[45] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[46] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[47] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[48] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[49] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[50] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[51] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[52] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[53] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[54] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[55] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[56] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[57] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[58] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[59] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[60] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[61] = 0U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[62] = 1U;
    __Vtable1_SOC__DOT__CPU__DOT__takeBranch[63] = 0U;
    __Vdly__SOC__DOT__CW__DOT__genblk2__DOT__reset_cnt = VL_RAND_RESET_I(16);
}
