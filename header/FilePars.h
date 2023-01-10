#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class FilePars {
private:
	std::ifstream in_;
	std::vector<std::vector<std::string>> ip_tabl;

	std::vector<std::string> split(const std::string& str, char d);
	void pars();
	//void pars(std::vector<std::vector<std::string>>& ip);

public:
	explicit FilePars(const char* in);
	FilePars(FilePars&) = delete;
	FilePars operator =(FilePars&) = delete;
	FilePars(FilePars&&) = default;
	FilePars& operator =(FilePars&&) = default;

	decltype(auto) get()noexcept {
		return std::move(ip_tabl);
	}
	~FilePars() {
		in_.close();
	}
	/*explicit FilePars(std::ifstream* in) :in_(in) {}
	~FilePars() {}*/
	
};

