#include "GameEvent.h"

GameEvent::GameEvent(std::string id,
	std::string headline,
	std::string text,
	std::vector<std::string> optionText,
	std::vector<std::function<void()>> checkFire,
	std::vector<std::function<void()>> allResults)
{
	this->headline = headline;
	this->text = text;
	this->optionText = optionText;
	this->checkFire = checkFire;
	this->allResults = allResults;
}

GameEvent::~GameEvent()
{

}