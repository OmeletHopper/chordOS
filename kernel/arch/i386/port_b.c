unsigned char read_port_b(unsigned short port) {
  unsigned char ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
  return ret;
}

void write_port_b(unsigned short port, unsigned char value) {
  asm volatile("outb %1, %0" : : "dN"(port), "a"(value));
}
