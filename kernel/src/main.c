#include <kernel/i386/gdt.h>
#include <kernel/splash.h>
#include <kernel/video.h>

void kernel_main() {
  k_clear_screen(7);
  k_puts(8, k_name);
  k_print(7, " written exclusively by Jon Archer ][.\n\n");
  k_print(7, "(C) 2018 Jonathan Archer.\n");

  k_print_splash("%s\n", splash);

  k_print(7, "Starting ");
  k_puts(8, k_name);
  k_print(7, "...\n\n");

  gdt_load();
  idt_load();
}
