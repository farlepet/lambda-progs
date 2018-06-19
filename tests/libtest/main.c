#include <lambda/sys/ktasks/kvid.h>
#include <lambda/sys/syscalls.h>

#include <unistd.h>
#include <stdio.h>

int main() {
	printf("\nSTDOUT printf test!\n");

	printf("Reading 8 characters from STDIN:\n");

	int i = 0;
	while(i < 8) {
        int c;
        if((c = getchar()) != EOF) {

		//if(read(0, &c, 1) > 0) {
			printf("Received character: %c\n", c);
			/*write(1, "Recv ch: ", 9);
			write(1, &c, 1);
			write(1, "\n", 1);*/
			i++;
		}
	}

	return 0;
}
