#include "EventManager.h"

EventManager::EventManager()
{

}

void EventManager::updateEndTurn(int month, int year)
{
	this->activeEvents.clear();

	for (int i = 0; i < this->allEvents.size(); i++)
	{
		this->allEvents.at(i)->setActive(false);

		for (int x = 0; x < this->allEvents.at(i)->getFlagDependencies()->size(); x++)
		{
			for (int a = 0; a < this->allEvents.size(); a++)
			{
				// Activate event if it is not date dependent.
				if (this->allEvents.at(i)->getFlagDependencies()->at(x) == this->allEvents.at(a)->getId() && 
					!this->allEvents.at(i)->isDateDependent())
				{
					this->allEvents.at(i)->setActive(true);
				}

				// Event will be active when both dependencies are met.
				else if (this->allEvents.at(i)->getFlagDependencies()->at(x) == this->allEvents.at(a)->getId() && this->allEvents.at(i)->isDateDependent())
				{
					if (this->allEvents.at(i)->getDateDependencies()->x >= month &&
						this->allEvents.at(i)->getDateDependencies()->y >= year &&
						this->allEvents.at(i)->getEndDateDependencies()->x <= month &&
						this->allEvents.at(i)->getEndDateDependencies()->y <= year)
					{
						if (thor::random(0, 100) >= this->allEvents.at(i)->getDateChance())
						{
							this->allEvents.at(i)->setActive(true);
						}
					}
				}
			}
		}

		if (this->allEvents.at(i)->getDateDependencies()->x >= month &&
			this->allEvents.at(i)->getDateDependencies()->y >= year &&
			this->allEvents.at(i)->getEndDateDependencies()->x <= month &&
			this->allEvents.at(i)->getEndDateDependencies()->y <= year)
		{
			if (thor::random(0, 100) <= this->allEvents.at(i)->getDateChance())
			{
				this->allEvents.at(i)->setActive(true);
			}
		}

		if (this->allEvents.at(i)->isActive())
		{
			this->activeEvents.push_back(this->allEvents.at(i));
		}
	}
}

EventManager::~EventManager()
{

}