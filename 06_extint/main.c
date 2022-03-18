#include "buzzer.h"
#include "eint.h"

int main()
{
	buzzer_init();
	eint2_init();
	while(1);
}

