#include "lcd.h"

int main()
{
	lcd_init();
	lcd_puts(LCD_LINE1, "DESD @ SUNBEAM");
	lcd_puts(LCD_LINE2, "GOD BLESS YOU!");
	while(1);
}

