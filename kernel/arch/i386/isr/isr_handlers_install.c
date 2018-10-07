#include <kernel/i386/isr.h>
#include <kernel/video.h>

void isr_handlers_install() {
  k_print(5, "Installing ISR handlers... ");
  isr_set_gate(0, (unsigned)isr0);
  isr_set_gate(1, (unsigned)isr1);
  isr_set_gate(2, (unsigned)isr2);
  isr_set_gate(3, (unsigned)isr3);
  isr_set_gate(4, (unsigned)isr4);
  isr_set_gate(5, (unsigned)isr5);
  isr_set_gate(6, (unsigned)isr6);
  isr_set_gate(7, (unsigned)isr7);
  isr_set_gate(8, (unsigned)isr8);
  isr_set_gate(9, (unsigned)isr9);
  isr_set_gate(10, (unsigned)isr10);
  isr_set_gate(11, (unsigned)isr11);
  isr_set_gate(12, (unsigned)isr12);
  isr_set_gate(13, (unsigned)isr13);
  isr_set_gate(14, (unsigned)isr14);
  isr_set_gate(15, (unsigned)isr15);
  isr_set_gate(16, (unsigned)isr16);
  isr_set_gate(17, (unsigned)isr17);
  isr_set_gate(18, (unsigned)isr18);
  isr_set_gate(19, (unsigned)isr19);
  isr_set_gate(20, (unsigned)isr20);
  isr_set_gate(21, (unsigned)isr21);
  isr_set_gate(22, (unsigned)isr22);
  isr_set_gate(23, (unsigned)isr23);
  isr_set_gate(24, (unsigned)isr24);
  isr_set_gate(25, (unsigned)isr25);
  isr_set_gate(26, (unsigned)isr26);
  isr_set_gate(27, (unsigned)isr27);
  isr_set_gate(28, (unsigned)isr28);
  isr_set_gate(29, (unsigned)isr29);
  isr_set_gate(30, (unsigned)isr30);
  isr_set_gate(31, (unsigned)isr31);
  k_print(2, "[ OKAY ]\n");
}
