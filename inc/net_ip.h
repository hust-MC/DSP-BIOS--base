#ifndef NET_IP_H
#define NET_IP_H

#define MAX_IP_OPTLEN		40		/* Max IP Header option field length	*/

struct IP_Header
{
	UINT16	vihl;					/* Version & Header Length field */
	UINT16	tos;					/* Type Of Service				 */
	UINT16  tlen[2];				/* Total Length			 		 */
	UINT32	id;						/* IP Identification number		 */
	UINT32  frags;					/* Flags & Fragment offsett		 */
	UINT16	ttl;					/* Time to live					 */
	UINT16	protocol;				/* Protocol over IP				 */
	UINT32 	checksum;				/* Header Checksum				 */
	UINT16	sip[4];					/* Source IP address			 */
	UINT16	dip[4];					/* Destination IP address		 */
	UINT16	opt[MAX_IP_OPTLEN]; /* Option field					 */
};

UINT16 IP_readHeader(UINT32 netAddr);

#endif
