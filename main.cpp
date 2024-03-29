#include <iostream>
#include <fstream>
#include "version.h"
#include "FilePars.h"
#include "LexSort.h"
#include <stdexcept>
#include <algorithm>


using TabInt = std::vector < std::vector < int >>;
using Byte = std::pair<int, int>;

template <typename X>
void printTab(const X& tab) {
	static int i = 0;
	for (auto it : tab) {
		i = 0;
		for (auto it1 : it) {
			std::cout << it1;
			i++;
			if (i!=4)
				std::cout << ".";
		}
		std::cout << std::endl;
	}
};

int main(int argc, char const* argv[]) {
	if (argc != 2) {
		std::cout << "The \"file name\" parameter is not entered" << std::endl;
		return 1;
	}
	TabInt ip_pool_trans;

	try {
		FilePars pars_vec(argv[1]);
		ip_pool_trans = pars_vec.getTab();

	}
	catch (const std::exception& e) {
		std::cout << "File is not open!" << std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}

	//transformTab(ip_pool_pars, ip_pool_trans);
	LexSort ipInt(std::move(ip_pool_trans));

	//Direct sorting:
	ipInt.sortForw();
	ip_pool_trans = ipInt.getTab();
	printTab(ip_pool_trans);

	//Reverse sorting:
	ipInt.sortRev();
	ip_pool_trans = ipInt.getTab();
	printTab(ip_pool_trans);

	//Sorting by first byte
	Byte f_byte = { 1,1 };
	ip_pool_trans = ipInt.sortOf(f_byte);
	printTab(ip_pool_trans);

	//Sorting by first and second byte
	Byte first_byte = { 1,46 };
	Byte second_byte = { 2,70 };
	ip_pool_trans = ipInt.sortOf(first_byte, second_byte);
	printTab(ip_pool_trans);

	//Sorting by any byte
	Byte any_byte = { 0,46 };
	ip_pool_trans = ipInt.sortOf(any_byte);
	printTab(ip_pool_trans);

	return 0;
}