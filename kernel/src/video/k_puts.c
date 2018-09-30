#include <kernel/video.h>

void k_puts(char color, const char *string) {
  for (int i = 0; string[i] != '\0'; i++)
    k_putchar(color, string[i]);
}
