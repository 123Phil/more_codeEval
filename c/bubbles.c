/*
Author: Phillip Stewart
Date: 24 March 2016
CodeEval Challenge: 158 - Interrupted Bubble Sort
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
	while(fgets(buffer, 2048, fp)) {
		int nums[1000];
		int i=0, num, iters, nums_len=0;
		int line_ended = 0;
		//read numbers into nums and iters
		while (i < 2048) {
			if (buffer[i] >= '0' && buffer[i] <= '9') {
				//read full # into nums[nums_len]
				num = buffer[i] - '0';
				i++;
				while (buffer[i] >= '0' && buffer[i] <= '9') {
					num *= 10;
					num += buffer[i] - '0';
					i++;
				}
				nums[nums_len] = num;
				nums_len++;
				if (nums_len > 1000) {
					printf("%s\n", "Too many numbers!!!");
					return 0;
				}
			} else if (buffer[i] == ' ') {
				i++;
				continue;
			} else if (buffer[i] == '|') {
				i++;i++;
				num = buffer[i] - '0';
				i++;
				while (buffer[i] >= '0' && buffer[i] <= '9') {
					num *= 10;
					num += buffer[i] - '0';
					i++;
				}
				iters = num;
				line_ended = 1;
				break;
			} else {
				printf("%s\n", "Too many numbers!!!");
				return 1;
			}
			i++;
		}

		if (line_ended == 0) {
			printf("%s\n", "Buffer too small!!!");
			return 2;
		}

		//t is temp variable, nums_len reduced since bubble compares j+1
		int t;
		nums_len--;
		for (i=0; i<num; i++) {
			for (int j=0; j<nums_len; j++) {
				if (nums[j] > nums[j+1]) {
					t = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = t;
				}
			}
		}

		//bring nums_len back up
		nums_len++;
		printf("%d", nums[0]);
		for (i=1; i<nums_len; i++) {
			printf(" %d", nums[i]);
		}
		printf("%s", "\n");
	}//end of while(fgets...){}
	
	fclose(fp);
	return 0;
}


