#! /bin/bash

echo "Compiling boot.s  ..."

i686-elf-as source/boot.s -o binaries/boot.o

echo "Compiling kernel..."

i686-elf-gcc -c source/kernel.c -o binaries/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

echo "Linking ..."

i686-elf-gcc -T source/linker.ld -o bin/muos.bin -ffreestanding -O2 -nostdlib binaries/boot.o binaries/kernel.o -lgcc

echo "Generating iso file..."

cd $HOME/Desktop/isodir/boot
rm muos.bin
cd $HOME/Documents/RandomOS
cp bin/muos.bin $HOME/Desktop/isodir/boot
cd $HOME/Desktop

grub-mkrescue -o muos.iso isodir    &> /dev/null
qemu-system-i386 -cdrom muos.iso    &> /dev/null
