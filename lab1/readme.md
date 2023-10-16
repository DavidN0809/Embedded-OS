### Guide is in .txt

changed 
qemu-system-arm -M versatilepb -m 128M -nographic -kernel hello_world.bin
to
qemu-system-arm -M versatilepb -m 128M -nographic -kernel hello_world.bin 2>/dev/null


due to
david@pop-os:~/Documents/GitHub/Embedded-OS/lab1$ qemu-system-arm -M versatilepb -m 128M -nographic -kernel hello_world.bin
pulseaudio: set_sink_input_volume() failed
pulseaudio: Reason: Invalid argument
pulseaudio: set_sink_input_mute() failed
pulseaudio: Reason: Invalid argument
Hello world!
QEMU: Terminated


and 
qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel hello_world.bin
to
qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel hello_world.bin 2>/dev/null

due to
pulseaudio: set_sink_input_volume() failed
pulseaudio: Reason: Invalid argument
pulseaudio: set_sink_input_mute() failed
pulseaudio: Reason: Invalid argument
QEMU: Terminated

All this change does is hide the failed/invalid arguments

to connect hand to run
(gdb) target remote 127.0.0.1:1234
