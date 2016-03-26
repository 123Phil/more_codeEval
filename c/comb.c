/*
Author: Phillip Stewart
Date: 24 March 2016
CodeEval Challenge: 233 - Comb sort
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
		int i=0, num, nums_len=0;
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
			} else if (buffer[i] == '\n' || buffer[i] == 0) {
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

		//this is the comb sort.
		int t, sorted, iters=0;
		int comb = 4*(nums_len) / 5;
		for (i=0; i<nums_len+1; i++) {
			//check sorted...
			sorted = 1;
			for (int j=0; j<nums_len-1; j++) {
				if (nums[j] > nums[j+1]) {
					sorted = 0;
					break;
				}
			}
			if (sorted) {
				break;
			}
			//here is one iter:
			for (int j=0; j+comb<nums_len; j++) {
				if (nums[j] > nums[j+comb]) {
					t = nums[j];
					nums[j] = nums[j+comb];
					nums[j+comb] = t;
				}
			}
			comb = (comb*4) / 5;
			iters++;
		}

		printf("%d\n", iters);
	}//end of while(fgets...){}
	
	fclose(fp);
	return 0;
}


