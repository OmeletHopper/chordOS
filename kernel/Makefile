BIN	:= kernel.elf
VERSION	:= 0.01
ARCH	:= i386

SRCS	:= $(shell find arch/$(ARCH)/ -name "*.s" -o -name "*.c")
SRCS	+= $(shell find src/ -name "*.c")

OBJS	:= $(patsubst %.s, %.o, $(patsubst %.c, %.o, $(SRCS)))

AS	:= nasm
CC	:= clang
LD	:= gold

ASFLAGS	:= -f elf32

CFLAGS	:= -target $(ARCH)-none-elf -Wall -Wextra
CFLAGS	+= -nostdlib -ffreestanding -fno-stack-protector
CFLAGS	+= -Iinc -D kernel_version=\"$(VERSION)\"

LFLAGS	:= -n -m elf_$(ARCH) --gc-sections -T arch/$(ARCH)/link.ld

.PHONY: all format clean

all: $(BIN)

format:
	clang-format -style=llvm -i \
	$(shell find . -name "*.c") \
	$(shell find . -name "*.h")

clean:
	-rm -r $(OBJS) $(BIN)

$(BIN): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $(BIN)
