/*   Do *not* directly modify this file.  It was    */
/*   generated by the Configuration Tool; any  */
/*   changes risk being overwritten.                */

/* INPUT bios.cdb */

/* MODULE PARAMETERS */
-u _FXN_F_nop
GBL_USERLIMPMODEABORTFXN = _FXN_F_nop;
-u _FXN_F_nop
GBL_USERINITFXN = _FXN_F_nop;

-u SRAM
MEM_SEGZERO = SRAM;
-u SRAM
MEM_MALLOCSEG = SRAM;

-u CLK_F_getshtime
CLK_TIMEFXN = CLK_F_getshtime;
-u CLK_F_run
CLK_HOOKFXN = CLK_F_run;

-u KNL_tick_stub
PRD_THOOKFXN = KNL_tick_stub;

-u L47SARAM
RTDX_DATAMEMSEG = L47SARAM;

-u L47SARAM
HST_DSMBUFSEG = L47SARAM;

-u GBL_NULL
SWI_EHOOKFXN = GBL_NULL;
-u GBL_NULL
SWI_IHOOKFXN = GBL_NULL;
-u SWI_F_exec
SWI_EXECFXN = SWI_F_exec;
-u SWI_F_run
SWI_RUNFXN = SWI_F_run;

-u MEM_NULL
TSK_STACKSEG = MEM_NULL;
-u _FXN_F_nop
TSK_VCREATEFXN = _FXN_F_nop;
-u _FXN_F_nop
TSK_VDELETEFXN = _FXN_F_nop;
-u _FXN_F_nop
TSK_VEXITFXN = _FXN_F_nop;

-u IDL_F_stub
IDL_CALIBRFXN = IDL_F_stub;

-u _UTL_doAbort
SYS_ABORTFXN = _UTL_doAbort;
-u _UTL_doError
SYS_ERRORFXN = _UTL_doError;
-u _UTL_halt
SYS_EXITFXN = _UTL_halt;
-u _UTL_doPutc
SYS_PUTCFXN = _UTL_doPutc;

-u _FXN_F_nop
GIO_CREATEFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_DELETEFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_PENDFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_POSTFXN = _FXN_F_nop;

