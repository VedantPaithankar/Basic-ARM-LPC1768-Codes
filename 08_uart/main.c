#include "uart.h"
#include <string.h>

int main()
{
	char str[32];
	uart_init(9600);
	while(1)
	{
		uart_puts("Enter new string: \r\n");
		uart_gets(str);
		strupr(str);
		uart_puts(str);
	}
}

