#include <std.h>
#include <string.h>
#include "main.h"
#include "net.h"
#include "drv_ecan.h"
#include "drv_spi.h"
#include "drv_sci.h"
#include "drv_i2c.h"
#include "global.h"

// 是否在Flash上运行
#define FLASH_RUN 0

#if FLASH_RUN
extern unsigned int hwi_vec_loadstart;
extern unsigned int hwi_vec_loadend;
extern unsigned int hwi_vec_runstart;

extern unsigned int trcdata_loadstart;
extern unsigned int trcdata_loadend;
extern unsigned int trcdata_runstart;

extern unsigned int ramfuncs_loadstart; 
extern unsigned int ramfuncs_loadend; 
extern unsigned int ramfuncs_runstart;

extern unsigned int xcfuncs_loadstart; 
extern unsigned int xcfuncs_loadend; 
extern unsigned int xcfuncs_runstart;

extern unsigned int iqfuncs_loadstart; 
extern unsigned int iqfuncs_loadend; 
extern unsigned int iqfuncs_runstart;

void InitFlash(void);

// Initialize the .trcdata section before main()
void UserInit(void)
{ 
	memcpy(&trcdata_runstart, &trcdata_loadstart, &trcdata_loadend - &trcdata_loadstart); 
}
#endif

/*
 * Private functions
 */
void setupTest(void);

/*
 * Main函数
 */
void main()
{


	#if FLASH_RUN
	// Copy functions from flash to ram
	asm(" EALLOW");
	memcpy(&hwi_vec_runstart, &hwi_vec_loadstart, &hwi_vec_loadend - &hwi_vec_loadstart);
	memcpy(&ramfuncs_runstart, &ramfuncs_loadstart, &ramfuncs_loadend - &ramfuncs_loadstart);
	memcpy(&xcfuncs_runstart, &xcfuncs_loadstart, &xcfuncs_loadend - &xcfuncs_loadstart); 
	memcpy(&iqfuncs_runstart, &iqfuncs_loadstart, &iqfuncs_loadend - &iqfuncs_loadstart);
	asm(" EDIS");

	// Speed up flash
	InitFlash();
	#endif


	// Disable dog, init PLL, init peripheral clocks 
	InitSysCtrl();

	// Disable CPU interrupts
	DINT;

	// Initialize the PIE control registers to their default state
	InitPieCtrl();

	// Disable CPU interrupts
	// clear all CPU interrupt flags
	IER = 0x0000;
	IFR = 0x0000;


	// 配置LED
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO60 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO52 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO53 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO53 = 1;
	EDIS;

	// 使能中断
	EnableInterrupts();



	#if WATCH_DOG
	EnableDog();
	#endif

	//EnableDog();	// 测试看门狗，lzp，2014.2.28
}



