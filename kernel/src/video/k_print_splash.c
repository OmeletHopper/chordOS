#include <kernel/video.h>

void k_print_splash(char *format, ...) {
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
        k_print_splash(__builtin_va_arg(va, char *));
        break;
      }
      i++;
      break;
    default:
      if (format[i] == ' ')
        k_putchar(0, ' ');
      else if (format[i] == 'X')
        k_putchar(0xF0, ' ');
      else if (format[i] == 'x')
        k_putchar(0x80, ' ');
      i++;
    }
  }
  __builtin_va_end(va);
}
