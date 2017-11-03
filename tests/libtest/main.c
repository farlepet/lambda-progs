#include <lambda/sys/ktasks/kvid.h>
#include <lambda/sys/syscalls.h>

int main() {
	sys_kvid_init();

	sys_kvid_print("\nKVID test\n");

	sys_kvid_print("Attempting to print a pointer to a non-existant page:\n");

	sys_kvid_print((void *)0xFFFFFFFF);

	for(;;);

	return 0;
}
