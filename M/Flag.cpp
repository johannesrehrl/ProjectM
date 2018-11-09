#include "Flag.h"

Flag::Flag(std::string id, bool active)
{
	this->id = id;
	this->active = active;
	this->dateChance = 0;
	this->dateDependent = false;
}

Flag::~Flag()
{

}