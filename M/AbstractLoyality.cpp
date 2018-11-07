#include "AbstractLoyality.h"

AbstractLoyality::AbstractLoyality(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->loyality = 0;

	this->myTooltip = std::make_shared<Tooltip>(this->window, this->assetsHandler);
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

	this->makeTooltip();
}

void AbstractLoyality::makeTooltip()
{
	this->myTooltip->setHeadLine("Loyality Modifiers");

	this->myTooltip->clearAllLines();

	for (int i = 0; i < this->loyalityModifiers.size(); i++)
	{
		if (this->loyalityModifiers.at(i)->getValue() < 0)
		{
			this->myTooltip->addLine(std::to_string((int)this->loyalityModifiers.at(i)->getValue()) + " " +
				this->loyalityModifiers.at(i)->getShortText());
		}

		else
		{
			this->myTooltip->addLine("+" + std::to_string((int)this->loyalityModifiers.at(i)->getValue()) + " " +
				this->loyalityModifiers.at(i)->getShortText());
		}

		if (this->loyalityModifiers.at(i)->isFinite())
		{
			this->myTooltip->addLine("Duration: " + std::to_string((int)this->loyalityModifiers.at(i)->getDuration()) + " months.");
		}
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