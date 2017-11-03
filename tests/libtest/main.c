#include <lambda/sys/ktasks/kvid.h>
#include <lambda/sys/syscalls.h>

#include <unistd.h>

int main() {
	sys_kvid_init();

	sys_kvid_print("\nKVID test\n");

	sys_kvid_print("Attempting to print a pointer to a non-existant page:\n");

	sys_kvid_print((void *)0xFFFFFFFF);

	write(1, "Test string using STDOUT!\n", 27);

	write(2, "Test string using STDERR!\n", 27);

	for(;;);

	return 0;
}
