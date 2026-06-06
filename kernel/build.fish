#!usr/bin/fish

make mkern.bin
cp mkern.bin iso/boot/
grub-mkrescue -o mazeos.iso iso
qemu-system-i386 -cdrom mazeos.iso -m 256M
