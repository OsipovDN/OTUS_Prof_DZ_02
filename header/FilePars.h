#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

using TabStr = std::vector < std::vector < std::string >>;

class FilePars {
private:
	std::unique_ptr<std::ifstream >in_;
	TabStr ip_tabl;

	std::vector<std::string> split(const std::string& str, char d);
	void pars();

public:
	explicit FilePars(const char* in);
	FilePars(FilePars&) = delete;
	FilePars operator =(FilePars&) = delete;
	FilePars(FilePars&&) = default;
	FilePars& operator =(FilePars&&) = default;

	auto& getTab()const noexcept { return this->ip_tabl; }

	~FilePars() { in_->close(); }

};

