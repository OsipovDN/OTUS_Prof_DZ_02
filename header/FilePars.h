#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class FilePars {
private:
	std::unique_ptr <std::ifstream> in_;
	//std::ifstream& in_;
	std::vector<std::vector<std::string>> ip_tabl;

	std::vector<std::string> split(const std::string& str, char d);
	void pars();
	//void pars(std::vector<std::vector<std::string>>& ip);

public:
	explicit FilePars(const char* in);
	decltype(auto) get() {
		return std::move(ip_tabl);
	}
	~FilePars() = default;
	/*explicit FilePars(std::ifstream* in) :in_(in) {}
	~FilePars() {}*/
	
};

