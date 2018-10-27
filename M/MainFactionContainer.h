#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"
#include "Government.h"
#include "MinistryCard.h"

class MainFactionContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<Government> government;

	std::shared_ptr<MinistryCard> financeMinistryCard;
	std::shared_ptr<MinistryCard> defenceMinistryCard;

	sf::RectangleShape body;
	sf::RectangleShape bodyShadow;
	sf::Text headline;

public:
	MainFactionContainer(std::shared_ptr<Government> government, std::shared_ptr<AssetsHandler> assetsHandler,
		std::shared_ptr<Window> window);
	~MainFactionContainer();
	void update();
	void updateEndTurn();
	void draw();
};