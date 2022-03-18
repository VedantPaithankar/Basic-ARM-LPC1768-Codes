#ifndef __LCD_H
#define __LCD_H

#include "LPC17xx.h"

#define LCD_DATA_GPIO LPC_GPIO2
#define LCD_D4	4
#define LCD_D5	5
#define LCD_D6	6
#define LCD_D7	7

#define LCD_CTRL_GPIO LPC_GPIO1
#define LCD_EN	22
#define LCD_RW	23
#define LCD_RS	24

#define LCD_CMD		0
#define LCD_DATA	1

#define LCD_LINE1	0x80
#define LCD_LINE2	0xC0

#define LCD_CLEAR		0x01
#define LCD_ENTRYMODE	0x06
#define LCD_DISPLAY		0x0C
#define LCD_FUNCTION	0x2C

void lcd_init(void);
void lcd_write_nibble(uint32_t rs, uint8_t val);
void lcd_busy_wait(void);
void lcd_write(uint32_t rs, uint8_t val);
void lcd_puts(uint8_t line, char str[]);

#endif














