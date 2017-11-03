#include <lambda/sys/syscalls.h>

void call_syscall(uint32_t scn, uint32_t *args)
{
	asm volatile("int $0xFF" :: "a"(scn), "b"((uint32_t)args));
}

int syscall_get_ktask(int n, uint32_t time) {
	uint32_t args[2] = { (uint32_t)n, time };
	call_syscall(SYSCALL_GET_KTASK, args);
	return (int)args[0];
}

int syscall_send_msg(int pid, void *msg, int size) {
	uint32_t args[3] = { (uint32_t)pid, (uint32_t)msg, (uint32_t)size };
	call_syscall(SYSCALL_SEND_MSG, args);
	return (int)args[0];
}

int syscall_recv_msg(void *msg, int size) {
	uint32_t args[2] = { (uint32_t)msg, (uint32_t)size };
	call_syscall(SYSCALL_RECV_MSG, args);
	return (int)args[0];
}

void syscall_exit(int code) {
	uint32_t args[1] = { (uint32_t)code };
	call_syscall(SYSCALL_EXIT, args);
	for(;;); // Shouldn't ever get here
}