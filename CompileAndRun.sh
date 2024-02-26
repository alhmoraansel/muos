#! /bin/bash

i686-elf-as source/boot.s -o binaries/boot.o

i686-elf-gcc -c source/kernel.c -o binaries/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

i686-elf-gcc -T source/linker.ld -o bin/muos.bin -ffreestanding -O2 -nostdlib binaries/boot.o binaries/kernel.o -lgcc

cp bin/muos.bin $HOME/Desktop/isodir/boot
cd $HOME/Desktop

grub-mkrescue -o muos.iso isodir
qemu-system-i386 -cdrom muos.iso
