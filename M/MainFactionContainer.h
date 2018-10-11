#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"

class MainFactionContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

	sf::RectangleShape body;
	sf::RectangleShape bodyShadow;
	sf::Text headline;

public:
	MainFactionContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~MainFactionContainer();
	void updateEndTurn();
	void draw();
};