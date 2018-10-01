bits 32

extern kernel_main

section .text

global start
start:
          ; Clear Interrupts.
          cli
          ; Load our stack.
          mov esp, stack_top
          ; Disable flashing colors.
          mov dx, 0x3DA
          in al, dx
          mov dx, 0x3C0
          mov al, 0x30
          out dx, al
          inc dx
          in al, dx
          and al, 0xF7
          dec dx
          out dx, al
          ; Call our main C code.
          call kernel_main
          ; Infinite loop.
          jmp $

section .bss
align 4096

stack_bottom:
          resb 8192
stack_top:
