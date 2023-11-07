#include <stdio.h>
#include <unistd.h> // For the usleep function

#define DEVNAME "/dev/vpb_uart"

int main(void) {
    FILE *uart_dev;


    uart_dev = fopen(DEVNAME, "r+");
    if (uart_dev == NULL) {
        perror("Failed to open the UART device");
        return -1;
    }

    fputc('A', uart_dev);
    fputc('B', uart_dev);
    fputc('C', uart_dev);


    // Flushing the output buffer to make sure the data is sent.
   // fflush(uart_dev);
/*    
    fputs(" entering fgetc ",uart_dev);
    int c = fgetc(uart_dev);
    fputs("\n passing fgetc ",uart_dev);
    if (c == EOF) {
        perror("Error receiving character");
        fclose(uart_dev);
        return -1;
    }

    fputc(c, uart_dev); // Echo the received character back. 
    fputs("passing fputc",uart_dev);
    // Flushing the output buffer to make sure the data is sent.
    fflush(uart_dev);
    */
    
    fclose(uart_dev);
    return 0;
}

