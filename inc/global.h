#ifndef GLOBAL_H
#define GLOBAL_H

#include "DSP2833x_Device.h"
#include "net_ethernet.h"
#include "net_ip.h"

/*
 * ��������
 */

/*------------------------------------------------------------------------------
    _SYS_OBJ

    System object define
------------------------------------------------------------------------------*/
typedef struct _SYS_OBJ
{
	// �ⲿ�洢��״̬
	// ����write-read����
	BOOLEAN isSRAMOK;
	
	// CANA״̬
	// ����loopback����
	BOOLEAN isCANAOK;

	// CANB״̬
	// ����loopback����
	BOOLEAN isCANBOK;

	// SCIB״̬
	// ����loopback����
	BOOLEAN isSCIOK;

	// SPI״̬
	// ��������PC���Ĳ���ʱwrite-read����
	BOOLEAN isSPIOK;

	// NET1״̬
	// ��task_cal�ж�NET1��MAC��ַ����write-read����
	BOOLEAN isNet1OK;

	// NET2״̬
	// ��task_cal�ж�NET2��MAC��ַ����write-read����
	BOOLEAN isNet2OK;

	// NET3״̬
	// ��task_net�в�ѯ��ؼĴ�����״̬
	BOOLEAN isNet3OK;
}
SYS_Obj, *SysHandle;

/*------------------------------------------------------------------------------
	SysGetObj()

 	Get the system object handle

	Return:
		pointer to SysObj
------------------------------------------------------------------------------*/
SysHandle SysGetObj(void);

/*------------------------------------------------------------------------------
    _NET_OBJ

    Net object define
------------------------------------------------------------------------------*/
typedef struct _NET_OBJ
{
	// ������ַ
	UINT32 netAddr;

	BOOLEAN isNetLeftOK;

	BOOLEAN isNetRightOK;

	// ����MAC��ַ
	UINT16 localMAC[6];

	// ����IP��ַ
	UINT16 localIP[4];

	// Net3Ŀ��IP��ַ
	UINT16 desIP[4];

	// �鲥IP��ַ
	UINT16 groupIP[4];

// NET1/NET2��ز���

	// �̰�IP - ��̬
	UINT16 shortIPA[4];

	// �̰�IP - ��̬
	UINT16 shortIPB[4];

	// ����IP - ����
	UINT16 longIPA[4];

	// ����IP - ����
	UINT16 longIPB[4];

	// NET1/NET2�Ƿ���յ���̫��֡
	BOOLEAN isNet1Received;
	BOOLEAN isNet1LongReceived;
	BOOLEAN isNet2Received;
	BOOLEAN isNet2LongReceived;
	
	// �Ƿ��������ź�
	BOOLEAN hasSignal;

	// NET1�������ռ��� & ��������
	UINT32 net1LongPacketCount;
	UINT32 net1LongPacketBkCount;

	// NET2�������ռ��� & ��������
	UINT32 net2LongPacketCount;
	UINT32 net2LongPacketBkCount;

	// NET1, NET2���յ��İ���
	// ������������SCI��ת��net��ʱ����֪�䷢�ͳ���
	UINT16 net1RxLen;	// net1��ǰ���յ��İ���
	UINT16 net2RxLen;	// net2��ǰ���յ��İ���

	// NET1����buffer
	UINT16 eth_net1_rx_buf[1518];
	// NET1��������buffer
	UINT16 eth_net1_long_rx_buf[150];
	// NET1��ָ��
	UINT16 * eth_net1_rx_buf_ptr;	

	// NET2����buffer
	UINT16 eth_net2_rx_buf[1518];
	// NET2��������buffer
	UINT16 eth_net2_long_rx_buf[150];
	// NET2��ָ��
	UINT16 * eth_net2_rx_buf_ptr;	

	// NET1, NET2����buffer
	UINT16 eth_tx_buf[1518];
	UINT16 * eth_tx_buf_ptr;	// дָ��

	// NET1 ���յ���̫��֡ͷ
	struct ETH_Header eth_net1_rx_header;

	// NET1 �����͵���̫��֡ͷ
	struct ETH_Header eth_net1_tx_header;

	// NET1 ���յ�IP֡ͷ
	struct IP_Header ip_net1_rx_header;
	
	// NET1 �����͵�IP֡ͷ
	struct IP_Header ip_net1_tx_header;

	// NET2 ���յ���̫��֡ͷ
	struct ETH_Header eth_net2_rx_header;

	// NET2 �����͵���̫��֡ͷ
	struct ETH_Header eth_net2_tx_header;

	// NET2 ���յ�IP֡ͷ
	struct IP_Header ip_net2_rx_header;
	
	// NET2 �����͵�IP֡ͷ
	struct IP_Header ip_net2_tx_header;

// NET3��ز���

	// NET3����buffer
	UINT16 eth_net3_rx_buf[1518];
	UINT16 * eth_net3_rx_buf_ptr;	// ��ָ��

	// NET3����buffer
	UINT16 eth_net3_tx_buf[1518];
	UINT16 * eth_net3_tx_buf_ptr;	// дָ��

	// NET3��������̫��֡ͷ
	struct ETH_Header eth_net3_tx_header;
	
	// NET3�����͵�IP֡ͷ
	struct IP_Header ip_net3_tx_header;
}
NET_Obj, *NetHandle;

