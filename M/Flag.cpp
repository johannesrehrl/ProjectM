#include "Flag.h"

Flag::Flag(std::string id, bool active)
{
	this->id = id;
	this->active = active;
	this->dateChance = 0;
	this->dateDependent = false;

	this->flagDependencies = std::make_shared<std::vector<std::string>>();
	this->dateDependencies = std::make_shared<sf::Vector2i>();
}

Flag::~Flag()
{

}