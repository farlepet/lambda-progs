#include <unistd.h>

size_t strlen(const char *str)
{
	register size_t i = 0;
	while(str[i]) i++;
	return i;
}