#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

bool cursor_enabled;
char *video_address;
int video_pos;

void k_clear_screen(char);
void k_newline();
void k_print_splash(char *, ...);
void k_print(char, char *, ...);
void k_putchar(char, char);
void k_puts(char, const char *);
void k_update_cursor();
void k_video_scroll();

#ifdef __cplusplus
}
#endif
