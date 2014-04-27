/*-------------------------------------------------------------------*
    drv_spi.h	

    SPI���������ڶ�дEEPROM (AT25640)
*-------------------------------------------------------------------*/

#ifndef DRV_SPI_H
#define DRV_SPI_H

#include "DSP2833x_Device.h"

// SPI ����������
#define SPI_WREN     0x0600	 // ʹ��д
#define SPI_WRDI     0x0400	 // ��ֹд
#define SPI_RDSR     0x0500	 // ��״̬�Ĵ���
#define SPI_WRSR     0x0100	 // д״̬�Ĵ���
#define SPI_READ     0x0300	 // ��
#define SPI_WRITE    0x0200	 // д

// SPI ������
enum SPI_PROTECT
{
    SPI_PROTECT_NONE,          // �ޱ���������д
    SPI_PROTECT_HIGH_QUARTER,  // ������1/4���򣬵�3/4�����д
    SPI_PROTECT_HIGH_HALF,     // ������1/2���򣬵�1/2�����д
    SPI_PROTECT_ALL            // �����������򣬶�����д
};

/* ��ʼ��SPI */
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

// ����ϵͳ����
BOOLEAN SPI_saveSysCfg(void);

// ��ȡϵͳ����
BOOLEAN SPI_loadSysCfg(void);

// SPI��������
BOOLEAN SPI_test(void);

#endif
