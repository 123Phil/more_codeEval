/*
Author: Phillip Stewart
Date: 18 March 2016
CodeEval Challenge: 156 - Roller Coaster
*/

#include <stdio.h>
#include <ctype.h>


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

	char buffer[1000];
	int upper = 1;
	int i;
	while(fgets(buffer, 1000, fp)){
		i = 0;
		upper = 1;
		while (buffer[i]) {
			if (isalpha(buffer[i])) {
				if (upper) {
					buffer[i] = toupper(buffer[i]);
					upper = 0;
				} else {
					buffer[i] = tolower(buffer[i]);
					upper = 1;
				}
			}
			i++;
		}
		printf("%s", buffer);
	}//end of while(fgets...){}
	
	fclose(fp);
	printf("\n");
	return 0;
}
