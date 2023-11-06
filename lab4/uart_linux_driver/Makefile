# Cross compilation Makefile for ARM
# Change KERN_SRC appropriately
KERN_SRC=../linux-6.5.7
obj-m = vpb_uart.o
 
all: 
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) modules
	arm-linux-gnueabi-gcc -Wall --static -O2 -mcpu=arm926ej-s vpb_uart_test.c -o vpb_uart_test

clean:
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) clean




