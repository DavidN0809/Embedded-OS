#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "uart_pl011.h"


char buf[64];
uint8_t buf_idx = 0u;

static void handle_calc(const char* input) {
    int num1 = 0, num2 = 0;
    char op = 0;
    char* ptr = (char*)input;

    // Skip the "calc" keyword
    while (*ptr && *ptr != ' ') ptr++;
    while (*ptr && *ptr == ' ') ptr++;

    // Parse the first number
    if (!*ptr) {
        uart_write("Missing first number.\n");
        return;
    }
    while (*ptr && *ptr >= '0' && *ptr <= '9') {
        if (num1 > INT_MAX/10) {
            uart_write("First number too large.\n");
            return;
        }
        num1 = num1 * 10 + (*ptr - '0');
        ptr++;
    }
    while (*ptr && *ptr == ' ') ptr++;

    // Check for operator
    if (!*ptr) {
        uart_write("Missing operator.\n");
        return;
    }

    // Parse the operator
    op = *ptr;
    ptr++;
    while (*ptr && *ptr == ' ') ptr++;

    // Parse the second number
    if (!*ptr) {
        uart_write("Missing second number.\n");
        return;
    }
    while (*ptr && *ptr >= '0' && *ptr <= '9') {
        if (num2 > INT_MAX/10) {
            uart_write("Second number too large.\n");
            return;
        }
        num2 = num2 * 10 + (*ptr - '0');
        ptr++;
    }
    while (*ptr && *ptr == ' ') ptr++;

    // Check for extraneous characters after parsing
    if (*ptr && *ptr != '\r') {
        uart_write("Invalid characters detected after command.\n");
        return;
    }

    // Perform the operation
    int result;
    char output[20];
    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': 
            if (num2 != 0) result = num1 / num2;
            else {
                uart_write("Division by zero error!\n");
                return;
            }
            break;
        default: 
            uart_write("Invalid operation!\n");
            return;
    }
    
    // Format and print the result
    int len = 0;
    int temp = result;
    do {
        output[len++] = '0' + temp % 10;
        temp /= 10;
    } while (temp);
    for (int i = 0; i < len / 2; i++) {
        char t = output[i];
        output[i] = output[len - 1 - i];
        output[len - 1 - i] = t;
    }
    output[len] = '\n';
    output[len + 1] = '\0';
    uart_write(output);
}

static void parse_cmd(void) {
    if (!strncasecmp("help\r", buf, strlen("help\r"))) {
        uart_write("Just type and see what happens!\n");
    } else if (!strncasecmp("uname\r", buf, strlen("uname\r"))) {
        uart_write("bare-metal arm 06_uart\n");
    } else if (!strncasecmp("calc", buf, 4)) {
        handle_calc(buf);
    }
}

int main() {
        uart_config config = {
            .data_bits = 8,
            .stop_bits = 1,
            .parity = false,
            .baudrate = 9600
        };
        uart_configure(&config);

        uart_putchar('A');
        uart_putchar('B');
        uart_putchar('C');
        uart_putchar('\n');

        uart_write("I love drivers!\n");
        uart_write("Type below...\n");

        char buffer[100];
        int buf_idx = 0;

        while (1) {
            char c;
            if (uart_getchar(&c) == UART_OK) {
                uart_putchar(c);
                buf[buf_idx % 64] = c;
                buf_idx++;
                if (c == '\r') {
                    uart_write("\n");
                    buf_idx = 0u;
                    parse_cmd();
                }
            }
        }

        return 0;
}

