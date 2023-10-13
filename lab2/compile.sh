#!/bin/bash

arm-none-eabi-as -mcpu=cortex-a8 -o startup.o startup.s
arm-none-eabi-gcc -c -g -mcpu=cortex-a8 -o uart_pl011.o uart_pl011.c 
arm-none-eabi-gcc -c -g -mcpu=cortex-a8 -o uart_test.o uart_test.c 
arm-none-eabi-gcc -nostartfiles -T uart_test.ld startup.o uart_pl011.o uart_test.o -o uart
arm-none-eabi-objcopy -O binary uart uart.bin
qemu-system-arm -M realview-pb-a8 -nographic -kernel uart.bin
