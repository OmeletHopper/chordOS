# chordOS [![Build Status](https://travis-ci.org/OmeletHopper/chordOS.svg?branch=master)](https://travis-ci.org/OmeletHopper/chordOS)
**Copyright (c) 2018 Jonathan Archer.**

<img alt="chordOS Splash" src="/docs/images/splash.png"/>

## Building
This section explains how to build chordOS. The packages that are required to build are `make`, `nasm`, `clang`, and `binutils`. Also, `grub-pc-bin` and `xorriso` are needed to make the ISO.

### Kernel
To build the kernel, all you have to do is run `make -C kernel` in the root source directory.

### ISO
After you've built everything above and would like a bootable image, simply run `./make_iso.sh` in the source directory, and you will get a bootable image named `chordOS.iso`.
