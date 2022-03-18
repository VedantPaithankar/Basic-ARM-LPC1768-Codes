#include "LPC17xx.h"
#include "led.h"

int main()
{
	led_init();
	while(1)
	{
		led_on();
		delay_ms(1000);
		led_off();
		delay_ms(1000);
	}
}

