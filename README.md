# Embedded-OS
## Lab 0
### Goals
- Install curl from source
### How I did it
- make clean  # to clear out previous builds
- ./configure --with-openssl --prefix=/usr/local
- make
- sudo make install

To use ssl, specify openssl and prefix for where curl is

test with 
- curl --version 

if doesnt work
- export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

## Lab 1
### Goals
After this lab, you will be able to
  - Write a bare-metal “Hello World”
  - Write simple GNU linker scripts
  - Use gdb

## Lab 2
### Goals
After this lab, you will be to
  - understand the process of writing a device driver
  - Write a polling based baremetal driver for UART
  - Test the driver

## Lab 3
### Goals
After this lab, you will be able to
  - Build a Linux kernel image for ARM Versatile board
  - Build a root file system with Busybox
  - Use Buildroot to build an embedded Linux file system, and test application
