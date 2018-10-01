#include <kernel/i386/gdt.h>
#include <kernel/video.h>

void gdt_load() {
  gdt_ptr.limit = (sizeof(struct gdt_entry) * 3) - 1;
  gdt_ptr.base = (int)&gdt;

  gdt_set_gate(0, 0, 0, 0, 0);
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment.
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment.

  k_print(5, "Flushing GDT... ");
  gdt_flush(&gdt_ptr);
  k_print(2, "[ OKAY ]\n");
}
