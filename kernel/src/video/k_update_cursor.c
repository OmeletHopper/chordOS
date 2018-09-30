#include <kernel/ports.h>
#include <kernel/video.h>

bool cursor_enabled = false;

void k_update_cursor() {
  if (!cursor_enabled) {
    write_port_b(0x3D4, 0x0A);
    write_port_b(0x3D5, (read_port_b(0x3D5) & 0xC0) | 14);
    write_port_b(0x3D4, 0x0B);
    write_port_b(0x3D5, (read_port_b(0x3D5) & 0xE0) | 15);
  }
  write_port_b(0x3D4, 0x0F);
  write_port_b(0x3D5, (unsigned char)(video_pos / 2 & 0xFF));
  write_port_b(0x3D4, 0x0E);
  write_port_b(0x3D5, (unsigned char)((video_pos / 2 >> 8) & 0xFF));
}
