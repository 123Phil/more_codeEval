/*
Author: Phillip Stewart
Date: 20 March 2016
CodeEval Challenge: 173 - Without repitition
*/

#include <stdio.h>


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

	char buffer[2048];
	char b2[2048];
	char prev;
	while(fgets(buffer, 2048, fp)) {
		prev = b2[0] = buffer[0];
		int j=1;
		for (int i=1; i<2048 && buffer[i]; i++) {
			if (prev != buffer[i]) {
				b2[j] = buffer[i];
				prev = buffer[i];
				j++;
			}
		}
		b2[j] = 0;
		printf("%s", b2);
	}//end of while(fgets...){}
	
	fclose(fp);
	return 0;
}
