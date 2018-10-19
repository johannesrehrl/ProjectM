#pragma once
#include <string>

class President
{
private:
	std::string name;

public:
	President() { name = ""; }
	~President() {}

	void setName(std::string val) { this->name = val; }
	std::string getName() { return this->name; }
};