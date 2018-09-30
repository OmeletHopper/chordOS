#! /bin/bash

mkdir -p iso/boot/grub
cp grub.cfg iso/boot/grub/
cp kernel/*.elf iso/boot/kernel.elf
grub-mkrescue -o chordOS.iso iso
