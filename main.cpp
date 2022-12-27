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
	std::ifstream out(argv[1]);
	if (!out) {
		std::cout << "File is not open!" << std::endl;
		return 1;
	}
	std::vector<std::vector<std::string>> ip_pool;
	try {
		FilePars Parser(out);
		Parser.pars(ip_pool);
		out.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

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