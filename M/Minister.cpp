#include "Minister.h"

Minister::Minister(std::string id, std::string name, int age)
{
	this->id = id;
	this->name = name;
	this->age = age;

	this->loyality = std::make_shared<AbstractLoyality>();
	this->power = std::make_shared<AbstractPower>();
}

void Minister::updateEndTurn()
{
	age++;

	this->loyality->updateEndTurn();
	this->power->updateEndTurn();
}

Minister::~Minister()
{

}