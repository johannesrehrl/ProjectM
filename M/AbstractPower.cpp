#include "AbstractPower.h"

AbstractPower::AbstractPower()
{
	this->power = 0;
}

void AbstractPower::updateEndTurn()
{
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

	if (this->power < 0)
	{
		this->power = 0;
	}

	else if (this->power > 100)
	{
		this->power = 100;
	}
}

void AbstractPower::subPowerModifier(std::string id)
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

void AbstractPower::recalcPower()
{
	this->power = 0;

	for (int i = 0; i < this->powerModifiers.size(); i++)
	{
		this->power += this->powerModifiers.at(i)->getValue();
	}

	if (this->power < 0)
	{
		this->power = 0;
	}

	else if (this->power > 100)
	{
		this->power = 100;
	}
}

AbstractPower::~AbstractPower()
{

}