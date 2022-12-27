#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "FilePars.h"
#include "LexSort.h"

int main(int argc, char const* argv[]) {
	if (argc != 2) {
		std::cout << "The \"file name\" parameter is not entered" << std::endl;
		return 1;
	}
	FilePars Parser(argv[1]);

	std::vector<std::vector<std::string>> ip_pool;
	Parser.pars(ip_pool);
	LexSort Lex(ip_pool);
	ip_pool = Lex.sort();
	for (auto it : ip_pool) {
		for (auto it1 : it) {
			std::cout << it1 << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}