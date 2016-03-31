/*
Author: Phillip Stewart
Date: 20 March 2016
CodeEval Challenge:
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

	char buffer[200];
	while(fgets(buffer, 200, fp)) {

		//logic


	}//end of while(fgets...){}
	
	fclose(fp);
	return 0;
}
