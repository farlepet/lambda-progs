MAINDIR    = $(CURDIR)
SRC        = $(MAINDIR)/src
INC        = $(MAINDIR)/inc

SRCS       = $(wildcard $(SRC)/*.c) $(wildcard $(SRC)/*/*.c) $(wildcard $(SRC)/*/*/*.c) $(wildcard $(SRC)/*/*/*/*.c)

OBJS       = $(patsubst %.c,%.o,$(SRCS))

CFLAGS    += -m32 -nostdlib -nostdinc -ffreestanding -Wall -Wextra -Werror -fno-stack-protector -I $(INC)
LDFLAGS    = -melf_i386 -T ../../linker_test.ld

OUT        = liblambda.a

link:   $(OBJS)
	@echo -e "\033[33m  \033[1mCombining Objects\033[0m"
	@ar rvs --target=elf32-i386 $(OUT) $(OBJS) &> /dev/null

all: link


# gcc:
%.o: %.c
	@echo -e "\033[32m  \033[1mCC\033[21m    \033[34m$<\033[0m"
	@$(CC) $(CFLAGS) -c -o $@ $<


clean:
	@rm -f $(OBJS) $(OUT)
