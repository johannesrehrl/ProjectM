#include "CorruptionRate.h"

CorruptionRate::CorruptionRate()
{
	this->corruption = 0;
	this->endTurnChange = 0;
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