#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 100
#define REAL_FLAG "BEGINNER{REDACTED}"

#define MAX(a, b) a > b ? a : b

char deobfuscate(char x, int i) {
    // this function has been redacted
    return x;
}

int check_flag(char *flag) {
    for (int i = 0; i < (MAX(strlen(flag), strlen(REAL_FLAG))); i++) {
        if (flag[i] != deobfuscate(REAL_FLAG[i], i)) return 0;
        usleep(10000);
    }

    return 1;
}

int main(int argc, char **argv) {
    char *buf = malloc(MAX_INPUT);

    printf("Welcome to the flag checker!\n");
    printf("Valid flags can consist of lowercase letters, numbers, -, and _ (as well as the flag wrapper of course!)\n");
    printf("Enter a flag: ");
    fflush(stdout);

    while (fgets(buf, MAX_INPUT, stdin) != NULL) {
        if (check_flag(strtok(buf, "\n"))) {
            puts("Correct! Now go enter that on the challenge website!");
            break;
        } else {
            puts("Incorrect flag :(");
        }

        printf("Enter a flag: ");
        fflush(stdout);
    }

    return EXIT_SUCCESS;
}
