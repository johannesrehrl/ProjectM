#include "NationalStability.h"

NationalStability::NationalStability()
{
	this->stability = 0;
}

void NationalStability::updateEndTurn()
{
	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->isFinite())
		{
			this->resourceModifier.at(i)->setDuration(this->resourceModifier.at(i)->getDuration() - 1);
		}
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