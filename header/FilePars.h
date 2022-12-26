#pragma once


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

std::vector<std::string> FilePars::split(const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}
void FilePars::pars(std::vector<std::vector<std::string>>& ip) {
    for (std::string line; std::getline(in_, line);)
    {
        //line ="113.162.145.156\t111\t0"
        std::vector<std::string> v = split(line, '\t');
        //v={"113.162.145.156","111","0"}
        ip.push_back(split(v.at(0), '.'));
    }
}