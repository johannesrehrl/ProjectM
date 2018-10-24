#include "NationalStability.h"

NationalStability::NationalStability()
{
	this->stability = 0;
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