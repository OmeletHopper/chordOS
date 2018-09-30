#include <kernel/video.h>

void k_print(char color, char *format, ...) {
  int i = 0;
  __builtin_va_list va;
  __builtin_va_start(va, format);
  while (format[i] != '\0') {
    switch (format[i]) {
    case '\n':
      k_newline();
      i++;
      break;
    case '%':
      i++;
      switch (format[i]) {
      case 's':
        k_print(color, __builtin_va_arg(va, char *));
        break;
      }
      i++;
      break;
    default:
      k_putchar(color, format[i++]);
    }
  }
  __builtin_va_end(va);
}
