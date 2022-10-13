#include <stdio.h>
#include <stdlib.h>

void setup();
void welcome();
void leaks();
unsigned int get_int();
unsigned long long get_addr();

int main(void) {
	setup();
	welcome();
	leaks();

	for (int i = 0 ; i < 1 ; i++) {
		printf("Please enter desired addr:\n");
		unsigned long long addr = get_addr();

		printf("Please enter desired bit:\n");
		unsigned int bit = get_int();

		unsigned long long res = ((unsigned long long)1 << bit);

		*((unsigned long long *)addr) ^= res;
	}
}

void setup() {
	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stdout, 0, _IONBF, 0);
}

void welcome() {
	puts("One bit can be flipped. What'll you choose?");
}

void leaks() {
	void * heap = malloc(0);
	char stack = 0;

	printf("HEAP:  %p\n", heap);
	printf("STACK: %p\n", &stack);
	printf("LIBC:  %p\n", printf);
	printf("EXE:   %p\n", leaks);

	free(heap);
}

unsigned long long get_addr() {
	char buf[17];
	fgets(buf, 17, stdin);

	return atoll(buf);
}

unsigned int get_int() {
	char buf[9];
	fgets(buf, 9, stdin);

	return atoi(buf);
}
