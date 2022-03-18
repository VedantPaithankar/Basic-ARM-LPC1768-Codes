#include "eint.h"
#include "buzzer.h"


volatile int eint2_flag = 0;

void eint2_init(void)
{
	//1. change dirn of port as input.
	LPC_GPIO2->FIODIR &= ~BV(EINT2IO);
	//2. change P2.12 function as EINT (using PINSEL4 [25:24] = 01).
	LPC_PINCON->PINSEL4 &= ~(BV(25) | BV(24));
	LPC_PINCON->PINSEL4 |= BV(24);
	//3. configure pin as rising edge intr (EXTMODE & EXTPOLAR).
	LPC_SC->EXTMODE |= BV(EINT2);
	LPC_SC->EXTPOLAR |= BV(EINT2);
	//4. clear extint.2 bit.
	LPC_SC->EXTINT |= BV(EINT2);
	//5. enable eint2 interrupt in NVIC.
	NVIC_EnableIRQ(EINT2_IRQn);
}

void EINT2_IRQHandler(void)
{
	//1. set a flag.
	eint2_flag = 1;
	//2. clear extint.2 bit.
	LPC_SC->EXTINT |= BV(EINT2);
}


