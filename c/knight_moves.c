/*
Author: Phillip Stewart
Date: 20 March 2016
CodeEval Challenge: 180 - Knight Moves
*/

#include <stdio.h>

const char* space = " ";
#define SPACE if(add_space){printf("%s",space);}else{add_space=1;}

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

	char buffer[80];
	char sq[3];
	sq[2] = 0;
	int rank, file, add_space;
	while(fgets(buffer, 80, fp)) {
		add_space = 0;
		file = buffer[0] - 'a' + 1;
		rank = buffer[1] - '0';
		if (file > 2) {
			if (rank > 1) { SPACE
				sq[0] = file + ('a'-1) - 2;
				sq[1] = rank + '0' - 1;
				printf("%s", sq);
			}
			if (rank < 8) { SPACE
				sq[0] = file + ('a'-1) - 2;
				sq[1] = rank + '0' + 1;
				printf("%s", sq);
			}
		}
		if (file > 1) {
			if (rank > 2) { SPACE
				sq[0] = file + ('a'-1) - 1;
				sq[1] = rank + '0' - 2;
				printf("%s", sq);
			}
			if (rank < 7) { SPACE
				sq[0] = file + ('a'-1) - 1;
				sq[1] = rank + '0' + 2;
				printf("%s", sq);
			}
		}
		if (file < 8) {
			if (rank > 2) { SPACE
				sq[0] = file + ('a'-1) + 1;
				sq[1] = rank + '0' - 2;
				printf("%s", sq);
			}
			if (rank < 7) { SPACE
				sq[0] = file + ('a'-1) + 1;
				sq[1] = rank + '0' + 2;
				printf("%s", sq);
			}
		}
		if (file < 7) {
			if (rank > 1) { SPACE
				sq[0] = file + ('a'-1) + 2;
				sq[1] = rank + '0' - 1;
				printf("%s", sq);
			}
			if (rank < 8) { SPACE
				sq[0] = file + ('a'-1) + 2;
				sq[1] = rank + '0' + 1;
				printf("%s", sq);
			}
		}
		printf("\n");
	}//end of while(fgets...){}
	
	fclose(fp);
	return 0;
}
