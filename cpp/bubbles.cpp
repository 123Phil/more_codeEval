/*
Author: Phillip Stewart
Date: 24 March 2016
CodeEval Challenge: 158 - Interrupted Bubble Sort
*/

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>


int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Usage:\n\t" << argv[0] << " <input file>\n";
		return 0;
	}
	
	std::ifstream fp(argv[1]);
	std::string num_string, iter_string;
	while(std::getline(fp, num_string, '|')) {
		std::getline(fp, iter_string);
		std::istringstream ss1(num_string);
		std::istringstream ss2(iter_string);
		int nums[2048];
		int i=0, num, num_len;
		while (ss1 >> num) {
			nums[i] = num;
			i++;
		}
		num_len = i;
		ss2 >> num;
		int t;
		for (i=0; i<num; i++) {
			for (int j=0; j<num_len-1; j++) {
				if (nums[j] > nums[j+1]) {
					t = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = t;
				}
			}
		}
		std::cout << nums[0];
		for (i=1; i<num_len; i++) {
			std::cout << " " << nums[i];
		}
		std::cout << std::endl;
	}
	fp.close();
	return 0;
}
