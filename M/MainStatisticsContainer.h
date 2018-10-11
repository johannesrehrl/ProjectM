#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"
#include "TurnManager.h"

class MainStatisticsContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<TurnManager> turnManager;

	sf::RectangleShape body;
	sf::RectangleShape bodyShadow;

	sf::Text headline;
	sf::Text dateText;

public:
	MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<TurnManager> turnManager);
	~MainStatisticsContainer();
	void updateEndTurn();
	void draw();
};