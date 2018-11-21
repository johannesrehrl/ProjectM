#include "Minister.h"

Minister::Minister(std::string id, std::string name, int age, bool available, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->id = id;
	this->name = name;
	this->age = age;
	this->available = available;

	this->loyality = std::make_shared<AbstractLoyality>(this->window, this->assetsHandler);
	this->power = std::make_shared<AbstractPower>(this->window, this->assetsHandler);
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