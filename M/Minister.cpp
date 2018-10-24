#include "Minister.h"

Minister::Minister(std::string id, std::string name, int age)
{
	this->id = id;
	this->name = name;
	this->age = age;
	this->power = 0;
	this->loyality = 0;
}

void Minister::updateEndTurn()
{
	age++;

	this->power = 0;

	for (int i = 0; i < this->powerModifiers.size(); i++)
	{
		if (this->powerModifiers.at(i)->isFinite())
		{
			this->powerModifiers.at(i)->setDuration(this->powerModifiers.at(i)->getDuration() - 1);

			if (this->powerModifiers.at(i)->getDuration() >= 0)
			{
				this->powerModifiers.erase(powerModifiers.begin() + i);
			}
		}

		this->power += this->powerModifiers.at(i)->getValue();
	}

	this->loyality = 0;

	for (int i = 0; i < this->loyalityModifiers.size(); i++)
	{
		if (this->loyalityModifiers.at(i)->isFinite())
		{
			this->loyalityModifiers.at(i)->setDuration(this->loyalityModifiers.at(i)->getDuration() - 1);

			if (this->loyalityModifiers.at(i)->getDuration() >= 0)
			{
				this->loyalityModifiers.erase(loyalityModifiers.begin() + i);
			}
		}

		this->loyality += this->loyalityModifiers.at(i)->getValue();
	}
}

void Minister::subLoyalityModifier(std::string id)
{
	for (int i = 0; i < this->loyalityModifiers.size(); i++)
	{
		if (this->loyalityModifiers.at(i)->getId() == id)
		{
			this->loyalityModifiers.erase(loyalityModifiers.begin() + i);
		}
	}

	this->recalcLoyality();
}

void Minister::subPowerModifier(std::string id)
{
	for (int i = 0; i < this->powerModifiers.size(); i++)
	{
		if (this->powerModifiers.at(i)->getId() == id)
		{
			this->powerModifiers.erase(powerModifiers.begin() + i);
		}
	}
	
	this->recalcPower();
}

void Minister::recalcLoyality()
{
	this->loyality = 0;

	for (int i = 0; i < this->loyalityModifiers.size(); i++)
	{
		this->power += this->loyalityModifiers.at(i)->getValue();
	}
}

void Minister::recalcPower()
{
	this->power = 0;

	for (int i = 0; i < this->powerModifiers.size(); i++)
	{
		this->power += this->powerModifiers.at(i)->getValue();
	}
}

Minister::~Minister()
{

}