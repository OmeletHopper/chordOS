#include <kernel/video.h>

void k_newline() {
  if (video_pos + 160 > 80 * 25 * 2)
    k_video_scroll();
  video_pos += (160 - video_pos % (160));
  k_update_cursor();
}