/*------------------------------------------------------------------------------
	NetGetObj()

 	Get the net object handle

	Return:
		pointer to NetObj
------------------------------------------------------------------------------*/
NetHandle NetGetObj(void);


// ���ڼ�¼ϵͳ������Ϣ�Ľṹ��
/*------------------------------------------------------------------------------
    _LOG_OBJ

    Net object define
------------------------------------------------------------------------------*/
typedef struct 
{
	UINT32 net1ISRCount;
	UINT32 net1UDPCount;
	UINT32 net1LongCount;
	UINT32 net1ShortCount;
	UINT32 net1OverRunCount;
	
	UINT32 net2ISRCount;
	UINT32 net2UDPCount;
	UINT32 net2LongCount;
	UINT32 net2ShortCount;
	UINT32 net2OverRunCount;

	UINT32 net1RxStopCount;	
	UINT32 net2RxStopCount;

	UINT32 netSoftRstCount;
	UINT32 netHardRstCount;
	UINT32 canRstCount;
	UINT32 sciRstCount;
	UINT32 watchDogRstCount;

	UINT32 sysRunStatus;

}LOG_OBJ, *LogHandle;

LogHandle LogGetObj(void);


// ��Դ����ʱ��
struct PowerErrorTime
{
	UINT16 year:8;
	UINT16 month:8;
	UINT16 day:8;
	UINT16 hour:8;
	UINT16 minute:8;
	UINT16 second:8;
};

/*------------------------------------------------------------------------------
    _XC_OBJ

    XC object define
------------------------------------------------------------------------------*/
typedef struct _XC_OBJ
{
// ��������̬��Ϣ

	// ���� 
	FLOAT32 hangxiang;

	// ��ҡ
	FLOAT32 hengyao;

	// ��ҡ
	FLOAT32 zongyao;

	// ����
	FLOAT32 jingdu;

	// γ��
	FLOAT32 weidu;

// �شų�����

	// �شų��������
	INT32 hx;

	// �شų��������
	INT32 hy;

	// �شų��������
	INT32 hz;

// ��Դ����
	
	// ����
	UINT16 scale;

	// ��Դ��ַ
	INT32 powerAddr[5][4];

	// ��Դ����
	UINT16 powerType[5][4];

	// ��Դ������
	UINT32 powerIMax[5][4];

	// ��Դ�������
	INT32 powerICal[5][4];

	// ��Դ���㳬��״̬
	BOOLEAN powerExceedCal[5][4];

	// ��Դ����
	INT32 powerI[5][4];

	// ��Դ��ѹ
	INT32 powerV[5][4];

	// ��Դ����״̬
	BOOLEAN powerState[5][4];

	// ��Դ����״̬
	BOOLEAN powerExceed[5][4];

	// ��Դ����ٷֱ�
	UINT16 powerExceedPercentage[5][4];

	// ��Դ����ʱ��
	struct PowerErrorTime powerErrorTime[5][4];

	// ��Դ����״̬
	BOOLEAN powerError[5][4];

	// ����ģʽ
	UINT16 exceedMode;
	
	// ��ÿ����Դ��Can������
	UINT16 powerDataCount[5][4];

	// ��Դ������ʷ��¼
	struct POWER_EXCEED_COUNT
	{
		UINT16 index;		// ��ǰ����index
		UINT16 count[10];	// ���������1-���0-����
	} powerExceedCount[5][4];
}XC_Obj, *XCHandle;

