#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Flag.h"
#include "Modifier.h"

class Event
{
private:
	bool active;
	std::string id;
	std::string headline;
	std::string text;
	std::vector<std::string> optionText;

	// Possible flags added by option choosen.
	std::map<int, std::shared_ptr<Flag>> addFlagResults;
	std::map<int, std::string> subFlagResults;

	// Possible plain influence change by option choosen.
	std::map<int, float> plainInfluenceResults;

	// Possible monthly influence change by option choosen.
	std::map<int, std::shared_ptr<Modifier>> addInfluenceModResults;
	std::map<int, std::shared_ptr<Modifier>> subInfluenceModResults;

	// Possible total stability change by option choosen.
	std::map<int, std::shared_ptr<Modifier>> addStabilityModResults;
	std::map<int, std::shared_ptr<Modifier>> subStabilityModResults;

	// Possible power change of a specific Ministry by option choosen.
	std::map<int, std::string, std::shared_ptr<Modifier>> addMinistryPowerModResults;
	std::map<int, std::string, std::shared_ptr<Modifier>> subMinistryPowerModResults;

	// Possible loyality change of a specific Ministry by option choosen.
	std::map<int, std::string, std::shared_ptr<Modifier>> addMinistryLoyalityModResults;
	std::map<int, std::string, std::shared_ptr<Modifier>> subMinistryLoyalityPowerModResults;

	std::shared_ptr<std::vector<std::string>> flagDependencies;
	std::shared_ptr<sf::Vector2i> dateDependency;
	std::shared_ptr<sf::Vector2i> endDateDependency;
	int dateChance;
	bool dateDependent;

public:
	Event();
	~Event();

	std::string getId() { return this->id; }
	bool isActive() { return this->active; }
	void setActive(bool val) { this->active = val; }

	std::shared_ptr<std::vector<std::string>> getFlagDependencies() { return this->flagDependencies; }
	std::shared_ptr<sf::Vector2i> getDateDependencies() { return this->dateDependency; }
	std::shared_ptr<sf::Vector2i> getEndDateDependencies() { return this->endDateDependency; }
	int getDateChance() { return dateChance; }
	void setDateChance(int val) { this->dateChance = val; }
	bool isDateDependent() { return this->dateDependent; }
};