/* OBJECT ALIASES */
_PIEVECT = PIEVECT;
_SRAM = SRAM;
_MSARAM = MSARAM;
_L03SARAM = L03SARAM;
_L47SARAM = L47SARAM;
_OTP = OTP;
_FLASH = FLASH;
_BOOTROM = BOOTROM;
_L7SARAM = L7SARAM;
_PRD_clock = PRD_clock;
_RTA_fromHost = RTA_fromHost;
_RTA_toHost = RTA_toHost;
_HWI_RESET = HWI_RESET;
_HWI_INT1 = HWI_INT1;
_HWI_INT2 = HWI_INT2;
_HWI_INT3 = HWI_INT3;
_HWI_INT4 = HWI_INT4;
_HWI_INT5 = HWI_INT5;
_HWI_INT6 = HWI_INT6;
_HWI_INT7 = HWI_INT7;
_HWI_INT8 = HWI_INT8;
_HWI_INT9 = HWI_INT9;
_HWI_INT10 = HWI_INT10;
_HWI_INT11 = HWI_INT11;
_HWI_INT12 = HWI_INT12;
_HWI_INT13 = HWI_INT13;
_HWI_TINT = HWI_TINT;
_HWI_DLOG = HWI_DLOG;
_HWI_RTOS = HWI_RTOS;
_HWI_RESERVED = HWI_RESERVED;
_HWI_NMI = HWI_NMI;
_HWI_ILLEGAL = HWI_ILLEGAL;
_HWI_USER1 = HWI_USER1;
_HWI_USER2 = HWI_USER2;
_HWI_USER3 = HWI_USER3;
_HWI_USER4 = HWI_USER4;
_HWI_USER5 = HWI_USER5;
_HWI_USER6 = HWI_USER6;
_HWI_USER7 = HWI_USER7;
_HWI_USER8 = HWI_USER8;
_HWI_USER9 = HWI_USER9;
_HWI_USER10 = HWI_USER10;
_HWI_USER11 = HWI_USER11;
_HWI_USER12 = HWI_USER12;
_PIE_INT1_1 = PIE_INT1_1;
_PIE_INT1_2 = PIE_INT1_2;
_PIE_INT1_3 = PIE_INT1_3;
_PIE_INT1_4 = PIE_INT1_4;
_PIE_INT1_5 = PIE_INT1_5;
_PIE_INT1_6 = PIE_INT1_6;
_PIE_INT1_7 = PIE_INT1_7;
_PIE_INT1_8 = PIE_INT1_8;
_PIE_INT2_1 = PIE_INT2_1;
_PIE_INT2_2 = PIE_INT2_2;
_PIE_INT2_3 = PIE_INT2_3;
_PIE_INT2_4 = PIE_INT2_4;
_PIE_INT2_5 = PIE_INT2_5;
_PIE_INT2_6 = PIE_INT2_6;
_PIE_INT2_7 = PIE_INT2_7;
_PIE_INT2_8 = PIE_INT2_8;
_PIE_INT3_1 = PIE_INT3_1;
_PIE_INT3_2 = PIE_INT3_2;
_PIE_INT3_3 = PIE_INT3_3;
_PIE_INT3_4 = PIE_INT3_4;
_PIE_INT3_5 = PIE_INT3_5;
_PIE_INT3_6 = PIE_INT3_6;
_PIE_INT3_7 = PIE_INT3_7;
_PIE_INT3_8 = PIE_INT3_8;
_PIE_INT4_1 = PIE_INT4_1;
_PIE_INT4_2 = PIE_INT4_2;
_PIE_INT4_3 = PIE_INT4_3;
_PIE_INT4_4 = PIE_INT4_4;
_PIE_INT4_5 = PIE_INT4_5;
_PIE_INT4_6 = PIE_INT4_6;
_PIE_INT4_7 = PIE_INT4_7;
_PIE_INT4_8 = PIE_INT4_8;
_PIE_INT5_1 = PIE_INT5_1;
_PIE_INT5_2 = PIE_INT5_2;
_PIE_INT5_3 = PIE_INT5_3;
_PIE_INT5_4 = PIE_INT5_4;
_PIE_INT5_5 = PIE_INT5_5;
_PIE_INT5_6 = PIE_INT5_6;
_PIE_INT5_7 = PIE_INT5_7;
_PIE_INT5_8 = PIE_INT5_8;
_PIE_INT6_1 = PIE_INT6_1;
_PIE_INT6_2 = PIE_INT6_2;
_PIE_INT6_3 = PIE_INT6_3;
_PIE_INT6_4 = PIE_INT6_4;
_PIE_INT6_5 = PIE_INT6_5;
_PIE_INT6_6 = PIE_INT6_6;
_PIE_INT6_7 = PIE_INT6_7;
_PIE_INT6_8 = PIE_INT6_8;
_PIE_INT7_1 = PIE_INT7_1;
_PIE_INT7_2 = PIE_INT7_2;
_PIE_INT7_3 = PIE_INT7_3;
_PIE_INT7_4 = PIE_INT7_4;
_PIE_INT7_5 = PIE_INT7_5;
_PIE_INT7_6 = PIE_INT7_6;
_PIE_INT7_7 = PIE_INT7_7;
_PIE_INT7_8 = PIE_INT7_8;
_PIE_INT8_1 = PIE_INT8_1;
_PIE_INT8_2 = PIE_INT8_2;
_PIE_INT8_3 = PIE_INT8_3;
_PIE_INT8_4 = PIE_INT8_4;
_PIE_INT8_5 = PIE_INT8_5;
_PIE_INT8_6 = PIE_INT8_6;
_PIE_INT8_7 = PIE_INT8_7;
_PIE_INT8_8 = PIE_INT8_8;
_PIE_INT9_1 = PIE_INT9_1;
_PIE_INT9_2 = PIE_INT9_2;
_PIE_INT9_3 = PIE_INT9_3;
_PIE_INT9_4 = PIE_INT9_4;
_PIE_INT9_5 = PIE_INT9_5;
_PIE_INT9_6 = PIE_INT9_6;
_PIE_INT9_7 = PIE_INT9_7;
_PIE_INT9_8 = PIE_INT9_8;
_PIE_INT10_1 = PIE_INT10_1;
_PIE_INT10_2 = PIE_INT10_2;
_PIE_INT10_3 = PIE_INT10_3;
_PIE_INT10_4 = PIE_INT10_4;
_PIE_INT10_5 = PIE_INT10_5;
_PIE_INT10_6 = PIE_INT10_6;
_PIE_INT10_7 = PIE_INT10_7;
_PIE_INT10_8 = PIE_INT10_8;
_PIE_INT11_1 = PIE_INT11_1;
_PIE_INT11_2 = PIE_INT11_2;
_PIE_INT11_3 = PIE_INT11_3;
_PIE_INT11_4 = PIE_INT11_4;
_PIE_INT11_5 = PIE_INT11_5;
_PIE_INT11_6 = PIE_INT11_6;
_PIE_INT11_7 = PIE_INT11_7;
_PIE_INT11_8 = PIE_INT11_8;
_PIE_INT12_1 = PIE_INT12_1;
_PIE_INT12_2 = PIE_INT12_2;
_PIE_INT12_3 = PIE_INT12_3;
_PIE_INT12_4 = PIE_INT12_4;
_PIE_INT12_5 = PIE_INT12_5;
_PIE_INT12_6 = PIE_INT12_6;
_PIE_INT12_7 = PIE_INT12_7;
_PIE_INT12_8 = PIE_INT12_8;
_KNL_swi = KNL_swi;
_TSK_idle = TSK_idle;
_IDL_cpuLoad = IDL_cpuLoad;
_LNK_dataPump = LNK_dataPump;
_RTA_dispatcher = RTA_dispatcher;
_LOG_system = LOG_system;
_LOG_trace = LOG_trace;
_SEM_net = SEM_net;
_SEM_can = SEM_can;
_IDL_busyObj = IDL_busyObj;

