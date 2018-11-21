#include "EventManager.h"

EventManager::EventManager()
{

}

void EventManager::updateEndTurn(int month, int year)
{
	this->activeEvents.clear();

	for (int i = 0; i < this->allEvents.size(); i++)
	{
		this->allEvents.at(i)->updateEndTurn();
		this->allEvents.at(i)->calcActive(month, year);
		
		if (this->allEvents.at(i)->isActive())
		{
			this->activeEvents.push_back(this->allEvents.at(i));

			if (this->allEvents.at(i)->isDeadUntoFire())
			{
				this->allEvents.at(i)->kill();
			}
		}
	}
}

EventManager::~EventManager()
{

}