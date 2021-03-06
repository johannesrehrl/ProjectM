#include "CorruptionRate.h"

CorruptionRate::CorruptionRate(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->corruption = 0;
	this->endTurnChange = 0;

	this->myTooltip = std::make_shared<Tooltip>(this->window, this->assetsHandler);
}

void CorruptionRate::updateEndTurn()
{
	this->endTurnChange = 0;

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		this->endTurnChange += this->resourceModifier.at(i)->getValue();

		if (this->resourceModifier.at(i)->isFinite())
		{
			this->resourceModifier.at(i)->setDuration(this->resourceModifier.at(i)->getDuration() - 1);

			if (this->resourceModifier.at(i)->getDuration() <= 0)
			{
				this->resourceModifier.erase(resourceModifier.begin() + i);
			}
		}
	}

	this->corruption += this->endTurnChange;

	if (this->corruption < 0)
	{
		this->corruption = 0;
	}

	else if (this->corruption > 100)
	{
		this->corruption = 100;
	}

	this->makeTooltip();
}

void CorruptionRate::makeTooltip()
{
	this->myTooltip->setHeadLine("Corruption Modifiers");

	this->myTooltip->clearAllLines();

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		std::string val = std::to_string((float)this->resourceModifier.at(i)->getValue());
		std::string useVal = val.substr(0, val.length() - 4);

		if (this->resourceModifier.at(i)->getValue() < 0)
		{
			this->myTooltip->addLine(this->resourceModifier.at(i)->getShortText() + " " 
				+ useVal);
		}

		else
		{
			this->myTooltip->addLine(this->resourceModifier.at(i)->getShortText() + " +" 
				+ useVal);
		}

		if (this->resourceModifier.at(i)->isFinite())
		{
			this->myTooltip->addLine("Duration: " + std::to_string((int)this->resourceModifier.at(i)->getDuration()) 
				+ " months.", 10);
		}
	}
}

std::shared_ptr<Modifier> CorruptionRate::getCorruptionModifierById(std::string id)
{
	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->getId() == id)
		{
			return this->resourceModifier.at(i);
		}
	}

	return nullptr;
}

void CorruptionRate::addCorruptionModifier(std::shared_ptr<Modifier> val)
{
	this->resourceModifier.push_back(val);

	this->recalcCorruption();
}

void CorruptionRate::subCorruptionModifier(std::string id)
{
	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->getId() == id)
		{
			this->resourceModifier.erase(resourceModifier.begin() + i);
		}
	}

	this->recalcCorruption();
}

void CorruptionRate::recalcCorruption()
{
	this->endTurnChange = 0;

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		this->endTurnChange += this->resourceModifier.at(i)->getValue();
	}

	if (this->corruption < 0)
	{
		this->corruption = 0;
	}

	else if (this->corruption > 100)
	{
		this->corruption = 100;
	}
}

CorruptionRate::~CorruptionRate()
{

}