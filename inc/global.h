#ifndef GLOBAL_H
#define GLOBAL_H

#include "DSP2833x_Device.h"
#include "net_ethernet.h"
#include "net_ip.h"

/*
 * 变量声明
 */

/*------------------------------------------------------------------------------
    _SYS_OBJ

    System object define
------------------------------------------------------------------------------*/
typedef struct _SYS_OBJ
{
	// 外部存储器状态
	// 开机write-read测试
	BOOLEAN isSRAMOK;
	
	// CANA状态
	// 开机loopback测试
	BOOLEAN isCANAOK;

	// CANB状态
	// 开机loopback测试
	BOOLEAN isCANBOK;

	// SCIB状态
	// 开机loopback测试
	BOOLEAN isSCIOK;

	// SPI状态
	// 保存来自PC机的参数时write-read测试
	BOOLEAN isSPIOK;

	// NET1状态
	// 在task_cal中对NET1的MAC地址进行write-read测试
	BOOLEAN isNet1OK;

	// NET2状态
	// 在task_cal中对NET2的MAC地址进行write-read测试
	BOOLEAN isNet2OK;

	// NET3状态
	// 在task_net中查询相关寄存器的状态
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
	// 网卡地址
	UINT32 netAddr;

	BOOLEAN isNetLeftOK;

	BOOLEAN isNetRightOK;

	// 本机MAC地址
	UINT16 localMAC[6];

	// 本机IP地址
	UINT16 localIP[4];

	// Net3目的IP地址
	UINT16 desIP[4];

	// 组播IP地址
	UINT16 groupIP[4];

// NET1/NET2相关参数

	// 短包IP - 姿态
	UINT16 shortIPA[4];

	// 短包IP - 姿态
	UINT16 shortIPB[4];

	// 长包IP - 导航
	UINT16 longIPA[4];

	// 长包IP - 导航
	UINT16 longIPB[4];

	// NET1/NET2是否接收到以太网帧
	BOOLEAN isNet1Received;
	BOOLEAN isNet1LongReceived;
	BOOLEAN isNet2Received;
	BOOLEAN isNet2LongReceived;
	
	// 是否有网络信号
	BOOLEAN hasSignal;

	// NET1长包接收计数 & 计数备份
	UINT32 net1LongPacketCount;
	UINT32 net1LongPacketBkCount;

	// NET2长包接收计数 & 计数备份
	UINT32 net2LongPacketCount;
	UINT32 net2LongPacketBkCount;

	// NET1, NET2接收到的包长
	// 这里是用于在SCI中转发net包时，告知其发送长度
	UINT16 net1RxLen;	// net1当前接收到的包长
	UINT16 net2RxLen;	// net2当前接收到的包长

	// NET1接收buffer
	UINT16 eth_net1_rx_buf[1518];
	// NET1长包接收buffer
	UINT16 eth_net1_long_rx_buf[150];
	// NET1读指针
	UINT16 * eth_net1_rx_buf_ptr;	

	// NET2接收buffer
	UINT16 eth_net2_rx_buf[1518];
	// NET2长包接收buffer
	UINT16 eth_net2_long_rx_buf[150];
	// NET2读指针
	UINT16 * eth_net2_rx_buf_ptr;	

	// NET1, NET2发送buffer
	UINT16 eth_tx_buf[1518];
	UINT16 * eth_tx_buf_ptr;	// 写指针

	// NET1 接收的以太网帧头
	struct ETH_Header eth_net1_rx_header;

	// NET1 待发送的以太网帧头
	struct ETH_Header eth_net1_tx_header;

	// NET1 接收的IP帧头
	struct IP_Header ip_net1_rx_header;
	
	// NET1 待发送的IP帧头
	struct IP_Header ip_net1_tx_header;

	// NET2 接收的以太网帧头
	struct ETH_Header eth_net2_rx_header;

	// NET2 待发送的以太网帧头
	struct ETH_Header eth_net2_tx_header;

	// NET2 接收的IP帧头
	struct IP_Header ip_net2_rx_header;
	
	// NET2 待发送的IP帧头
	struct IP_Header ip_net2_tx_header;

// NET3相关参数

	// NET3接收buffer
	UINT16 eth_net3_rx_buf[1518];
	UINT16 * eth_net3_rx_buf_ptr;	// 读指针

	// NET3发送buffer
	UINT16 eth_net3_tx_buf[1518];
	UINT16 * eth_net3_tx_buf_ptr;	// 写指针

	// NET3待发送以太网帧头
	struct ETH_Header eth_net3_tx_header;
	
	// NET3待发送的IP帧头
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


// 用于记录系统运行信息的结构体
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


// 电源故障时间
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
// 导航、姿态信息

	// 航向 
	FLOAT32 hangxiang;

	// 横摇
	FLOAT32 hengyao;

	// 纵摇
	FLOAT32 zongyao;

	// 经度
	FLOAT32 jingdu;

	// 纬度
	FLOAT32 weidu;

// 地磁场参数

	// 地磁场北向分量
	INT32 hx;

	// 地磁场东向分量
	INT32 hy;

	// 地磁场垂向分量
	INT32 hz;

// 电源参数
	
	// 量程
	UINT16 scale;

	// 电源地址
	INT32 powerAddr[5][4];

	// 电源类型
	UINT16 powerType[5][4];

	// 电源最大电流
	UINT32 powerIMax[5][4];

	// 电源解算电流
	INT32 powerICal[5][4];

	// 电源解算超差状态
	BOOLEAN powerExceedCal[5][4];

	// 电源电流
	INT32 powerI[5][4];

	// 电源电压
	INT32 powerV[5][4];

	// 电源开关状态
	BOOLEAN powerState[5][4];

	// 电源超差状态
	BOOLEAN powerExceed[5][4];

	// 电源超差百分比
	UINT16 powerExceedPercentage[5][4];

	// 电源故障时间
	struct PowerErrorTime powerErrorTime[5][4];

	// 电源故障状态
	BOOLEAN powerError[5][4];

	// 超差模式
	UINT16 exceedMode;
	
	// 对每个电源的Can包计数
	UINT16 powerDataCount[5][4];

	// 电源超差历史记录
	struct POWER_EXCEED_COUNT
	{
		UINT16 index;		// 当前计数index
		UINT16 count[10];	// 超差计数：1-超差，0-正常
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
	// SCI单帧接收完成标志
	BOOLEAN isReceived;

	// SCI缓存 
	UINT16 rxBuf[512];
	UINT16 txBuf[512];
	
	// 发送长度除12的商
	UINT16 quotient;

	// 发送长度除12的余数
	UINT16 odd;

	// 接收帧的长度
	UINT16 rxLen;

	//配置参数烧写错误标志
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
	// 当前工作的ECan源
	UINT16 currentCan;

	BOOLEAN isCanAOK;

	BOOLEAN isCanBOK;

	// Can数据包
	UINT32 msgID;		// ID
	UINT32 msgDataH;	// 数据高4bytes
	UINT32 msgDataL;	// 数据低4bytes

	// Can接收数据缓冲
	// 20个电源，每个电源发送频率为2Hz
	struct MSG_ARRAY
	{
		BOOLEAN isActive;
		UINT32 msgID;
		UINT32 msgDataH;
		UINT32 msgDataL;
	} msgArray[40];

	struct MSG_ARRAY* msgWritePtr; // 写指针
	struct MSG_ARRAY* msgReadPtr;	// 读指针
	struct MSG_ARRAY* msgStartPtr;	// 起始地址
	struct MSG_ARRAY* msgEndPtr;	// 结束地址

	// Can数据包 - 电源故障数据
	UINT32 errMsgID;		// ID
	UINT32 errMsgDataH;	// 数据高4bytes
	UINT32 errMsgDataL;	// 数据低ytes

	// 是否收到Can数据包
	BOOLEAN isReceived;

	// 是否接收到电垂障数据包
	BOOLEAN isReceivedError;

	// CanA的包计数和备份包计数
	UINT32 packetCountA;
	UINT32 packetBkCountA;

	// CanB的包计数和备份包计数
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

void InitGlobalObj(void);	// 初始化全局变量
void XCInitObj(void);	// 初始化消磁变量
void LogInitObj(UINT16 opt);	// 初始化调试变量
void NetInitRstSignal(UINT16 opt);	// 复位网卡

#endif



