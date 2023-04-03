#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class LexSort {
private:
	std::unique_ptr<std::vector<std::vector<int>>> ip_tab_trans;

public:
	LexSort(std::vector<std::vector<int>> obj):
		ip_tab_trans(std::make_unique<std::vector<std::vector<int>>>(obj)){};

	LexSort(LexSort&) = delete;
	LexSort operator =(LexSort&) = delete;
	LexSort(LexSort&&) = default;
	LexSort& operator =(LexSort&&) = default;

	~LexSort() {};

	void sortForw() {
		std::stable_sort(ip_tab_trans->begin(), ip_tab_trans->end(),
			[](std::vector<int> rvl, std::vector<int>lvl) {
				return  rvl < lvl;
			});
	}

	void sortRev() {
		std::stable_sort(ip_tab_trans->begin(), ip_tab_trans->end(),
			[](std::vector<int> rvl, std::vector<int>lvl) {
				return  rvl > lvl;
			});
	}
	std::vector<std::vector<int>>& getTab() {
		return *this->ip_tab_trans;
	};

	



	/*std::vector<std::vector<std::string>> sort() {

	std::stable_sort(vec.begin(), vec.end(),
		[](std::vector<std::string> rvl, std::vector<std::string>lvl) {
			if (std::stoi(rvl[0]) == std::stoi(lvl[0])) {
				if (std::stoi(rvl[1]) == std::stoi(lvl[1])) {
					if (std::stoi(rvl[2]) == std::stoi(lvl[2])) {
						return std::stoi(rvl[3]) > std::stoi(lvl[3]);
					}
					return std::stoi(rvl[2]) > std::stoi(lvl[2]);
				}
				return std::stoi(rvl[1]) > std::stoi(lvl[1]);
			}
			return std::stoi(rvl[0]) > std::stoi(lvl[0]);
		});
	return vec;
}*/
};