/* MODULE GBL */

SECTIONS {
   .vers (COPY): {} /* version information */
}

--diag_suppress=16002 /* avoid 6.1.x linker warning */

-priority
-llnkrtdx.a28FP
-ldrivers.a28FP        /* device drivers support */
-lsioboth.a28FP        /* supports both SIO models */
-lbios.a28FP           /* DSP/BIOS support */
-lrtdxfp.lib           /* RTDX support */
-lrts2800_fpu32.lib    /* C and C++ run-time library support */

/* MODULE MEM */
-stack 0x200
MEMORY {
   PAGE 1:   PIEVECT:    origin = 0xd00,         len = 0x100
   PAGE 0:   SRAM:       origin = 0x100000,      len = 0x80000
   PAGE 1:   MSARAM:     origin = 0x0,           len = 0x800
   PAGE 0:   L03SARAM:   origin = 0x8000,        len = 0x4000
   PAGE 1:   L47SARAM:   origin = 0xc000,        len = 0x3c00
   PAGE 0:   OTP:        origin = 0x380400,      len = 0x400
   PAGE 0:   FLASH:      origin = 0x300000,      len = 0x40000
   PAGE 0:   BOOTROM:    origin = 0x3fe000,      len = 0x1fc0
   PAGE 1:   L7SARAM:    origin = 0xfc00,        len = 0x400
}
/* MODULE CLK */
SECTIONS {
   .clk: {
        CLK_F_gethtime = CLK_F_getshtime;
        *(.clk) 
   } > L47SARAM  PAGE 1, RUN_START(CLK_A_TABBEG) 
}
_CLK_PRD = CLK_PRD;
_CLK_COUNTSPMS = CLK_COUNTSPMS;
_CLK_REGS = CLK_REGS;
_CLK_USETIMER = CLK_USETIMER;
_CLK_TIMERNUM = CLK_TIMERNUM;
_CLK_TCR = CLK_TCR;
_CLK_TDDR = CLK_TDDR;

/* MODULE PRD */
SECTIONS {
   .prd: RUN_START(PRD_A_TABBEG), RUN_END(PRD_A_TABEND) {
   } > L47SARAM PAGE 1
}
PRD_A_TABLEN = 0;

/* MODULE RTDX */
_RTDX_interrupt_mask = 0x0;

/* MODULE SWI */
SECTIONS {
   .swi: RUN_START(SWI_A_TABBEG), RUN_END(SWI_A_TABEND) {
   } > L47SARAM PAGE 1
}
SWI_A_TABLEN = 1;

/* MODULE TSK */
SECTIONS {
   .tsk: {
        *(.tsk) 
   } > L47SARAM PAGE 1
}

/* MODULE IDL */
SECTIONS {
   .idl: {
        *(.idl) 
   } > L47SARAM PAGE 1, RUN_START(IDL_A_TABBEG)
   
   .idlcal: {
        *(.idlcal) 
   } > L47SARAM PAGE 1, RUN_START(IDL_A_CALBEG) 
}


