#include <stdio.h>
#include <ctype.h>


#define DEVNAME	"/dev/vpb_uart"

int main(void) {
	FILE *uart_dev;

	uart_dev = fopen(DEVNAME, "r+");
	if (uart_dev == NULL) {
        perror("Failed to open the UART device");
        return -1;
    }

	fputc('a', uart_dev);
	fputc('b', uart_dev);
	fputc('c', uart_dev);

	
	fclose(uart_dev);
	return 0;
}

/*
int main(void) {
    FILE *uart_dev;
    int c;

    uart_dev = fopen(DEVNAME, "r+");
    if (uart_dev == NULL) {
        perror("Failed to open the UART device");
        return -1;
    }

    // Loop to echo characters
    while (1) {
        c = fgetc(uart_dev);  // Read a character from UART
        if (feof(uart_dev) || ferror(uart_dev)) {
            // Handle end of file or error
            break;
        }
        fputc(c, uart_dev);    // Write the character back to UART
    }

    fclose(uart_dev);
    return 0;
}
*/
