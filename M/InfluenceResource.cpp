#include "InfluenceResource.h"

InfluenceResource::InfluenceResource(float influence)
{
	this->influence = influence;
	this->endTurnChange = 0;
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
		}
	}

	this->influence += this->endTurnChange;
}

void InfluenceResource::subInfluenceResource(std::string id)
{
	for (int i = 0; i < this->resourceModifier.size(); i++)
	{
		if (this->resourceModifier.at(i)->getId() == id)
		{
			this->resourceModifier.erase(resourceModifier.begin() + i);
		}
	}
}

InfluenceResource::~InfluenceResource()
{

}