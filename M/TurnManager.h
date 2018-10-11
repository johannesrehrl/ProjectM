#pragma once
#include <string>
#include <map>
#include "FlagManager.h"
#include "Flag.h"

class TurnManager
{
private:
	std::shared_ptr<FlagManager> flagManager;
	int turn;
	std::string monthMap [12];
	int month;
	int year;

public:
	TurnManager(std::shared_ptr<FlagManager> flagManager);
	~TurnManager();
	void update();
	void endTurn();

	std::string getDate() { return monthMap[month - 1] + ", " + std::to_string(year); }
	int getTurn() { return turn; }
	int getYear() { return year; }
	int getMonth() { return month; }
};