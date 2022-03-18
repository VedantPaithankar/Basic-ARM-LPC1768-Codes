#ifndef __LED_H
#define __LED_H

#include "LPC17xx.h"

#define BBS 0x20000000
#define BBAS 0x22000000
#define BB_ALS(bbrgr, bit) (*(uint32_t*)(BBAS + (((uint32_t)bbrgr-BBS)<<5) + (bit<<2)))

#define LED	29
#define LED_GPIO	LPC_GPIO1

void led_init(void);
void led_on(void);
void led_off(void);

#endif


