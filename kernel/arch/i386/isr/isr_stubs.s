extern fault_handler

section .text
bits 32

global isr0
isr0:
    cli
    push byte 0
    push byte 0
    jmp isr_common

global isr1
isr1:
    cli
    push byte 0
    push byte 1
    jmp isr_common

global isr2
isr2:
    cli
    push byte 0
    push byte 2
    jmp isr_common

global isr3
isr3:
    cli
    push byte 0
    push byte 3
    jmp isr_common

global isr4
isr4:
    cli
    push byte 0
    push byte 4
    jmp isr_common

global isr5
isr5:
    cli
    push byte 0
    push byte 5
    jmp isr_common

global isr6
isr6:
    cli
    push byte 0
    push byte 6
    jmp isr_common

global isr7
isr7:
    cli
    push byte 0
    push byte 7
    jmp isr_common

global isr8
isr8:
    cli
    push byte 8
    jmp isr_common

global isr9
isr9:
    cli
    push byte 0
    push byte 9
    jmp isr_common

global isr10
isr10:
    cli
    push byte 10
    jmp isr_common

global isr11
isr11:
    cli
    push byte 11
    jmp isr_common

global isr12
isr12:
    cli
    push byte 12
    jmp isr_common

global isr13
isr13:
    cli
    push byte 13
    jmp isr_common

global isr14
isr14:
    cli
    push byte 14
    jmp isr_common

global isr15
isr15:
    cli
    push byte 0
    push byte 15
    jmp isr_common

global isr16
isr16:
    cli
    push byte 0
    push byte 16
    jmp isr_common

global isr17
isr17:
    cli
    push byte 0
    push byte 17
    jmp isr_common

global isr18
isr18:
    cli
    push byte 0
    push byte 18
    jmp isr_common

global isr19
isr19:
    cli
    push byte 0
    push byte 19
    jmp isr_common

global isr20
isr20:
    cli
    push byte 0
    push byte 20
    jmp isr_common

global isr21
isr21:
    cli
    push byte 0
    push byte 21
    jmp isr_common

global isr22
isr22:
    cli
    push byte 0
    push byte 22
    jmp isr_common

global isr23
isr23:
    cli
    push byte 0
    push byte 23
    jmp isr_common

global isr24
isr24:
    cli
    push byte 0
    push byte 24
    jmp isr_common

global isr25
isr25:
    cli
    push byte 0
    push byte 25
    jmp isr_common

global isr26
isr26:
    cli
    push byte 0
    push byte 26
    jmp isr_common

global isr27
isr27:
    cli
    push byte 0
    push byte 27
    jmp isr_common

global isr28
isr28:
    cli
    push byte 0
    push byte 28
    jmp isr_common

global isr29
isr29:
    cli
    push byte 0
    push byte 29
    jmp isr_common

global isr30
isr30:
    cli
    push byte 0
    push byte 30
    jmp isr_common

global isr31
isr31:
    cli
    push byte 0
    push byte 31
    jmp isr_common

isr_common:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, fault_handler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret
