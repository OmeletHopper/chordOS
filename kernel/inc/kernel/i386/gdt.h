#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct gdt_entry {
  unsigned short limit_low;
  unsigned short base_low;
  unsigned char base_mid;
  unsigned char access;
  unsigned char gran;
  unsigned char base_high;
} __attribute__((packed));

struct gdt_pointer {
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

void gdt_flush();
void gdt_load();
void gdt_set_gate(int, unsigned long, unsigned long, unsigned char,
                  unsigned char);

struct gdt_pointer gdt_ptr;
struct gdt_entry gdt[3];

#ifdef __cplusplus
}
#endif
