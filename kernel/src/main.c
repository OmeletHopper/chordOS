#include <kernel/splash.h>
#include <kernel/video.h>

void kernel_main() {
  k_clear_screen(7);
  k_puts(8, "chord OS");
  k_print(7, " written exclusively by Jon Archer ][.\n");

  k_print_splash("%s\n", splash);

  k_print(7, "Starting ");
  k_puts(8, "chord OS");
  k_print(7, "...\n\n");
}
