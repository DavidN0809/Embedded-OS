#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVNAME "/dev/vpb_uart"

int main(void) {
    FILE *uart_dev;

    uart_dev = fopen(DEVNAME, "r+");
    if (uart_dev == NULL) {
        perror("Failed to open the UART device");
        return -1;
    }
    
  fputs("UART test program started. Type 'help' or 'uname' to get a response.\n",uart_dev);


     // Loop forever, reading characters from UART.
    while (1) {
        char ch;
        ssize_t ret = read(uart_dev, &ch, 1); // Read a character from the UART device.
        if (ret < 0) {
            perror("Error reading from UART device");
            usleep(100000); // Sleep for a short while before trying again
            continue;
        }

        // Echo the character back to UART
        write(uart_dev, &ch, 1);
    }
    
    close(uart_dev);
    return 0;
}


