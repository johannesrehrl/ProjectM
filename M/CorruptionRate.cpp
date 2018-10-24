#include "CorruptionRate.h"

CorruptionRate::CorruptionRate(float corruption)
{
	this->corruption = corruption;
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
}

void CorruptionRate::addCorruptionModifier(std::shared_ptr<Modifier> val)
{
	this->resourceModifier.push_back(val);

	this->endTurnChange = 0;

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		this->endTurnChange += this->resourceModifier.at(i)->getValue();
	}
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
}

void CorruptionRate::recalcCorruption()
{
	this->endTurnChange = 0;

	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		this->endTurnChange += this->resourceModifier.at(i)->getValue();
	}
}

CorruptionRate::~CorruptionRate()
{

}