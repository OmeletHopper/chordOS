bits 32

global gdt_flush
gdt_flush:
          mov edx, [esp + 4]
          lgdt [edx]
          mov ax, 0x10
          mov ds, ax
          mov es, ax
          mov fs, ax
          mov gs, ax
          mov ss, ax
          jmp 0x08:gdt_flush.jmp
gdt_flush.jmp:
          ret
