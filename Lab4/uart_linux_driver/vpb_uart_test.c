#include <stdio.h>
#include <ctype.h>

#define DEVNAME	"/dev/vpb_uart"

int main(void) {
	FILE *uart_dev;

	uart_dev = fopen(DEVNAME, "r+");
	fputc('A', uart_dev);
	fputc('B', uart_dev);
	fputc('C', uart_dev);

	
	fclose(uart_dev);
	return 0;
}
