#include <kernel/i386/gdt.h>

void gdt_load() {
  gdt_ptr.limit = (sizeof(struct gdt_entry) * 3) - 1;
  gdt_ptr.base = (int)&gdt;

  gdt_set_gate(0, 0, 0, 0, 0);
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment.
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment.

  gdt_flush(&gdt_ptr);
}
