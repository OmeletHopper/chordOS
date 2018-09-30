#include <kernel/i386/gdt.h>

void gdt_set_gate(int i, unsigned long base, unsigned long limit,
                  unsigned char access, unsigned char gran) {
  gdt[i].base_low = (base & 0xFFFF);
  gdt[i].base_mid = (base >> 16) & 0xFF;
  gdt[i].base_high = (base >> 24) & 0xFF;
  gdt[i].limit_low = (limit & 0xFFFF);
  gdt[i].gran = ((limit >> 16) & 0x0F);
  gdt[i].gran |= (gran & 0xF0);
  gdt[i].access = access;
}
