#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"
#include "TurnManager.h"
#include "ResourceManager.h" 
#include "Government.h" 

class MainStatisticsContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<TurnManager> turnManager;
	std::shared_ptr<ResourceManager> resourceManager;
	std::shared_ptr<Government> government;

	sf::RectangleShape body;
	sf::RectangleShape bodyShadow;

	sf::Text headline;
	sf::Text dateText;
	sf::Text presidentNameText;
	sf::Text influenceText;
	sf::Text stabilityText;

	sf::Sprite influenceSprite;
	sf::Sprite stabilitySprite;

public:
	MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<TurnManager> turnManager,
		std::shared_ptr<ResourceManager> resourceManager, std::shared_ptr<Government> government);
	~MainStatisticsContainer();
	void updateEndTurn();
	void update();
	void draw();
};