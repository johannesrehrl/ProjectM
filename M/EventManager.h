#pragma once
#include <vector>
#include <Thor/Math.hpp>
#include "Event.h"

class EventManager
{
private:
	std::vector<std::shared_ptr<Event>> allEvents;
	std::vector<std::shared_ptr<Event>> activeEvents;

public:
	EventManager();
	~EventManager();
	void updateEndTurn(int month, int year);
	std::vector<std::shared_ptr<Event>> getActiveEvents() { return this->activeEvents; }
};