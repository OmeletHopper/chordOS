bits 32

extern kernel_main

global start
start:
          ; Clear Interrupts.
          cli
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
