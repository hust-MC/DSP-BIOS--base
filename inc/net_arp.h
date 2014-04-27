#ifndef NET_ARP_H
#define NET_ARP_H

#include "net_ethernet.h"
#include "DSP2833X_Device.h"

#define	MAXHWALEN		6		/**< Maximum HW address Length (6=Eth)*/
#define MAXPRALEN		4		/**< Maximum Protocol adr.len (4=IPv4)*/

/** \def ARP_TSIZE
 * 	\ingroup opentcp_config
 *	\brief ARP cache size (number of entries)
 *
 *	Change this number to change ARP cache size (number of cached 
 *	ARP:IP address pairs).
 *
 *	Changing this values affects memory consumption as well as processing
 *	power needed to manage the ARP cache. If a device communicates with 
 *	a limited number of hosts, this cache size may be smaller, thus 
 *	reducing memory requirements. Small cache size may, however, reduce
 *	performance when communicating with more hosts than there are cache
 *	entries available.
 */
#define ARP_TSIZE		10	

/** \def ARP_TIMEOUT
 * 	\ingroup opentcp_config
 *	\brief ARP cache entry refresh period (in seconds)
 *
 *	Change this number to change refresh period of ARP cache entries.
 *
 *	Changing this values changes the amount of ARP refreshes performed 
 *	and thus can change processing power used when refreshing the entries.
 */
#define ARP_TIMEOUT		60

/** \def ARP_RESEND
 * 	\ingroup opentcp_config
 *	\brief ARP Request resend period (in seconds)
 *
 *	Change this number to determine how quickly will ARP module issue
 *	ARP requests.
 *
 *	Changing this values changes the amount time that will elapse before
 *	ARP module resends it's ARP request in case no response has been
 *	received. Change this number according to expected network latency and
 *	desired resolving speed.
 */

#define ARP_RESEND		2	

/** \def ARP_MAXRETRY
 * 	\ingroup opentcp_config
 *	\brief Number of IP address resolving retires
 *
 *	Change this number to change number of times ARP module will resend
 *	ARP requests before giving up (if no ARP reply is received).
 */	
#define ARP_MAXRETRY	5		/**< Give up after x times			*/


/* System constants, don't modify	*/

#define AR_HARDWARE		0x0001	/* Ethernet hardware type code		*/
#define ARP_ETHCODE		0x0806	/* ARP over Ethernet				*/

#define ARP_REQUEST		1		/* ARP Request to resolve address	*/
#define ARP_REPLY		2		/* Reply to resolve request			*/

UINT16 ARP_process(UINT32 netAddr);
void ARP_sendResponse(UINT32 netAddr);

#endif

