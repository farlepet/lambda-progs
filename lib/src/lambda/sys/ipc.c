#include <lambda/sys/syscalls.h>
#include <lambda/sys/ipc.h>

int ipc_send_message(int dest_pid, void *msg, uint32_t size) {
	uint32_t args[3] = { (uint32_t)dest_pid, (uint32_t)msg, size };
	call_syscall(SYSCALL_IPC_SEND, args);
	return (int)args[0];
}

int ipc_recv_message(struct ipc_message_user *msg) {
	uint32_t args[1] = { (uint32_t)msg };
	call_syscall(SYSCALL_IPC_RECV, args);
	return (int)args[0];
}

int ipc_recv_message_pid(struct ipc_message_user *umsg, int pid) {
	uint32_t args[3] = { (uint32_t)umsg, (uint32_t)pid };
	call_syscall(SYSCALL_IPC_RECV_PID, args);
	return (int)args[0];
}

int ipc_recv_message_blocking(struct ipc_message_user *umsg) {
	uint32_t args[1] = { (uint32_t)umsg };
	call_syscall(SYSCALL_IPC_RECV_BLOCKING, args);
	return (int)args[0];
}

int ipc_recv_message_pid_blocking(struct ipc_message_user *umsg, int pid) {
	uint32_t args[3] = { (uint32_t)umsg, (uint32_t)pid };
	call_syscall(SYSCALL_IPC_RECV_PID_BLOCKING, args);
	return (int)args[0];
}

int ipc_copy_message(uint32_t message_id, void *dest) {
	uint32_t args[3] = { (uint32_t)message_id, (uint32_t)dest };
	call_syscall(SYSCALL_IPC_COPY_MSG, args);
	return (int)args[0];
}

int ipc_delete_message(uint32_t message_id) {
	uint32_t args[1] = { (uint32_t)message_id };
	call_syscall(SYSCALL_IPC_DELETE_MSG, args);
	return (int)args[0];
}

int ipc_block_pid(int pid) {
	uint32_t args[1] = { (uint32_t)pid };
	call_syscall(SYSCALL_IPC_BLOCK_PID, args);
	return (int)args[0];
}