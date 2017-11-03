#ifndef LAMBDA_LIB_UNISTD_H
#define LAMBDA_LIB_UNISTD_H

#include <stddef.h>

size_t read(int desc, void *buff, size_t len);

size_t write(int desc, const void *buff, size_t len);

#endif