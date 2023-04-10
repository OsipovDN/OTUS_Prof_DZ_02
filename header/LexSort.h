#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <execution>

class LexSort {
private:
	using TabInt = std::vector < std::vector < int >>;
	std::unique_ptr<TabInt> ip_tab_trans;
public:
	LexSort(TabInt obj) :
		ip_tab_trans(std::make_unique<TabInt>(obj)) {};

	LexSort(LexSort&) = delete;
	LexSort operator =(LexSort&) = delete;
	LexSort(LexSort&&) = default;
	LexSort& operator =(LexSort&&) = default;

	~LexSort() {};

	void sortForw() {
		std::sort(ip_tab_trans->begin(), ip_tab_trans->end());
	};

	void sortRev() {
		std::sort(ip_tab_trans->rbegin(), ip_tab_trans->rend());
	};

	TabInt sortOf(std::pair <int, int>& b1, std::pair <int, int>& b2) {
		bool flag_sort;
		TabInt res_vec;
		flag_sort = std::is_sorted(std::execution::par, ip_tab_trans->cbegin(), ip_tab_trans->cend());
		if (!flag_sort)
			sortForw();
		auto start_it = std::find_if(ip_tab_trans->cbegin(), ip_tab_trans->cend(), [&](std::vector <int> ip) {
			return (ip[b1.first - 1] == b1.second && ip[b2.first - 1] == b2.second);
			});
		auto end = std::count_if(start_it, ip_tab_trans->cend(), [&](std::vector <int> ip) {
			return (ip[b1.first - 1] == b1.second && ip[b2.first - 1] == b2.second);
			});
		std::for_each(start_it, start_it + end, [&](const std::vector<int>& obj) {
			return res_vec.push_back(obj);
			});
		return res_vec;

	};

	std::vector<std::vector<int>>& getTab() {
		return *this->ip_tab_trans;
	};

};
