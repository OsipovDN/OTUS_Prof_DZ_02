#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class LexSort {
private:
	std::vector<std::vector<std::string>> vec;
public:
	explicit LexSort(std::vector<std::vector<std::string>> in) :vec(in) {};
	~LexSort() {};
};
