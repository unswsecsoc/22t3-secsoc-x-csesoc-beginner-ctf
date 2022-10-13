#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/syscall.h>


void setup() {
	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stdout, 0, _IONBF, 0);
}

void victory() {
	//system("/bin/sh");
	syscall(SYS_execve, "/bin/sh", 0, 0);
}

int main(void) {
	setup();

	char user_data[0x40];
	do {
		gets(user_data);
		printf("%s\n", user_data);
	} while (strlen(user_data) != 0);
}
