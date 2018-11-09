#include "FlagManager.h"

FlagManager::FlagManager()
{

}

void FlagManager::updateEndTurn()
{
	
}

bool FlagManager::doesFlagExist(std::string id)
{
	for (int i = 0; i < this->allFlags.size(); i++)
	{
		if (id == this->allFlags.at(i)->getId())
		{
			return true;
		}
	}

	return false;
}

std::shared_ptr<Flag> FlagManager::getFlag(std::string id)
{
	for (int i = 0; i < this->allFlags.size(); i++)
	{
		if (id == this->allFlags.at(i)->getId())
		{
			return this->allFlags.at(i);
		}
	}

	return nullptr;
}

void FlagManager::deleteFlag(std::string id)
{
	for (int i = 0; i < this->allFlags.size(); i++)
	{
		if (id == this->allFlags.at(i)->getId())
		{
			this->allFlags.erase(allFlags.begin() + i);
		}
	}
}

FlagManager::~FlagManager()
{

}