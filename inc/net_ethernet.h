#ifndef ETHERNET_H 
#define ETHERNET_H

#include "DSP2833X_Device.h"

#define	PROTOCOL_IP			0x0800			/* IP over Ethernet	*/
#define PROTOCOL_ARP		0x0806			/* ARP over Ethernet */

#define RX_BUF_SIZE 1518

#define	ETH_ADDRESS_LEN	 6
#define	ETH_HEADER_LEN   14

#define	ARP_BUFFER	0x5F	/* 256 byte Tx for ARP */
#define	ICMP_BUF	0x4D	/* 1536 byte Tx for ICMP */
#define	TCP_BUF		0x53	/* 1536 byte Tx for TCP */
#define	UDP_BUF		0x59	/* 1536 byte Tx for UDP */

#define XC_SHORT_LEN 44
#define XC_LONG_LEN  102

/* Ethernet frame struct */
struct ETH_Header
{
	// 目的MAC地址
	UINT16 desMAC[ETH_ADDRESS_LEN];
	
	// 源MAC地址
	UINT16 srcMAC[ETH_ADDRESS_LEN];					

	// 协议
	UINT16 protocol[2];
};

/* API prototypes */

void ETH_processFrame(UINT32 netAddr);

// Init Ethernet
void ETH_init(UINT32 netAddr, UINT16* mac);

/* Receive Frame */

// Receive single frame to buffer
UINT16 ETH_receiveFrame(UINT32 netAddr);
// Init reading from buffer
void ETH_initRead(UINT32 netAddr, BOOLEAN isLong);
// Read byte from buffer
UINT16 ETH_readByte(UINT32 netAddr);
// Read ethernet frame header from buffer
void ETH_readHeader(UINT32 netAddr, BOOLEAN isLong);
// Skip some bytes
void ETH_skipByte(UINT32 netAddr, UINT16 skipNum);

/* Send Frame */

// Init write buffer 
void ETH_initWrite(UINT32 netAddr);
// Write eth header to buffer
void ETH_writeHeader(UINT32 netAddr, struct ETH_Header* header);
// Write byte to buffer
void ETH_writeByte(UINT32 netAddr, UINT16 dat);
// Begin to send single frame to PHY
void ETH_sendFrame(UINT32 netAddr, UINT16 dataLength);

#endif

