#include "FlagManager.h"

FlagManager::FlagManager()
{

}

void FlagManager::updateEndTurn(int month, int year)
{
	for (int i = 0; i < this->allFlags.size(); i++)
	{
		for (int x = 0; x < this->allFlags.at(i)->getFlagDependencies()->size(); x++)
		{
			for (int a = 0; a < this->allFlags.size(); a++)
			{
				if (this->allFlags.at(i)->getFlagDependencies()->at(x) == this->allFlags.at(a)->getId())
				{
					this->allFlags.at(i)->setActive(true);
				}
			}
		}
				
		if (this->allFlags.at(i)->getDateDependencies()->x == month &&
			this->allFlags.at(i)->getDateDependencies()->y == year &&
			this->allFlags.at(i)->isDateDependent())
		{
			if(thor::random(0, 100) >= this->allFlags.at(i)->getDateChance())
			{
				this->allFlags.at(i)->setActive(true);
			}
		}
	}
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