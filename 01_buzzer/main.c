#include "LPC17xx.h"

#define FIO2DIR (*(volatile uint32_t*)0x2009C040)
#define FIO2SET (*(volatile uint32_t*)0x2009C058)
#define FIO2CLR (*(volatile uint32_t*)0x2009C05C)
#define FIO2MASK (*(volatile uint32_t*)0x2009C050)

#define BUZZER 11

void buzzer_init(void);
void buzzer_off(void);
void buzzer_on(void);
void buzzer_beep(void);

int main()
{
	int i;
	buzzer_init();
	for(i=0; i<3; ++i)
	{
		buzzer_beep();
		delay_ms(2000);
	}
	while(1);
}

void buzzer_init(void)
{
	FIO2MASK = ~BV(BUZZER);
	FIO2DIR |= BV(BUZZER);
	buzzer_off();
}

void buzzer_off(void)
{
	FIO2SET |= BV(BUZZER);
}

void buzzer_on(void)
{
	FIO2CLR = BV(BUZZER);
}

void buzzer_beep(void)
{
	buzzer_on();
	delay_ms(2000);	
	buzzer_off();
}

