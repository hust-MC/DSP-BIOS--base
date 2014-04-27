#ifndef MAIN_H
#define MAIN_H

#include "DSP2833x_Device.h"
#include "DSP2833x_GlobalPrototypes.h"

/*-----------------------------------------------------------------------------
	Specify the PLL control register (PLLCR) and divide select (DIVSEL) value.
-----------------------------------------------------------------------------*/

//#define DSP28_DIVSEL   0   // Enable /4 for SYSCLKOUT
//#define DSP28_DIVSEL   1 // Enable /4 for SYSCKOUT
#define DSP28_DIVSEL     2 // Enable /2 for SYSCLKOUT
//#define DSP28_DIVSEL     3 // Enable /1 for SYSCLKOUT

#define DSP28_PLLCR   10
//#define DSP28_PLLCR    9
//#define DSP28_PLLCR    8
//#define DSP28_PLLCR    7
//#define DSP28_PLLCR    6
//#define DSP28_PLLCR    5
//#define DSP28_PLLCR    4
//#define DSP28_PLLCR    3
//#define DSP28_PLLCR    2
//#define DSP28_PLLCR    1
//#define DSP28_PLLCR    0  // PLL is bypassed in this mode
//----------------------------------------------------------------------------


/*-----------------------------------------------------------------------------
      Specify the clock rate of the CPU (SYSCLKOUT) in nS.

      Take into account the input clock frequency and the PLL multiplier
      selected in step 1.

      Use one of the values provided, or define your own.
      The trailing L is required tells the compiler to treat
      the number as a 64-bit value.

      Only one statement should be uncommented.

      Example 1: 150 MHz devices:
                 CLKIN is a 30MHz crystal.

                 In step 1 the user specified PLLCR = 0xA for a
                 150Mhz CPU clock (SYSCLKOUT = 150MHz).

                 In this case, the CPU_RATE will be 6.667L
                 Uncomment the line:  #define CPU_RATE  6.667L

      Example 2: 100 MHz devices:
                 CLKIN is a 20MHz crystal.

	             In step 1 the user specified PLLCR = 0xA for a
	             100Mhz CPU clock (SYSCLKOUT = 100MHz).

	             In this case, the CPU_RATE will be 10.000L
                 Uncomment the line:  #define CPU_RATE  10.000L
-----------------------------------------------------------------------------*/
#define CPU_RATE    6.667L   // for a 150MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE    7.143L   // for a 140MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE    8.333L   // for a 120MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   10.000L   // for a 100MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   13.330L   // for a 75MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   20.000L   // for a 50MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   33.333L   // for a 30MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   41.667L   // for a 24MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   50.000L   // for a 20MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   66.667L   // for a 15MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE  100.000L   // for a 10MHz CPU clock speed  (SYSCLKOUT)

#define CPU_FRQ_150MHZ    1     // 150 MHz CPU Freq (30 MHz input freq) by DEFAULT
#define CPU_FRQ_100MHZ    0     // DSP28_28335||DSP28_28334


// 延时us
#define DELAY_US(n)       \
	DSP28x_usDelay(((((long double) n * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L);

// 延时ms
#define DELAY_MS(n)       \
{                         \
	UINT16 i;             \
                          \
	for(i=0; i<n; i++)    \
	{                     \
		DELAY_US(1000);   \
	}                     \
}

// 延时s
#define DELAY_S(n)           \
{                            \
	UINT16 i;                \
                             \
	for(i=0; i<n; i++)       \
	{                        \
		DELAY_US(1000000);   \
	}                        \
}

// 是否启用看门狗
#define WATCH_DOG 1

// 是否启用新版本Can协议
#define NEW_CAN 1

#endif

