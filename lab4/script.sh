set -e 
cd uart_linux_driver
make
cp vpb_uart.ko ~/Documents/GitHub/Embedded-OS/lab4/rootfs/
cp vpb_uart_test ~/Documents/GitHub/Embedded-OS/lab4/rootfs/
cp vpb_uart_init.sh ~/Documents/GitHub/Embedded-OS/lab4/rootfs/
cd ..
cd rootfs
find . -print0 | cpio --null -ov --format=newc | gzip -9 > ../rootfs.cpio.gz
cd ..
qemu-system-arm -M versatilepb -kernel linux-6.5.7/arch/arm/boot/zImage -dtb linux-6.5.7/arch/arm/boot/dts/arm/versatile-pb.dtb -initrd rootfs.cpio.gz -serial stdio -append "root=/dev/mem serial=ttyAMA0"
