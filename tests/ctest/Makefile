MAINDIR    = $(CURDIR)

SRCS       = $(wildcard *.c)

OBJS       = $(patsubst %.c,%.o,$(SRCS))

CFLAGS    += -m32 -nostdlib -nostdinc -ffreestanding -Wall -Wextra -Werror
LDFLAGS    = -melf_i386 -T ../../linker_test.ld

OUT        = ctest

link:   $(OBJS)
	@echo -e "\033[33m  \033[1mLinking sources\033[0m"
	@ld $(LDFLAGS) -o $(OUT) ../../crt/crt0.o $(OBJS)
	@objcopy -O binary ctest ctest.bin

all: link


# gcc:
%.o: %.c
	@echo -e "\033[32m  \033[1mCC\033[21m    \033[34m$<\033[0m"
	@$(CC) $(CFLAGS) -c -o $@ $<


clean:
	@rm -f $(OBJS) $(OUT)
