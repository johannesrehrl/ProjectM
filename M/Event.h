#pragma once
#include <SFML/Graphics.hpp>
#include <THOR/Math.hpp>
#include <string>
#include <vector>
#include "Flag.h"
#include "FlagManager.h"
#include "Modifier.h"

class Event
{
private:
	std::shared_ptr<FlagManager> flagManager;

	bool dead;
	//True if event can only be fired once.
	bool deadUntoFire;
	bool active;
	std::string id;
	std::string headline;
	std::string text;
	std::vector<std::string> optionText;

	//Event only able to fire within range of dates.
	bool hasDateRange;
	bool rangeActive;
	float rangeChance;
	sf::Vector2i lowerDateLimit;
	sf::Vector2i upperDateLimit;

	//Event is counting down until it is fired.
	bool hasCounter;
	bool counterActive;
	bool startCounter;
	float counterChance;
	int monthsUntilFire;

	//Event fired by a combination of flags.
	bool hasFlagDependency;
	bool flagActive;
	float flagChance;
	std::vector<std::vector<std::string>> flagDependencies;

	//Event is fired if a combination of dependencies (flag, counter, date range, etc...) is true.
	std::vector<std::vector<std::string>> linkedDependencies;
public:
	Event(bool dead,
	bool deadUntoFire,
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

	std::shared_ptr<FlagManager> flagManager
	);
	~Event();

	void calcActive(int month, int year);
	void updateEndTurn() { if (dead) { return; } if (startCounter) { this->monthsUntilFire--; } }

	std::string getId() { return this->id; }
	bool isActive() { return this->active; }
	void setActive(bool val) { this->active = val; }

	void kickOffCounter() { this->startCounter = true; }
	void endCounter() { this->startCounter = false; }

	void kill() { this->dead = true; }
	bool isDeadUntoFire() { return this->deadUntoFire; }
};