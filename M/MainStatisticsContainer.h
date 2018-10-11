#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"
#include "TurnManager.h"
#include "ResourceManager.h" 

class MainStatisticsContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<TurnManager> turnManager;
	std::shared_ptr<ResourceManager> resourceManager;

	sf::RectangleShape body;
	sf::RectangleShape bodyShadow;

	sf::Text headline;
	sf::Text dateText;
	sf::Text influenceText;
	sf::Text stabilityText;

public:
	MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<TurnManager> turnManager,
		std::shared_ptr<ResourceManager> resourceManager);
	~MainStatisticsContainer();
	void updateEndTurn();
	void draw();
};