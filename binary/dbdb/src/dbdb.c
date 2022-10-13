#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


#define MAX_KEY_SZ 0x40
#define MAX_DATA_SZ 0x500
#define MAX_DB_ENTRIES 0x10

void setup();
int get_int();
void print_menu();
void welcome();
void allocate();
void delete();
void edit();
void view();
void get_data(char * buf, unsigned int num);


struct db_entry {
	char * key;
	char * data;
};

struct db_entry * database[MAX_DB_ENTRIES];
int database_idx = 0;

int main(void) {
	setup();
	welcome();

	while(true) {
		print_menu();
		printf("> ");

		int user_choice = get_int();
		switch (user_choice) {
			case 1:
				allocate();
				break;
			case 2: 
				delete();
				break;
			case 3:
				edit();
				break;
			case 4:
				view();
				break;
			case 5:
				exit(0);
			default:
				continue;
		}
	}

}

void setup() {
	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stdout, 0, _IONBF, 0);
}

int get_int() {
	char tmp[8];
	get_data(tmp, 8);

	return atoi(tmp);
}

void get_data(char * buf,unsigned  int num) {
	int ret = read(0, buf, num);
}

void print_menu() {
	puts("1: Allocate entry");
	puts("2: Delete entry");
	puts("3: Edit entry");
	puts("4: View entry");
	puts("5: Exit");
}

void welcome() {
	puts("Welcome to DBDB v0.1! - (Dreally Bad DataBase)!");
	puts("Hope we provide a good user experience :)");
}

void allocate() {
	if (database_idx == MAX_DB_ENTRIES) {
		printf("Database is full.\n");
		return;
	}

	struct db_entry * entry = malloc(sizeof(struct db_entry));
	entry->key = malloc(MAX_KEY_SZ);

	printf("Please enter a key: ");	
	get_data(entry->key, MAX_KEY_SZ);

	printf("Please enter data length: ");
	int data_len = get_int();

	if (data_len > MAX_DATA_SZ)
		data_len = MAX_DATA_SZ;

	printf("Please enter data: ");
	entry->data = malloc(data_len);
	get_data(entry->data, data_len);


	database[database_idx] = entry;
	database_idx++;

	return;
}

void delete() {
	char key [40];
	printf("Please enter a key: ");	
	get_data(key, MAX_KEY_SZ);

	for (int i = 0 ; i < database_idx ; i++) {
		if (database[i] == NULL)
			continue;

		if (strcmp(key, database[i]->key) == 0) {
			free(database[i]->key);
			free(database[i]->data);
			free(database[i]);

			database[i] = NULL;

			return;
		}
	}

	printf("Unable to find matching key.\n");
}

void edit() {
	char key [40];
	printf("Please enter a key: ");	
	get_data(key, MAX_KEY_SZ);

	for (int i = 0 ; i < database_idx ; i++) {
		if (database[i] == NULL)
			continue;

		if (strcmp(key, database[i]->key) == 0) {
			printf("Please enter data length: ");
			int data_len = get_int();

			if (data_len > MAX_DATA_SZ)
				data_len = MAX_DATA_SZ;

			printf("Please enter data: ");
			get_data(database[i]->data, data_len);

			return;
		}
	}

	printf("Unable to find matching key.\n");
}

void  view() {
	char key [40];
	printf("Please enter a key: ");	
	fflush(stdout);

	get_data(key, MAX_KEY_SZ);

	for (int i = 0 ; i < database_idx ; i++) {
		if (database[i] == NULL)
			continue;

		if (strcmp(key, database[i]->key) == 0) {
			printf("%s", database[i]->data);
			return;
		}
	}

	printf("Unable to find matching key.\n");
}
