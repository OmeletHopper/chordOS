#include <kernel/i386/idt.h>
#include <kernel/i386/isr.h>
#include <kernel/ports.h>

void idt_set_gate(int irq, unsigned long ptr) {
  isr_set_gate(irq + PIC_OFFSET, ptr);
}