LOG_A_TABLEN = 2; _LOG_A_TABLEN = 2;

PIP_A_TABLEN = 2;


SECTIONS {
        .dsm: {} > L47SARAM PAGE 1

        .sem: {} > L47SARAM PAGE 1

        .rtdx_data: {}  > L47SARAM PAGE 1

        .TSK_idle$stk: {
            *(.TSK_idle$stk)
        } > L47SARAM PAGE 1

        /* LOG_system buffer */
        .LOG_system$buf: align = 0x40 {} > L47SARAM PAGE 1

       /* RTA_fromHost buffer */
       .hst1: align = 0x4 {} > L47SARAM PAGE 1

       /* RTA_toHost buffer */
       .hst0: align = 0x4 {} > L47SARAM PAGE 1

        .trace: fill = 0x0 {
           _SYS_PUTCBEG = .;
           . += 0x200;
           _SYS_PUTCEND = . - 1;
        } > L47SARAM PAGE 1

        .hst: RUN_START(HST_A_TABBEG), RUN_START(_HST_A_TABBEG), RUN_END(HST_A_TABEND), RUN_END(_HST_A_TABEND) {
        } > L47SARAM PAGE 1

        .log: RUN_START(LOG_A_TABBEG), RUN_START(_LOG_A_TABBEG), RUN_END(LOG_A_TABEND), RUN_END(_LOG_A_TABEND) {
        } > L47SARAM PAGE 1

        .pip: RUN_START(PIP_A_TABBEG), RUN_START(_PIP_A_TABBEG), RUN_END(PIP_A_TABEND), RUN_END(_PIP_A_TABEND) {
        } > L47SARAM PAGE 1

        .sts: RUN_START(STS_A_TABBEG), RUN_START(_STS_A_TABBEG), RUN_END(STS_A_TABEND), RUN_END(_STS_A_TABEND) {
        } > L47SARAM PAGE 1

        .stack: {
            GBL_stackbeg = .;
            *(.stack)
            GBL_stackend = GBL_stackbeg + 0x200 - 1;
        _HWI_STKBOTTOM = GBL_stackbeg;
            _HWI_STKTOP = (GBL_stackend + 1);
        } > MSARAM PAGE 1

        .hwi_vec: START(_hwi_vec_loadstart), END(_hwi_vec_loadend), SIZE(_hwi_vec_loadsize), RUN_START(_hwi_vec_runstart) {
       /* no HWI stubs are necessary */
       }  > PIEVECT PAGE 1

        .bss:     {} > SRAM PAGE 0

        .sysdata: {} > SRAM PAGE 0

        frt:    {} > SRAM PAGE 0

        .mem: 	  {} > SRAM PAGE 0

        .bios:    {} > SRAM PAGE 0

        .cio:     {} > SRAM PAGE 0

        .data:    {} > SRAM PAGE 0

        .gio:     {} > SRAM PAGE 0

        .pinit:   {} > SRAM PAGE 0

        .sys:     {} > SRAM PAGE 0

        .sysregs: {} > SRAM PAGE 0

        .text:    {} > SRAM PAGE 0

        .cinit:    {} > SRAM PAGE 0

        .const:    {} > SRAM PAGE 0

        .ebss:     {} > SRAM PAGE 0

        .switch:    {} > SRAM PAGE 0

        .gblinit:    {} > SRAM PAGE 0

        .sysinit:    {} > SRAM PAGE 0

        .trcdata:    {} > SRAM PAGE 0

        .rtdx_text: {}  > SRAM PAGE 0

        .hwi_disp_sec:     {} > SRAM PAGE 0

        .hwi: {
       /* no HWI stubs are necessary */
       }  > SRAM PAGE 0

        /* LOG_trace buffer */
        .LOG_trace$buf: align = 0x80 {} > SRAM PAGE 0

        GROUP {
         .econst: {} 
         .printf (COPY): {} 
        } > SRAM PAGE 0

        .args: fill=0 {
            *(.args)
            . += 0x4;
        } > SRAM PAGE 0

        .SRAM$heap: {
            . += 0x800;
        } RUN_START(SRAM$B), RUN_START(_SRAM_base), RUN_SIZE(SRAM$L), RUN_SIZE(_SRAM_length) > SRAM PAGE 0

}
