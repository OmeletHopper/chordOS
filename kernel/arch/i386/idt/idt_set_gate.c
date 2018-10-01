#include <kernel/i386/idt.h>
#include <kernel/ports.h>

void idt_set_gate(int irq, unsigned long ptr) {
  isr_set_gate(irq + PIC_OFFSET, ptr);
}

void isr_set_gate(int irq, unsigned long ptr) {
  idt[irq].low_bits_offset = (unsigned long)ptr & 0xffff;
  idt[irq].selector = 0x08; // Offset
  idt[irq].zero = 0;
  idt[irq].type_attr = 0x8e; // Gate
  idt[irq].high_bits_offset = ((unsigned long)ptr & 0xffff0000) >> 16;
}
