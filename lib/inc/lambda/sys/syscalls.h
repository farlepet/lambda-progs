#ifndef LAMBDA_LIB_LAMBDA_SYS_SYSCALLS_H
#define LAMBDA_LIB_LAMBDA_SYS_SYSCALLS_H

#include <stdint.h>

#include <lambda/sys/ipc.h>

#define SYSCALL_GET_KTASK 0
#define SYSCALL_SEND_MSG  1
#define SYSCALL_RECV_MSG  2
#define SYSCALL_EXIT      3

#define SYSCALL_IPC_SEND              4
#define SYSCALL_IPC_RECV              5
#define SYSCALL_IPC_RECV_PID          6
#define SYSCALL_IPC_RECV_BLOCKING     7
#define SYSCALL_IPC_RECV_PID_BLOCKING 8
#define SYSCALL_IPC_COPY_MSG          9
#define SYSCALL_IPC_DELETE_MSG        10
#define SYSCALL_IPC_BLOCK_PID         11

#define SYSCALL_FS_READ    12
#define SYSCALL_FS_WRITE   13
#define SYSCALL_FS_OPEN    14
#define SYSCALL_FS_CLOSE   15
#define SYSCALL_FS_READDIR 16
#define SYSCALL_FS_FINDDIR 17
#define SYSCALL_FS_MKDIR   18
#define SYSCALL_FS_CREATE  19
#define SYSCALL_FS_IOCTL   20

void call_syscall(uint32_t scn, uint32_t *args);

#define IDLE_TASK_SLOT   0
#define KVID_TASK_SLOT   1
#define KBUG_TASK_SLOT   2
#define KINPUT_TASK_SLOT 3
#define KRNG_TASK_SLOT   4
#define KTERM_TASK_SLOT  5

/**
 * Requests the PID of a given KTASK
 *
 * @param n KTASK ID
 * @param time Time in seconds to allow for waiting for the KTASK to spawn, 0 means infinite
 *
 * @return The PID of the requested KTASK, or 0 if not found
 */
int  syscall_get_ktask(int n, uint32_t time);

/**
 * Send a message to a task with the given PID
 *
 * @param pid Task PID
 * @param msg Pointer to message
 * @param size Size of message
 */
int  syscall_send_msg(int pid, void *msg, int size);

/**
 * Wait for and receive a message
 *
 * NOTE: This is unsafe/unreliable, as any task can send a message that may not
 * be the expected size of format.
 *
 * @param msg Pointer to message buffer to store message in
 * @param size Size of message to read
 */
int  syscall_recv_msg(void *msg, int size);

/**
 * Ends this task with the given code.
 *
 * @param code Code to exit with
 */
void syscall_exit(int code);

#endif
