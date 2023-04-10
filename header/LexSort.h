#pragma once
#include <memory>
#include <vector>

using TabInt = std::vector < std::vector < int >>;
using Byte = std::pair<int, int>;

class LexSort {
private:
	std::unique_ptr<TabInt> ip_tab_trans;
	
public:
	
	LexSort(TabInt obj) :
		ip_tab_trans(std::make_unique<TabInt>(obj)) {};

	LexSort(LexSort&) = delete;
	LexSort operator =(LexSort&) = delete;
	LexSort(LexSort&&) = default;
	LexSort& operator =(LexSort&&) = default;

	~LexSort() {};

	void sortForw();
	void sortRev();
	TabInt sortOf(Byte& b1, Byte& b2);
	TabInt sortOf(Byte& b);
	std::vector<std::vector<int>>& getTab();

};
