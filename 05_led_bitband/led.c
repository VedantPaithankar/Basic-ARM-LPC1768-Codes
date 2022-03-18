#include "led.h"

void led_init(void)
{
	// make LED pin as output
	BB_ALS(&LED_GPIO->FIODIR, LED) = 1;
	// led off
	led_off();
}

void led_on(void)
{
	// make LED pin high
	BB_ALS(&LED_GPIO->FIOSET, LED) = 1;
}

void led_off(void)
{
	// make LED pin low
	BB_ALS(&LED_GPIO->FIOCLR, LED) = 1;
}







