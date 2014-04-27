/*-------------------------------------------------------------------*
    drv_spi.h	

    SPI驱动，用于读写EEPROM (AT25640)
*-------------------------------------------------------------------*/

#ifndef DRV_SPI_H
#define DRV_SPI_H

#include "DSP2833x_Device.h"

// SPI 操作命令字
#define SPI_WREN     0x0600	 // 使能写
#define SPI_WRDI     0x0400	 // 禁止写
#define SPI_RDSR     0x0500	 // 读状态寄存器
#define SPI_WRSR     0x0100	 // 写状态寄存器
#define SPI_READ     0x0300	 // 读
#define SPI_WRITE    0x0200	 // 写

// SPI 保护区
enum SPI_PROTECT
{
    SPI_PROTECT_NONE,          // 无保护，都可写
    SPI_PROTECT_HIGH_QUARTER,  // 保护高1/4区域，低3/4区域可写
    SPI_PROTECT_HIGH_HALF,     // 保护高1/2区域，低1/2区域可写
    SPI_PROTECT_ALL            // 保护所有区域，都不可写
};

/* 初始化SPI */
/*-------------------------------------------------------------------*
    SPI_init()

    Init SPI.

    Ret:
        NULL
*-------------------------------------------------------------------*/
void SPI_init();

/*-------------------------------------------------------------------*
    SPI_setProtectArea()

    Set protect area

    Param:
        protectArea: the area to protect, see enum SPI_PROTECT above
    Ret:
        NULL
*-------------------------------------------------------------------*/
void SPI_setProtectArea(UINT16 protectArea);

/*-------------------------------------------------------------------*
    SPI_writeEE()

    Write data to AT25040

    Param:
        address: the number of mail box
        data: the pointer to the send buffer
        len: the length of data to be write
    Ret:
        none
*-------------------------------------------------------------------*/
void SPI_writeEE(UINT16 address, UINT16 *data, UINT16 len);

/*-------------------------------------------------------------------*
    SPI_readEE()

    Read data from AT25040

    Param:
        address: the address of AT25040 to read begin
        data: the pointer to the receive buffer
        len: the length of data to be read
    Ret:
        NULL
*-------------------------------------------------------------------*/
void SPI_readEE(UINT16 address, UINT16 *data, UINT16 len);

// 保存系统配置
BOOLEAN SPI_saveSysCfg(void);

// 读取系统配置
BOOLEAN SPI_loadSysCfg(void);

// SPI开机测试
BOOLEAN SPI_test(void);

#endif
