/*
Author: Phillip Stewart
Date: 20 March 2016
CodeEval Challenge: 179 - Broken LCD
*/

#include <stdio.h>


void print_bin(char c) {
	char o[2];
	o[1] = 0;
	for (int i = 0; i < 8; i++) {
		if ((c << i) & 0x80) {
			o[0] = '1';
		} else {
			o[0] = '0';
		}
		printf("%s", o);
	}
}


int main(int argc, char* argv[])
{

	if (argc != 2) {
		printf("Usage:\n\t%s <input file>\n", argv[0]);
		return 0;
	}

	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Error opening input file.");
		return 0;
    }

	char buffer[200];
	int i,j;
	while(fgets(buffer, 200, fp)) {
		//Read LCD binary
		int buf_ctr = 0;
		char LCD[12];
		for (i=0; i<12; i++) {
			LCD[i] = 0;
			for (j=0; j<8; j++) {
				if (buffer[buf_ctr] == '1') {
					LCD[i] |= 0x1<<(7-j);
				}
				++buf_ctr;
			}
			++buf_ctr;
		}

		//Read Digits into bit mask
		char digits[12];
		int len = 0;
		for (i=0; i<13; i++) {
			digits[len] = 0;
			char c = buffer[buf_ctr];
			if (c == '\n' || c == 0) {
				break;
			}
			switch(c) {
				case '0': digits[len] = 252; break;
				case '1': digits[len] = 96;  break;
				case '2': digits[len] = 218; break;
				case '3': digits[len] = 242; break;
				case '4': digits[len] = 102; break;
				case '5': digits[len] = 182; break;
				case '6': digits[len] = 190; break;
				case '7': digits[len] = 224; break;
				case '8': digits[len] = 254; break;
				case '9': digits[len] = 246; break;
				case '.': digits[len-1] |= 0x1; break;
			}
			if (c != '.') {
				++len;
			}
			++buf_ctr;
		}

		//Compare, mask digits with LCD...
		int printed_1 = 0;
		for (i=0; i+len<13; i++) {
			for (j=0; j<len; j++) {
				if (!(digits[j] == (digits[j] & LCD[i+j]))) {
					// printf("Mismatch at LCD[%d]:\n", i);
					// print_bin(digits[j]);
					// printf("\n");
					// print_bin(LCD[i+j]);
					// printf("\n");
					break;
				}
			}
			if (j == len) {
				printf("%d\n", 1);
				printed_1 = 1;
				break;
			}
		}
		if (!printed_1) {
			printf("%d\n", 0);
		}
	}//end of while(fgets...){}
	
	fclose(fp);
	return 0;
}
