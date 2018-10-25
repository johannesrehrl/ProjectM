#include "AbstractLoyality.h"

AbstractLoyality::AbstractLoyality()
{
	this->loyality = 0;
}

void AbstractLoyality::updateEndTurn()
{
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

	if (this->loyality < 0)
	{
		this->loyality = 0;
	}

	else if (this->loyality > 100)
	{
		this->loyality = 100;
	}
}

void AbstractLoyality::subLoyalityModifier(std::string id)
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

void AbstractLoyality::recalcLoyality()
{
	this->loyality = 0;

	for (int i = 0; i < this->loyalityModifiers.size(); i++)
	{
		this->loyality += this->loyalityModifiers.at(i)->getValue();
	}

	if (this->loyality < 0)
	{
		this->loyality = 0;
	}

	else if (this->loyality > 100)
	{
		this->loyality = 100;
	}
}

AbstractLoyality::~AbstractLoyality()
{

}