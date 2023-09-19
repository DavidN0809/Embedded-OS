# Embedded-OS
## Lab 0
- Install curl from source
- make clean  # to clear out previous builds
- ./configure --with-openssl --prefix=/usr/local
- make
- sudo make install

To use ssl, specify openssl and prefix for where curl is

test with 
- curl --version 

if doesnt work
- export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
