#include <kernel/video.h>

void k_video_scroll() {
  for (int i = 0; i < 25; i++)
    for (int j = 0; j < 80 * 2; j++)
      video_address[i * 80 * 2 + j] = video_address[(i + 1) * 80 * 2 + j];
  video_pos -= 80 * 2;
  k_update_cursor();
}
