MAINDIR    = $(CURDIR)
LIB        = $(MAINDIR)/../../lib
LIBINC     = $(LIB)/inc

SRCS       = $(wildcard *.c)

OBJS       = $(patsubst %.c,%.o,$(SRCS))

CFLAGS    += -m32 -nostdlib -nostdinc -ffreestanding -Wall -Wextra -Werror -fno-stack-protector -I$(LIBINC)
LDFLAGS    = -melf_i386 -T $(LIB)/linker.ld

OUT        = ipc-test

link:   $(OBJS)
	@echo -e "\033[33m  \033[1mLinking sources\033[0m"
	@ld $(LDFLAGS) -o $(OUT) $(LIB)/crt/crt0.o $(OBJS) $(LIB)/liblambda.a
#@objcopy -O binary $(OUT) $(OUT).bin

all: link


# gcc:
%.o: %.c
	@echo -e "\033[32m  \033[1mCC\033[21m    \033[34m$<\033[0m"
	@$(CC) $(CFLAGS) -c -o $@ $<


clean:
	@rm -f $(OBJS) $(OUT) $(OUT).bin
