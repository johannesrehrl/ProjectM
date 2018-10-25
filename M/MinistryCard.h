#pragma once
#include <SFML/Graphics.hpp>
#include "Ministry.h"

class MinistryCard 
{
private:
	std::shared_ptr<Ministry> ministry;

	sf::RectangleShape body;

	sf::Text nameText;
	sf::Text corruptionText;
	sf::Text ministerText;
	sf::Text powerText;
	sf::Text loyalityText;

public:
	MinistryCard(std::shared_ptr<Ministry> ministry);
	~MinistryCard();
	void update();
	void updateEndTurn();
	void draw();
};