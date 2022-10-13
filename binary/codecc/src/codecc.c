#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/personality.h>

void decode();
void encode();
void print_menu();
int get_int();
void setup();

int main(void) {
	setup();
	while(true) {
		print_menu();
		printf("> ");

		int choice = get_int();
		int len;
		char * data;

		switch(choice) {
			case 1:
				printf("Please enter data length: ");
				len = get_int();
				printf("Please enter data: ");
				data = malloc(len);
				read(0, data, len);

				encode(data, len);

				free(data);
				break;
			case 2:
				printf("Please enter data length: ");
				len = get_int();
				printf("Please enter data: ");

				data = malloc(len);
				read(0, data, len);

				decode(data, len);

				free(data);
				break;
			case 3:
				exit(0);
			default:
				break;
		}

	}
}

int get_int() {
	char buf[8];
	fgets(buf, 8, stdin);

	return atoi(buf);
}

void print_menu() {
	puts("1: Encode");
	puts("2: Decode");
	puts("3: Exit");

}

void setup() {
	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stdout, 0, _IONBF, 0);
	personality(ADDR_NO_RANDOMIZE);
}

void decode(char * input, int len) {
	int dec_len = 0x10 * len;

	unsigned char decoded[dec_len];
	int dec_idx = 0;
	
	for(int in_idx = 0 ; in_idx < len;) {
		char control = input[in_idx++];

		switch(control) {
			case 0 ... 127:
				for (int j = 0 ; j <= control ; j++) {
					decoded[dec_idx++] = input[in_idx++];
				}
				break;

			case -127 ... -1:
				;
				int repeat = 1-control;
				char byte = input[in_idx++];

				for (int j = 0 ; j < repeat ; j++) {
					decoded[dec_idx++] =  byte;
				}
				break;

			case -128:
				break;
		}
		
	}

	for (int i = 0 ; i < dec_idx - 1 ; i++) {
		printf("%02x", decoded[i]);
	}
	printf("\n");
}

void encode(char * input, int len)  {
	int enc_len = len;	

	unsigned char encoded[enc_len];

	int run = 0;
	int in_idx = 0;
	int old_idx = in_idx;
	int enc_idx = 0;
	
	for(; (in_idx + run + 1) < len ; ) {
		if (input[in_idx + run] == input[in_idx + run+1] && run < 127) {
			run++;
		}
		else {
			if ( run > 0) {
				if ((in_idx - old_idx) > 0) {
					encoded[enc_idx++] = (in_idx - old_idx - 1);
					for(;old_idx < in_idx; old_idx++) {
						encoded[enc_idx++] = input[old_idx];
					}
				}

				encoded[enc_idx++] = -run;

				encoded[enc_idx++] = input[in_idx];

				in_idx += run + 1;
				old_idx = in_idx;
			}
			else {
				in_idx = in_idx + 1;
				if ((in_idx - old_idx) == 128) {
					encoded[enc_idx++] = 0x7f;
					
					for(;old_idx < in_idx; old_idx++) {
						encoded[enc_idx++] = input[old_idx];
					}
				}
			}

			run = 0;
		}
	}

	// for remaining non-run bytes 
	if (in_idx - old_idx ) {
		encoded[enc_idx++] = (in_idx - old_idx - 1);
			
		for(;old_idx < in_idx; old_idx++) {
			encoded[enc_idx++] = input[old_idx];
		}
	}

	for (int i = 0 ; i < enc_len ; i++) {
		printf("%02x", encoded[i]);
	}

	printf("\n");
}
