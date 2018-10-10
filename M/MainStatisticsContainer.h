#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"

class MainStatisticsContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

	sf::RectangleShape body;
	sf::RectangleShape bodyShadow;
	sf::Text headline;

public:
	MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~MainStatisticsContainer();
	void update();
	void draw();
};