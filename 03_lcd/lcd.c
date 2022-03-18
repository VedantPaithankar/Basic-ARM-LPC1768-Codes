#include "lcd.h"

void lcd_init(void)
{
	// make data pins as output (dir)
	LCD_DATA_GPIO->FIODIR |= BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);
	// make ctrl pins as output (dir)
	LCD_CTRL_GPIO->FIODIR |= BV(LCD_RS) | BV(LCD_RW) | BV(LCD_EN);
	delay_ms(100);

	// set function (4-bit mode, 2 line display, 5x10 font)
	lcd_write(LCD_CMD, LCD_FUNCTION);
	// set display (display on, cursor off, blink off)
	lcd_write(LCD_CMD, LCD_DISPLAY);
	// set entry mode (incr addr)
	lcd_write(LCD_CMD, LCD_ENTRYMODE);
	// clear display
	lcd_write(LCD_CMD, LCD_CLEAR);
	delay_ms(100);
}

void lcd_write_nibble(uint32_t rs, uint8_t val)
{
	// make RS pin = 0 for command or = 1 for data.
	if(rs == LCD_CMD)
		LCD_CTRL_GPIO->FIOCLR = BV(LCD_RS);
	else
		LCD_CTRL_GPIO->FIOSET |= BV(LCD_RS);
		
	// make RW pin = 0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_RW);

	// write data on D4 to D7.
	LCD_DATA_GPIO->FIOCLR = BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);
	LCD_DATA_GPIO->FIOSET |= ((uint32_t)val & 0x0F) << LCD_D4;

	// make falling edge on EN
	LCD_CTRL_GPIO->FIOSET |= BV(LCD_EN);
	delay_ms(1);	
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_EN);
}

void lcd_busy_wait(void)
{
	// make D7 as input pin (dirn)
	LCD_DATA_GPIO->FIODIR &= ~BV(LCD_D7);
	// make RS pin = 0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_RS);
	// make RW pin = 1 & EN pin = 1
	LCD_CTRL_GPIO->FIOSET |= BV(LCD_RW) | BV(LCD_EN);

	// read D7 & wait if it is 1 
	while(LCD_DATA_GPIO->FIOPIN & BV(LCD_D7));
	
	// make EN pin = 0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_EN);
	// make D7 as output pin (dirn)
	LCD_DATA_GPIO->FIODIR |= BV(LCD_D7);
}

void lcd_write(uint32_t rs, uint8_t val)
{
	uint8_t hi = (val >> 4);
	uint8_t lo = (val & 0x0F);
	// write high nibble
	lcd_write_nibble(rs, hi);
	// write lower nibble
	lcd_write_nibble(rs, lo);
	// wait for busy flag
	lcd_busy_wait();
	delay_ms(3);
}

void lcd_puts(uint8_t line, char str[])
{
	int i;
	// set line addr
	lcd_write(LCD_CMD, line);
	// send char data one by one
	for(i=0; str[i]!='\0'; i++)
		lcd_write(LCD_DATA, str[i]);
}



