#include "buzzer.h"
#include "eint.h"


int main()
{
	buzzer_init();
	eint2_init();
	while(1)
	{
		// wait while flag is 0
		while(eint2_flag == 0);
		// beep the buzzer
		buzzer_beep();
		// clear the flag
		eint2_flag = 0;
	}
}