/*------------------------------------------------------------------------------
	XCGetObj()

 	Get the xc object handle

	Return:
		pointer to XCObj
------------------------------------------------------------------------------*/
XCHandle XCGetObj(void);

/*------------------------------------------------------------------------------
    _SCI_OBJ

    SCI object define
------------------------------------------------------------------------------*/
typedef struct _SCI_OBJ
{
	// SCI��֡������ɱ�־
	BOOLEAN isReceived;

	// SCI���� 
	UINT16 rxBuf[512];
	UINT16 txBuf[512];
	
	// ���ͳ��ȳ�12����
	UINT16 quotient;

	// ���ͳ��ȳ�12������
	UINT16 odd;

	// ����֡�ĳ���
	UINT16 rxLen;

	//���ò�����д�����־
	UINT16 configFalse;

	UINT16 opNetCan;

	UINT16 resetFlag;

}SCI_Obj, *SCIHandle;

SCIHandle SCIGetObj(void);

/*------------------------------------------------------------------------------
    _CAN_OBJ

    Can object define
------------------------------------------------------------------------------*/
typedef struct _CAN_OBJ
{
	// ��ǰ������ECanԴ
	UINT16 currentCan;

	BOOLEAN isCanAOK;

	BOOLEAN isCanBOK;

	// Can���ݰ�
	UINT32 msgID;		// ID
	UINT32 msgDataH;	// ���ݸ�4bytes
	UINT32 msgDataL;	// ���ݵ�4bytes

	// Can�������ݻ���
	// 20����Դ��ÿ����Դ����Ƶ��Ϊ2Hz
	struct MSG_ARRAY
	{
		BOOLEAN isActive;
		UINT32 msgID;
		UINT32 msgDataH;
		UINT32 msgDataL;
	} msgArray[40];

	struct MSG_ARRAY* msgWritePtr; // дָ��
	struct MSG_ARRAY* msgReadPtr;	// ��ָ��
	struct MSG_ARRAY* msgStartPtr;	// ��ʼ��ַ
	struct MSG_ARRAY* msgEndPtr;	// ������ַ

	// Can���ݰ� - ��Դ��������
	UINT32 errMsgID;		// ID
	UINT32 errMsgDataH;	// ���ݸ�4bytes
	UINT32 errMsgDataL;	// ���ݵ�ytes

	// �Ƿ��յ�Can���ݰ�
	BOOLEAN isReceived;

	// �Ƿ���յ��紹�����ݰ�
	BOOLEAN isReceivedError;

	// CanA�İ������ͱ��ݰ�����
	UINT32 packetCountA;
	UINT32 packetBkCountA;

	// CanB�İ������ͱ��ݰ�����
	UINT32 packetCountB;
	UINT32 packetBkCountB;

}CAN_Obj, *CanHandle;

/*------------------------------------------------------------------------------
	CanGetObj()

 	Get the can object handle

	Return:
		pointer to CAN_Obj
------------------------------------------------------------------------------*/
CanHandle CanGetObj(void);

/*
 * Functions
 */

void InitGlobalObj(void);	// ��ʼ��ȫ�ֱ���
void XCInitObj(void);	// ��ʼ�����ű���
void LogInitObj(UINT16 opt);	// ��ʼ�����Ա���
void NetInitRstSignal(UINT16 opt);	// ��λ����

#endif



