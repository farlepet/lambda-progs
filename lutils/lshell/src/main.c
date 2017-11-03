#include <lambda/sys/ktasks/kvid.h>
#include <lambda/sys/syscalls.h>

int main() {
	sys_kvid_init();

    sys_kvid_print("\nlshell built "__DATE__"\n");
    
    for(;;);

    return 0;
}