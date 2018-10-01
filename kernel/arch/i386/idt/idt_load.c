#include <kernel/i386/idt.h>
#include <kernel/ports.h>
#include <kernel/video.h>

void idt_load() {
  unsigned long idt_addr, idt_ptr[2];

  // Initialize
  write_port_b(0x20, 0x11);
  write_port_b(0xA0, 0x11);

  // Remap
  write_port_b(0x21, PIC_OFFSET);
  write_port_b(0xA1, PIC_OFFSET + 8);

  // Cascade
  write_port_b(0x21, 0x00);
  write_port_b(0xA1, 0x00);

  // Info
  write_port_b(0x21, 0x01);
  write_port_b(0xA1, 0x01);

  // Mask interrupts
  write_port_b(0x21, 0xFF);
  write_port_b(0xA1, 0xFF);

  idt_addr = (unsigned long)idt;
  idt_ptr[0] =
      (sizeof(struct idt_entry) * IDT_SIZE) + ((idt_addr & 0xffff) << 16);
  idt_ptr[1] = idt_addr >> 16;

  k_print(5, "Flushing IDT... ");
  idt_flush(idt_ptr);
  k_print(2, "[ OKAY ]\n");
}
