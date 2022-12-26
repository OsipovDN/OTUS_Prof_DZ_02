#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class FilePars {
private:
	std::ifstream& in_;
	//std::vector<std::vector<std::string>> ip_tabl;

public:
	explicit FilePars(std::ifstream& in) :in_(in) {}
	~FilePars() {}
    std::vector<std::string> split(const std::string& str, char d);
    void pars(std::vector<std::vector<std::string>>& ip);
};

