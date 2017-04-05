#ifndef LAMBDA_LIB_LAMBDA_SYS_KTASKS_KVID_H
#define LAMBDA_LIB_LAMBDA_SYS_KTASKS_KVID_H

#include <stdint.h>

enum kvid_types
{
	KVID_PRINT  = 0, //!< Print a message to the screen
	KVID_KERROR = 1  //!< Print information to the screen
};

struct kvid_type_msg //!< A type message to be sent to kvid
{
	int32_t pid;  //!< Sender's PID
	uint8_t type; //!< Type of kvid message
};

struct kvid_print_msg //!< A message telling kvid to print a string
{
	char *string; //!< A null-terminated string
};

struct kvid_kerror_msg //!< A message telling kvid to print a kernel message
{
	uint32_t error_level; //!< Error level for kerror
	char    *string;    //!< String for kerror to print
};

struct kvid_print_m //!< A structure holding an entire kvid print message
{
	struct kvid_type_msg  ktm;
	struct kvid_print_msg kpm;
};

struct kvid_kerror_m //!< S structure holding an entire kvid kerror message
{
	struct kvid_type_msg   ktm;
	struct kvid_kerror_msg kkm;
};


/**
 * Initialize KVID system. Retrieves KVID's PID and stores it.
 */
void sys_kvid_init();

/**
 * Send a message via KVID
 *
 * @param str String to display
 */
void sys_kvid_print(char *str);

#endif
