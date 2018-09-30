#include <kernel/video.h>

void k_clear_screen(char color) {
  for (int i = 0; i < 80 * 25; i++)
    k_putchar(color, ' ');
  video_pos = 0;
  k_update_cursor();
}
