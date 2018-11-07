#include "AbstractPower.h"

AbstractPower::AbstractPower(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->power = 0;

	this->myTooltip = std::make_shared<Tooltip>(this->window, this->assetsHandler);
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

	this->makeTooltip();
}

void AbstractPower::makeTooltip()
{
	this->myTooltip->setHeadLine("Power Modifiers");

	this->myTooltip->clearAllLines();

	for (int i = 0; i < this->powerModifiers.size(); i++)
	{
		if (this->powerModifiers.at(i)->getValue() < 0)
		{
			this->myTooltip->addLine(std::to_string((int)this->powerModifiers.at(i)->getValue()) + " " +
				this->powerModifiers.at(i)->getShortText());
		}

		else
		{
			this->myTooltip->addLine("+" + std::to_string((int)this->powerModifiers.at(i)->getValue()) + " " +
				this->powerModifiers.at(i)->getShortText());
		}

		if (this->powerModifiers.at(i)->isFinite())
		{
			this->myTooltip->addLine("Duration: " + std::to_string((int)this->powerModifiers.at(i)->getDuration()) + " months.");
		}
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