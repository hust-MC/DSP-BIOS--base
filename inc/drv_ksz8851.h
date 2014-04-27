#ifndef NET_KSZ_H
#define NET_KSZ_H

#include "drv_ksz8851Reg.h"
#include "main.h"
#include "global.h"

#define PHY_RESET_TIMEOUT 10

/*
 * Functions Protocol
 */

void    KSZ_stop(UINT32 baseAddr);
void    KSZ_start(UINT32 baseAddr);

void    KSZ_startReceive(UINT32 addr);
void    KSZ_stopReceive(UINT32 addr);
void    KSZ_clearRxQMU(UINT32 addr);

void    KSZ_reset(UINT32 baseAddr);
void    KSZ_readChipID(UINT32 baseAddr, PUINT16);

void    KSZ_setAddress(UINT32 baseAddr, UINT16 *);
void    KSZ_readAddress(UINT32 baseAddr, UINT16 *);

void    KSZ_startReceiveTransfer(UINT32 baseAddr);
void    KSZ_startTransmitTransfer(UINT32 baseAddr);
void    KSZ_stopTransfer(UINT32 baseAddr);
void    KSZ_releaseReceive(UINT32 baseAddr);
BOOLEAN KSZ_transmitDone(UINT32 baseAddr, PUINT16);

void    KSZ_acknowledgeInterrupt(UINT32 baseAddr, UINT16);
void    KSZ_disableInterrupt(UINT32 baseAddr, UINT16);
void    KSZ_enableInterrupt(UINT32 baseAddr, UINT16);

BOOLEAN KSZ_restartAutoNego(UINT32 baseAddr);
BOOLEAN KSZ_checkLink(UINT32 baseAddr);


/*
 * Read or write KS8851M register 
 */

#define HW_READ_WORD(baseAddr, regAddr, data)                     \
	*data = *((volatile UINT16 *)(baseAddr + regAddr / 2));

#define HW_WRITE_WORD(baseAddr, regAddr, data)                    \
	*((volatile UINT16 *)(baseAddr + regAddr / 2)) = data;

/* 
 * Read multiplex frames from KS8851MQL QMU RxQ packet memory
 * at one DMA interval. Frame size (len) must be DWORD alignment.  
 * (1). reset RX frame pointer.
 * (2). start transfer.
 * (3). dummy read.
 * (4). read 4-byte frame header.
 * (5). read the single frame data.
 * (6). loop 3, and 4, until finished all the frame data.
 * (7). stop transfer.
 */

#define HW_READ_START(baseAddr, data)                                    \
{                                                                        \
    PUINT16 pwData = (PUINT16)data;                                      \
                                                                         \
    HW_WRITE_WORD(baseAddr, REG_RX_ADDR_PTR, RXFDPR_DEFAUL);             \
    HW_WRITE_WORD(baseAddr, REG_RXQ_CMD, (RXQ_CMD_CNTL | RXQ_START));    \
    HW_READ_WORD(baseAddr, REG_QDR_DUMMY, pwData);                       \
}

#define HW_READ_END(baseAddr)                                            \
{                                                                        \
    HW_WRITE_WORD(baseAddr, REG_RXQ_CMD, RXQ_CMD_CNTL);                  \
}

/* 
 * Read single frame from KS8851MQL QMU RxQ packet memory
 * at one DMA interval. Frame size (len) must be DWORD alignment  
 * (1). reset RX frame pointer.
 * (2). start transfer.
 * (3). dummy read.
 * (4). read 4-byte frame header.
 * (5). read frame data.
 * (6). stop transfer.
 */
#define HW_READ_BUFFER(baseAddr, data, len)                   \
{                                                             \
    UINT16 lengthInWord = ((len + 1) >> 1) ;                  \
    PUINT16 pwData = (PUINT16)data;                           \
	UINT16 temp;	                                          \
                                                              \
    if(lengthInWord & 0x1) lengthInWord += 1;                 \
    HW_READ_START(baseAddr, data);                            \
    HW_READ_WORD(baseAddr, REG_QDR_DUMMY, pwData);            \
    HW_READ_WORD(baseAddr, REG_QDR_DUMMY, pwData);            \
    while(lengthInWord--)                                     \
	{	                                                      \
       HW_READ_WORD(baseAddr, REG_QDR_DUMMY, &temp);          \
	   *(pwData++) = temp & 0x00FF;                           \
	   *(pwData++) = (temp >> 8) & 0x00FF;                    \
	}	                                                      \
    HW_READ_END(baseAddr);                                    \
}

/* Write the multiplex frames to KS8851MQL QMU TxQ packet memory
 * at one DMA interval. Frame size (len) must be DWORD alignment  
 * (1). Start transfer.
 * (2). Write 4-byte frame header.
 * (3). write the single frame data.
 * (4). loop 2, and 3, until finished all the frame data.
 * (5). Stop transfer.
 */

#define HW_WRITE_START(baseAddr)                                         \
{                                                                        \
    HW_WRITE_WORD(baseAddr, REG_RXQ_CMD, (RXQ_CMD_CNTL | RXQ_START));    \
}

#define HW_WRITE_END(baseAddr)                                           \
{                                                                        \
    HW_WRITE_WORD(baseAddr, REG_RXQ_CMD, RXQ_CMD_CNTL);                  \
}

/* 
 * Write a single frame to KS8851MQL QMU TxQ packet memory
 * at one DMA interval. 
 * Frame size (len) will be adjusted to DWORD alignment  
 * (1). start transfer.
 * (2). write 4-byte frame header.
 * (3). write frame data.
 * (4). stop transfer.
 */
#define HW_WRITE_BUFFER(baseAddr, data, len)                                                            \
{                                                                                                       \
    UINT16 lengthInWord = ((len + 1) >> 1);                                                             \
	PUINT16 pwData = (PUINT16)data;                                                                     \
                                                                                                        \
    if(lengthInWord & 0x1) lengthInWord +=1;                                                            \
    HW_WRITE_START(baseAddr);                                                                           \
    HW_WRITE_WORD(baseAddr, REG_QDR_DUMMY, TX_CTRL_INTERRUPT_ON);                                       \
    HW_WRITE_WORD(baseAddr, REG_QDR_DUMMY, len);                                                        \
    while(lengthInWord--)                                                                               \
       HW_WRITE_WORD(baseAddr, REG_QDR_DUMMY, ((*pwData++) & 0x00FF) | (((*pwData++) << 8) & 0xFF00));  \
    HW_WRITE_END(baseAddr);                                                                             \
}

#endif
