#include <kernel/video.h>

char *video_address = (char *)0xb8000;
int video_pos = 0;

void k_putchar(char color, char character) {
  if (video_pos + 4 > 80 * 25 * 2)
    k_video_scroll();
  video_address[video_pos++] = character;
  video_address[video_pos++] = color;
  k_update_cursor();
}
