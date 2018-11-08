#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Flag
{
private:
	std::string id;
	bool active;
	std::shared_ptr<std::vector<std::string>> flagDependencies;
	std::shared_ptr<sf::Vector2i> dateDependencies;
	int dateChance;
	bool dateDependent;

public:
	Flag(std::string id, bool active);
	~Flag();

	std::string getId() { return this->id; }
	std::string setId(std::string val) { this->id = val; }
	bool isActive() { return this->active; }
	void setActive(bool val) { this->active = val; }

	std::shared_ptr<std::vector<std::string>> getFlagDependencies() { return this->flagDependencies; }
	std::shared_ptr<sf::Vector2i> getDateDependencies() { return this->dateDependencies; }
	int getDateChance() { return dateChance; }
	void setDateChance(int val) { this->dateChance = val; }
	bool isDateDependent() { return this->dateDependent; }
};
