#include <iostream>
#include <vector>
#include <fstream>
#include "FilePars.h"
#include "LexSort.h"
#include <stdexcept>

using TabStr=std::vector < std::vector < std::string >> ;
using TabInt = std::vector < std::vector < int >>;

template <typename X>
void printTab(const X& tab) {
	for (auto it : tab) {
		for (auto it1 : it) {
			std::cout << it1 << " ";
		}
		std::cout << std::endl;
	}
};

void transformTab(TabStr& ip_tab_str, TabInt& ip_tab_int) {
	for (const auto& it_tab:ip_tab_str) {
		std::vector<int> temp;
		std::for_each(it_tab.cbegin(), it_tab.cend(), [&](
			const std::string& str) {
				temp.push_back(std::stoi(str));
			});
		ip_tab_int.push_back(temp);
	}
};

int main(int argc, char const* argv[]) {
	if (argc != 2) {
		std::cout << "The \"file name\" parameter is not entered" << std::endl;
		return 1;
	}
	TabStr ip_pool_pars;
	TabInt ip_pool_trans;

	try {
		FilePars pars_vec(argv[1]);
		ip_pool_pars = pars_vec.getTab();	

	}
	catch (const std::exception& e) {
		std::cout << "File is not open!" << std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}

	transformTab(ip_pool_pars, ip_pool_trans);
	LexSort ipInt(std::move(ip_pool_trans));

	//Сортировка от меньшего к большему
	//std::cout << "Direct sorting:" << std::endl;
	ipInt.sortForw();
	ip_pool_trans = ipInt.getTab();
	printTab(ip_pool_trans);

	//Сортировка всего файла от большего к меньшему
	//std::cout << "Reverse sorting:" << std::endl;
	ipInt.sortRev();
	ip_pool_trans = ipInt.getTab();
	printTab(ip_pool_trans);

	//Сортировка по первому и второму байтам
	std::pair<int, int> first_byte = { 1,46 };
	std::pair<int, int> second_byte = { 2,70 };
	ip_pool_trans=ipInt.sortOf(first_byte, second_byte);
	printTab(ip_pool_trans);

	//Сортировка по первому и второму байтам
	std::pair<int, int> any_byte = { 0,46 };
	ip_pool_trans = ipInt.sortOf(any_byte);
	printTab(ip_pool_trans);


		

	
	return 0;
}