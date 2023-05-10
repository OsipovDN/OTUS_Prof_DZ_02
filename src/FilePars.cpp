#include "FilePars.h"
#include <algorithm>

FilePars::FilePars(const char* in) :in_(std::make_unique<std::ifstream>(in)) {
	if (!in_->is_open()) {
		throw std::runtime_error("file not found!");
	}
	pars();

}

std::vector<std::string> FilePars::split(const std::string& str, char d) {
	//std::vector<std::string> r;
	std::vector<std::string> r;
	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);

	while (stop != std::string::npos) {
		r.push_back(str.substr(start, stop - start));
		start = stop + 1;
		stop = str.find_first_of(d, start);
	}
	r.push_back(str.substr(start));
	return r;
}

void FilePars::pars() {

	for (std::string line; std::getline(*in_, line);) {
		//line ="113.162.145.156\t111\t0"
		std::vector<std::string> v = split(line, '\t');
		//v={"113.162.145.156","111","0"}
		v = (split(v.at(0), '.'));
		//v={"113","162","145","156"}
		std::vector<int> v1;
		for (auto it : v)
			v1.push_back (std::stoi(it));
		ip_tabl.push_back(v1);
	};
}


