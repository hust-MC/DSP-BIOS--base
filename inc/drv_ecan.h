/*-------------------------------------------------------------------*
    fun_ecan.h	

    2812 ECan模块头文件

    last modify : 2013.5.9 by hustlzp
*-------------------------------------------------------------------*/

#ifndef DRV_ECAN_H
#define DRV_ECAN_H

#include "DSP2833x_Device.h"

#define CAN_A 0
#define CAN_B 1

/* ECan 驱动波特率选择 */
enum ECan_baudRate
{
    ECAN_BAUD_RATE_50K  = 50,
    ECAN_BAUD_RATE_100K = 100,
    ECAN_BAUD_RATE_125K = 125,
    ECAN_BAUD_RATE_250K = 250,
    ECAN_BAUD_RATE_500K = 500,
    ECAN_BAUD_RATE_1M   = 1000
};

/* ECan 邮箱初始化配置参数 */
struct ECan_mboxConfig
{
    UINT16 dir;          // 1 Rx, 0 Tx
    UINT16 mode;         // 1 standar, 0 extended
    UINT16 enableMask;   // 1 enable, 0 not
    UINT16 autoAnswer;   // 1 auto answer, 0 not
    UINT32 id;           // 29bits or 11bits
    UINT32 mask;         // accept mask
};


// 初始化Ecan
void ECAN_init(UINT16 baudRate);
void ECANA_init(UINT16 baudRate);
void ECANB_init(UINT16 baudRate);

// 改变邮箱ID
void ECANA_setID(UINT32 mboxNum, UINT32 id);
void ECANB_setID(UINT32 mboxNum, UINT32 id);

// ECan loopback test
BOOLEAN ECANA_test(void);
BOOLEAN ECANB_test(void);

#endif

