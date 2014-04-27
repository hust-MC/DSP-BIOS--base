#ifndef NET_H
#define NET_H

#include <main.h>

#define NET_LEFT_ADDR   0x200000
#define NET_RIGHT_ADDR  0x204000
#define NET3_ADDR	    0x208000
#define NET_RST_ADDR    0x210000

// ¼¤»îÍø¿¨
void NET_active(void);

// ÅäÖÃÍø¿¨
void NET_init();

// ÇĞ»»ÍøÂçÔ´
void NET_switchNetSource(void);

#endif
