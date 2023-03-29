#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "FilePars.h"
#include "LexSort.h"
#include <stdexcept>

int main(int argc, char const* argv[]) {
	if (argc != 2) {
		std::cout << "The \"file name\" parameter is not entered" << std::endl;
		return 1;
	}

	std::vector<std::vector<int>> ip_pool;

	try {
		FilePars obj(argv[1]);
		ip_pool = obj.getTabTransform();
	}
	catch (const std::exception& e) {
		std::cout << "File is not open!" << std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	ip_pool = LexSort().sort(std::move(ip_pool));
	for (auto it : ip_pool) {
		for (auto it1 : it) {
			std::cout << it1 << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}