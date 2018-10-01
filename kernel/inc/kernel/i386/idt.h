#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define IDT_SIZE 256
#define PIC_OFFSET 32

struct idt_entry {
  unsigned short int low_bits_offset;
  unsigned short int selector;
  unsigned char zero;
  unsigned char type_attr;
  unsigned short int high_bits_offset;
} idt[IDT_SIZE];

void idt_flush();
void idt_load();
void idt_set_gate(int, unsigned long);
void isr_set_gate(int, unsigned long);

#ifdef __cplusplus
}
#endif
