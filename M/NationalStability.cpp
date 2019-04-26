#include "NationalStability.h"

NationalStability::NationalStability(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->stability = 0;
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->myTooltip = std::make_shared<Tooltip>(this->window, this->assetsHandler);
}

void NationalStability::updateEndTurn()
{
	this->stability = 0;

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->isFinite())
		{
			this->resourceModifier.at(i)->setDuration(this->resourceModifier.at(i)->getDuration() - 1);

			if (this->resourceModifier.at(i)->getDuration() >= 0)
			{
				this->resourceModifier.erase(resourceModifier.begin() + i);
			}
		}

		this->stability += this->resourceModifier.at(i)->getValue();
	}

	this->makeTooltip();
}

void NationalStability::makeTooltip()
{
	this->myTooltip->setHeadLine("Stability Modifiers");

	this->myTooltip->clearAllLines();

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->getValue() < 0)
		{
			this->myTooltip->addLine(this->resourceModifier.at(i)->getShortText() + " "
				+ std::to_string((int)this->resourceModifier.at(i)->getValue()));
		}

		else
		{
			this->myTooltip->addLine(this->resourceModifier.at(i)->getShortText() + " +"
				+ std::to_string((int)this->resourceModifier.at(i)->getValue()));
		}

		if (this->resourceModifier.at(i)->isFinite())
		{
			this->myTooltip->addLine("Duration: " + std::to_string((int)this->resourceModifier.at(i)->getDuration()) 
				+ " months.", 10);
		}
	}
}

std::shared_ptr<Modifier> NationalStability::getStabilityModifierById(std::string id)
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

void NationalStability::addStabilityModifier(std::shared_ptr<Modifier> val)
{
	this->resourceModifier.push_back(val);

	this->stability = 0;

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		this->stability += this->resourceModifier.at(i)->getValue();
	}
}

void NationalStability::subStabilityModifier(std::string id)
{
	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->getId() == id)
		{
			this->resourceModifier.erase(resourceModifier.begin() + i);
		}
	}
}

NationalStability::~NationalStability()
{

}