#ifndef TASK_CAN_H
#define TASK_CAN_H

#include "main.h"

#if NEW_CAN
// Can消息ID
struct NEW_CANMSGID_BITS
{
	UINT16 node_id_t:7; 		 // 目的节点设备编号
	UINT16 funcode:4;			 // 功能码
	UINT16 extend:2;		 // 保留，填0
	UINT16 extend_extra;	// 保留，填0
	UINT16 AAM:1;			 // 自动应答模式位
	UINT16 AME:1; 			 // 接收过滤使能位
    UINT16 IDE:1;          	 // 扩展位标识符
};

union NEW_CANMSGID
{
   UINT32				    all;
   struct NEW_CANMSGID_BITS bit;
};
#endif

// Can数据低4字节
struct MY_DATAL_BITS
{
   UINT16 BYTE4:8;	// 低位
   UINT16 BYTE3:8;
   UINT16 BYTE2:8;
   UINT16 BYTE1:8;	// 高位
};

union MY_DATAL {
   UINT32               all;
   struct MY_DATAL_BITS bit;
};

// Can数据高4字节
struct MY_DATAH_BITS
{
   UINT16 BYTE8:8;      
   UINT16 BYTE7:8;      
   UINT16 BYTE6:8;      
   UINT16 BYTE5:8;     
};

union MY_DATAH {
   UINT32               all;
   struct MY_DATAH_BITS bit;
};

#endif
