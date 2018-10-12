#pragma once
#include <string>

class Player
{
private:
	std::string name;

public:
	Player() { name = ""; }
	~Player(){}

	void setName(std::string val) { this->name = val; }
	std::string getName() { return this->name; }
};