/*
Author: Phillip Stewart
Date: 18 March 2016
CodeEval Challenge: 192 - Compare Points
https://www.codeeval.com/open_challenges/192/
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
	int O, P, Q, R;
	while(getline(fp, line)) {
		//read #s from line
		std::istringstream ss(line);
		ss >> O >> P >> Q >> R;

		if (P == R && O == Q) {
				std::cout << "here";
		} else {
			// Check North-South first
			if (P > R) {
				std::cout << "S";
			} else if (P < R) {
				std::cout << "N";
			}
			// Check East-West
			if (O > Q) {
				std::cout << "W";
			} else if (O < Q) {
				std::cout << "E";
			}
		}
		
		std::cout << std::endl;
	}
	
	fp.close();
	return 0;
}
