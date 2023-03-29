#include <iostream>
#include <vector>
#include <fstream>
#include "FilePars.h"
#include "LexSort.h"
#include <stdexcept>

template <typename X>
void printTab(const X& tab) {
	for (auto it : tab) {
		for (auto it1 : it) {
			std::cout << it1 << " ";
		}
		std::cout << std::endl;
	}
};


int main(int argc, char const* argv[]) {
	if (argc != 2) {
		std::cout << "The \"file name\" parameter is not entered" << std::endl;
		return 1;
	}
	std::vector<std::vector<std::string>> ip_pool_pars;
	std::vector<std::vector<int>> ip_pool_trans;

	try {
		FilePars pars_vec(argv[1]);
		ip_pool_pars = pars_vec.getTab();
		LexSort ipInt(std::move(ip_pool_pars));
		ipInt.transformTab();

		//Сортировка от меньшего к большему
		std::cout << "Direct sorting:" << std::endl;
		ip_pool_trans = ipInt.sortForw();
		printTab(ip_pool_trans);

		//Сортировка всего файла от большего к меньшему
		std::cout << "Reverse sorting:" << std::endl;
		ip_pool_trans = ipInt.sortRev();
		printTab(ip_pool_trans);
	}
	catch (const std::exception& e) {
		std::cout << "File is not open!" << std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}

	
	return 0;
}