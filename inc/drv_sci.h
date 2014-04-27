#ifndef DRV_SCI_H
#define DRV_SCI_H

#include "DSP2833x_Device.h"

#define go_on   1
#define	finish	2
#define	wrong	3

#define	HEAD_L  	0
#define	HEAD_H  	1
#define	SUB			2
#define	CMD			3
#define	SEQ_L		4
#define	SEQ_H		5
#define	LEN_L		6
#define	LEN_H		7
#define	CHECK_L		8
#define	CHECK_H 	9
#define	EXPAND_L  	10
#define	EXPAND_H	11

#define SCI_BAUD_RATE_9600   0
#define SCI_BAUD_RATE_19200  1
#define SCI_BAUD_RATE_38400  2
#define SCI_BAUD_RATE_57600  3
#define SCI_BAUD_RATE_115200 4

void SCIB_init(UINT32 baudRate);
void SCIB_send(UINT16 len, UINT16 *buf);
BOOLEAN SCIB_test(void);

#endif
