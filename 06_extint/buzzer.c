#include "buzzer.h"

void buzzer_init(void)
{
	// set buzzer pin as output
	BUZZER_GPIO->FIODIR |= BV(BUZZER);
	// buzzer off
	buzzer_off();
}

void buzzer_on(void)
{
	// set buzzer pin low
	BUZZER_GPIO->FIOCLR = BV(BUZZER);
}

void buzzer_off(void)
{
	// set buzzer pin high
	BUZZER_GPIO->FIOSET |= BV(BUZZER);
}

void buzzer_beep(void)
{
	buzzer_on();
	delay_ms(1000);
	buzzer_off();
}



