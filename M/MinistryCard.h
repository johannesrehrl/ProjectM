#pragma once
#include <SFML/Graphics.hpp>
#include "Ministry.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "Cursor.h"

class MinistryCard 
{
private:
	std::shared_ptr<Ministry> ministry;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<Cursor> cursor;

	sf::RectangleShape body;

	sf::Text nameText;
	sf::Text corruptionText;
	sf::Text ministerText;
	sf::Text powerText;
	sf::Text loyalityText;

	sf::Sprite corruptionIconSprite;
	sf::Sprite powerIconSprite;
	sf::Sprite loyalityIconSprite;

public:
	MinistryCard(std::shared_ptr<Ministry> ministry, sf::Vector2f size, sf::Vector2f pos, 
		std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Cursor> cursor);
	~MinistryCard();
	void update(sf::Vector2i mousePos);
	void updateEndTurn();
	void draw();
};