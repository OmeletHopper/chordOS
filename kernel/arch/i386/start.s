bits 32

extern kernel_main

global start
start:
          cli
          call kernel_main
          jmp $
