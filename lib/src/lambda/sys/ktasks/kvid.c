#include <lambda/sys/ktasks/kvid.h>
#include <lambda/sys/syscalls.h>
#include <lambda/sys/ipc.h>

static int kvid_pid;

void sys_kvid_init() {
	kvid_pid = syscall_get_ktask(KVID_TASK_SLOT, 0);
}

void sys_kvid_print(char *str) {
	if(kvid_pid)
	{
		struct kvid_print_m kpm;
		kpm.ktm.pid    = -8; //current_pid;
		kpm.ktm.type   = KVID_PRINT;
		kpm.kpm.string = str;
		//syscall_send_msg(kvid_pid, &kpm, sizeof(struct kvid_print_m));
		ipc_send_message(kvid_pid, &kpm, sizeof(struct kvid_print_m));
	}
}
