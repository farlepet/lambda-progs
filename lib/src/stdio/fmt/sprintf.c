#include "helpers.h"

int sprintf(char *out, const char *format, ...)
{
	__builtin_va_list varg;
    __builtin_va_start(varg, format);
    
    int ret = print(out, format, varg);
    
	__builtin_va_end(varg);
	return ret;
}