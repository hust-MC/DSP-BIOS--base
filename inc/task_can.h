#ifndef TASK_CAN_H
#define TASK_CAN_H

#include "main.h"

#if NEW_CAN
// Can��ϢID
struct NEW_CANMSGID_BITS
{
	UINT16 node_id_t:7; 		 // Ŀ�Ľڵ��豸���
	UINT16 funcode:4;			 // ������
	UINT16 extend:2;		 // ��������0
	UINT16 extend_extra;	// ��������0
	UINT16 AAM:1;			 // �Զ�Ӧ��ģʽλ
	UINT16 AME:1; 			 // ���չ���ʹ��λ
    UINT16 IDE:1;          	 // ��չλ��ʶ��
};

union NEW_CANMSGID
{
   UINT32				    all;
   struct NEW_CANMSGID_BITS bit;
};
#endif

// Can���ݵ�4�ֽ�
struct MY_DATAL_BITS
{
   UINT16 BYTE4:8;	// ��λ
   UINT16 BYTE3:8;
   UINT16 BYTE2:8;
   UINT16 BYTE1:8;	// ��λ
};

union MY_DATAL {
   UINT32               all;
   struct MY_DATAL_BITS bit;
};

// Can���ݸ�4�ֽ�
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
