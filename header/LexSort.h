#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class LexSort {
private:
	//std::vector<std::vector<std::string>> vec;
public:
	LexSort()=default;
	LexSort(LexSort&) = delete;
	LexSort operator =(LexSort&) = delete;
	LexSort(LexSort&&) = default;
	LexSort& operator =(LexSort&&) = default;

	~LexSort() {};

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

	std::vector<std::vector<int>>&& sort(std::vector<std::vector<int>>&& vec) {

		std::stable_sort(vec.begin(), vec.end(),
			[](std::vector<int> rvl, std::vector<int>lvl) {
				return  rvl > lvl;
			});
		return std::move(vec);
	}
};
