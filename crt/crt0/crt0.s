# CRT0.s

.global start
start:
	call main

prog_exit:
	push $0        # Argument array
	mov %esp, %ebx # Pointer to argument array
	mov $3, %eax   # SYSCALL_EXIT
	int $0xFF      # Syscall

.inf_loop:         # Shouldn't get here with the syscall
	hlt
	jmp .inf_loop
