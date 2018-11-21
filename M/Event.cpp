#include "Event.h"

Event::Event(bool deadUntoFire,
	bool dead,
	std::string id,
	std::string headline,
	std::string text,
	std::vector<std::string> optionText,

	bool hasDateRange,
	bool rangeActive,
	float rangeChance,
	sf::Vector2i lowerDateLimit,
	sf::Vector2i upperDateLimit,

	bool hasCounter,
	bool counterActive,
	bool startCounter,
	float counterChance,
	int monthsUntilFire,

	bool hasFlagDependency,
	bool flagActive,
	float flagChance,
	std::vector<std::vector<std::string>> flagDependencies,

	std::vector<std::vector<std::string>> linkedDependencies,
	
	std::shared_ptr<FlagManager> flagManager)
{
	this->deadUntoFire = deadUntoFire;
	this->dead = dead;
	this->headline = headline;
	this->text = text;
	this->optionText = optionText;

	this->hasDateRange = hasDateRange;
	this->rangeActive = rangeActive;
	this->rangeChance = rangeChance;
	this->lowerDateLimit = lowerDateLimit;
	this->upperDateLimit = upperDateLimit;

	this->hasCounter = hasCounter;
	this->counterActive = counterActive;
	this->startCounter = startCounter;
	this->counterChance = counterChance;
	this->monthsUntilFire = monthsUntilFire;

	this->hasFlagDependency = hasFlagDependency;
	this->flagActive = flagActive;
	this->flagChance = flagChance;
	this->flagDependencies = flagDependencies;

	this->linkedDependencies = linkedDependencies;
	
	this->flagManager = flagManager;
}

void Event::calcActive(int month, int year)
{
	this->active = false;
	this->rangeActive = false;
	this->counterActive = false;
	this->flagActive = false;

	if (dead) { return; }

	if (hasDateRange)
	{
		if (month >= lowerDateLimit.x && year >= lowerDateLimit.y &&
			month <= upperDateLimit.x && year <= upperDateLimit.y)
		{
			if (thor::random(0, 100) <= this->rangeChance)
			{
				this->rangeActive = true;
			}
		}
	}

	if (hasCounter)
	{
		if (monthsUntilFire <= 0)
		{
			if (thor::random(0, 100) <= this->counterChance)
			{
				this->counterActive = true;
			}
		}
	}

	if (hasFlagDependency)
	{
		for (int i = 0; i < this->flagDependencies.size(); i++)
		{
			bool act = true;

			for (int x = 0; x < this->flagDependencies.at(i).size(); x++)
			{
				if (this->flagManager->doesFlagExist(this->flagDependencies.at(i).at(x)))
				{
					if (!this->flagManager->getFlag(this->flagDependencies.at(i).at(x))->isActive())
					{
						act = false;
					}
				}
			}

			if (act)
			{
				if (thor::random(0, 100) <= this->flagChance)
				{
					this->flagActive = true;
				}
			}
		}
	}

	if (this->linkedDependencies.size() != 0)
	{
		if (this->counterActive || this->rangeActive || this->flagActive)
		{
			this->active = true;
		}

		else
		{
			this->active = false;
		}
	}

	else
	{
		for (int i = 0; i < linkedDependencies.size(); i++)
		{
			bool act = true;

			for (int x = 0; x < linkedDependencies.at(i).size(); x++)
			{
				if (linkedDependencies.at(i).at(x) == "range")
				{
					if (!this->rangeActive)
					{
						act = false;
					}
				}

				else if (linkedDependencies.at(i).at(x) == "counter")
				{
					if (!this->counterActive)
					{
						act = false;
					}
				}

				else if (linkedDependencies.at(i).at(x) == "flag")
				{
					if (!this->flagActive)
					{
						act = false;
					}
				}
			}

			if (act)
			{
				this->active = true;
			}
		}
	}
}

Event::~Event()
{

}