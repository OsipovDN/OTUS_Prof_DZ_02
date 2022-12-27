#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class FilePars {
private:
	std::unique_ptr <std::ifstream> in_;
	//std::ifstream& in_;
	//std::vector<std::vector<std::string>> ip_tabl;

public:
	explicit FilePars(const char* in) {
		try {
			in_ = std::unique_ptr<std::ifstream>(new std::ifstream(in));
		}
		catch (const std::ifstream::failure& e) {
			std::cout << "File is not open!" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	~FilePars() {}

	/*explicit FilePars(std::ifstream* in) :in_(in) {}
	~FilePars() {}*/
	std::vector<std::string> split(const std::string& str, char d);
	void pars(std::vector<std::vector<std::string>>& ip);
};

