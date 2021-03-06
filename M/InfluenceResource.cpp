#include "InfluenceResource.h"

InfluenceResource::InfluenceResource(float influence, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->influence = influence;
	this->endTurnChange = 0;

	this->myTooltip = std::make_shared<Tooltip>(this->window, this->assetsHandler);
}

void InfluenceResource::updateEndTurn()
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

	this->influence += this->endTurnChange;

	if (this->influence < 0)
	{
		this->influence = 0;
	}

	this->makeTooltip();
}

void InfluenceResource::makeTooltip()
{
	this->myTooltip->setHeadLine("Influence Modifiers");

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

std::shared_ptr<Modifier> InfluenceResource::getInfluenceModifierById(std::string id)
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

void InfluenceResource::addInfluenceModifier(std::shared_ptr<Modifier> val)
{
	this->resourceModifier.push_back(val);

	this->endTurnChange = 0;

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		this->endTurnChange += this->resourceModifier.at(i)->getValue();
	}

	this->makeTooltip();
}

void InfluenceResource::subInfluenceModifier(std::string id)
{
	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->getId() == id)
		{
			this->resourceModifier.erase(resourceModifier.begin() + i);
		}
	}

	this->makeTooltip();
}

InfluenceResource::~InfluenceResource()
{

}