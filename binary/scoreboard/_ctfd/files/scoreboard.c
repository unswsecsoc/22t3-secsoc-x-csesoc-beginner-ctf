#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 10

struct entry {
	char name[4];
	long points;
	char * message;
};

void setup();
void print_menu();
int get_int();
void display_scoreboard();
void enter_user();
void swap_users(struct entry * a, struct entry  * b);
void view_user();


char * flag;
struct entry scoreboard[MAX_USERS];

int main(void) {
	setup();

	while (true) {
		print_menu();

		printf("> ");
		int user_choice = get_int();
		switch (user_choice) {
			case 1:
				enter_user();
				break;
			case 2:
				display_scoreboard();
				break;
			case 3:
				view_user();
				break;
			case 4:
				exit(0);
				break;
			default:
				break;
		}
	}

}

void print_menu() {
	puts("1: Enter user");
	puts("2: Print scoreboard");
	puts("3: View user");
	puts("4: Exit");
}	

void setup() {
	flag = malloc(0x40);
	FILE * f = fopen("/home/ctf/flag", "r");
	fgets(flag, 0x40, f);
	fclose(f);

	memset(scoreboard, 0, sizeof(scoreboard));

	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stdout, 0, _IONBF, 0);
}

int get_int() {
	char buf[8];
	fgets(buf, 8, stdin);

	return atoi(buf);
}

void enter_user() {
	struct entry new_user;
	printf("Enter name: ");
	fgets(new_user.name, 5, stdin);
	new_user.name[3] = 0;
	for (int i = 0 ; i < 3 ; i++) {
		new_user.name[i] = toupper(new_user.name[i]);
	}
	
	printf("Enter points: ");
	new_user.points = get_int();

	printf("Enter message length: ");
	int len = get_int();

	new_user.message = malloc(len);
	printf("Enter message: ");
	fgets(new_user.message, len, stdin);
	new_user.message[strcspn(new_user.message, "\n")] = 0;

	int rank = MAX_USERS;
	for (int i = MAX_USERS - 1;  i >= 0 ; i--) {
		if (scoreboard[i].points > new_user.points)
			break;
		rank = i;
	}

	for (int i = rank ; i < MAX_USERS ; i++ ) {
		swap_users(&scoreboard[i], &new_user);
	}
}

void swap_users(struct entry * a, struct entry * b) {
	struct entry tmp;
	memcpy(tmp.name, a->name, 4);
	tmp.points = a->points;
	tmp.message = a->message;

	memcpy(a->name, b->name, 4);
	a->points = b->points;
	a->message = b->message;

	
	memcpy(b->name, tmp.name, 4);
	b->points = tmp.points;
	b->message = tmp.message;
}

void view_user() {
	puts("Which position would you like to view?");
	int idx = get_int();
	if (idx >= MAX_USERS)
		return;

	printf("%s:	%d		MSG: %s\n", scoreboard[idx].name, scoreboard[idx].points, scoreboard[idx].message);
}

void display_scoreboard() {
	for (int i = 0 ; i < MAX_USERS ; i++) {
		printf("%s:	%d		MSG: %s\n", scoreboard[i].name, scoreboard[i].points, scoreboard[i].message);
	}
}
