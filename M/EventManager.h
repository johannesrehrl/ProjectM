#pragma once
#include <vector>
#include <Thor/Math.hpp>
#include "GameEvent.h"

class EventManager
{
private:
	std::vector<std::shared_ptr<GameEvent>> allEvents;
	std::vector<std::shared_ptr<GameEvent>> activeEvents;

public:
	EventManager();
	~EventManager();
	void updateEndTurn(int month, int year);
	std::vector<std::shared_ptr<GameEvent>> getActiveEvents() { return this->activeEvents; }
};