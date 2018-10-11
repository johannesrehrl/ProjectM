#include "TurnManager.h"

TurnManager::TurnManager(std::shared_ptr<FlagManager> flagManager)
{
	this->flagManager = flagManager;

	this->monthMap[0] = "January";
	this->monthMap[1] = "February";
	this->monthMap[2] = "March";
	this->monthMap[3] = "April";
	this->monthMap[4] = "May";
	this->monthMap[5] = "June";
	this->monthMap[6] = "July";
	this->monthMap[7] = "August";
	this->monthMap[8] = "September";
	this->monthMap[9] = "October";
	this->monthMap[10] = "November";
	this->monthMap[11] = "December";

	this->month = 1;
	this->year = 1900;
}

void TurnManager::update()
{

}

void TurnManager::endTurn()
{
	if (this->flagManager->doesFlagExist("end_turn"))
	{
		this->flagManager->getFlag("end_turn")->setActive(true);
	}

	else
	{
		this->flagManager->addFlag(std::make_shared<Flag>("end_turn", true));
	}

	month++;

	if (month > 12)
	{
		month = 1;
		year++;
	}
}

TurnManager::~TurnManager()
{

}