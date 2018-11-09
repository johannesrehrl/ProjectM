#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Flag
{
private:
	std::string id;
	bool active;

public:
	Flag(std::string id, bool active);
	~Flag();

	std::string getId() { return this->id; }
	std::string setId(std::string val) { this->id = val; }
	bool isActive() { return this->active; }
	void setActive(bool val) { this->active = val; }
};
