/*
Author: Phillip Stewart
Date: 
CodeEval Challenge:

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
	std::string line;
	int num = 0;
	while(getline(fp, line)) {
		
		//read # from line
		std::istringstream ss(line);
		while (ss >> num) {
			std::cout << num << std::endl;
		}
	}
	
	fp.close();
	return 0;
}
