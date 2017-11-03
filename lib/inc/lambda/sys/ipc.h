#ifndef LAMBDA_LIB_LAMBDA_SYS_IPC_H
#define LAMBDA_LIB_LAMBDA_SYS_IPC_H

#include <stdint.h>

/**
 * Defines a representation of a message that processes themselves may see.
 */
struct ipc_message_user {
    uint32_t message_id; ///< Message ID
    int      src_pid;    ///< PID of sending process
    uint32_t length;     ///< Length of message
};


/**
 * Send IPC message to given PID
 *
 * @param dest_pid Destination PID
 * @param msg Message contents
 * @param size Size of message
 * @return < 0 if error
 */
int ipc_send_message(int dest_pid, void *msg, uint32_t size);

/**
 * Receive IPC message, if one is available
 *
 * @param msg Where to store message information
 * @return < 0 if error
 */
int ipc_recv_message(struct ipc_message_user *msg);

/**
 * Receive message (user message structure) from specified PID, if available
 *
 * @param umsg Where to store message
 * @param pid PID of sending process
 * @return 0 on success, < 0 on error or no message
 */
int ipc_recv_message_pid(struct ipc_message_user *umsg, int pid);


/**
 * Receive message (user message structure), blocking if none available
 *
 * @param umsg Where to store message
 * @return 0 on success, < 0 on error
 */
int ipc_recv_message_blocking(struct ipc_message_user *umsg);

/**
 * Receive message (user message structure), blocking if none available
 *
 * @param umsg Where to store message
 * @param pid PID of sending process
 * @return 0 on success, < 0 on error
 */
int ipc_recv_message_pid_blocking(struct ipc_message_user *umsg, int pid);


/**
 * Copy message contents to specified destination, then delete message.
 *
 * @param message_id Message ID to copy from
 * @param dest Pointer to data destination
 * @return < 0 on error
 */
int ipc_copy_message(uint32_t message_id, void *dest);

/**
 * Delete given message
 *
 * @param message_id ID of message
 */
int ipc_delete_message(uint32_t message_id);

/**
 * Block PID from sending messages to this process
 *
 * @param pid PID of process to block
 * @return < 0 on error
 */
int ipc_block_pid(int pid);

#endif