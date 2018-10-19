#include "Minister.h"

Minister::Minister(std::string id, std::string name, int age)
{
	this->id = id;
	this->name = name;
	this->age = age;
}

void Minister::updateEndTurn()
{
	age++;
}

Minister::~Minister()
{

}