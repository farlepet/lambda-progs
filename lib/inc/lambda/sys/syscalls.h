#ifndef LAMBDA_LIB_LAMBDA_SYS_SYSCALLS_H
#define LAMBDA_LIB_LAMBDA_SYS_SYSCALLS_H

#include <stdint.h>

#define SYSCALL_GET_KTASK 0
#define SYSCALL_SEND_MSG  1
#define SYSCALL_RECV_MSG  2
#define SYSCALL_EXIT      3

void call_syscall(uint32_t scn, uint32_t *args);

#define IDLE_TASK_SLOT   0
#define KVID_TASK_SLOT   1
#define KBUG_TASK_SLOT   2
#define KINPUT_TASK_SLOT 3
#define KRNG_TASK_SLOT   4
#define KTERM_TASK_SLOT  5

int  syscall_get_ktask(int n, uint32_t time);
int  syscall_send_msg(int pid, void *msg, int size);
int  syscall_recv_msg(void *msg, int size);
void syscall_exit(int code);

#endif
