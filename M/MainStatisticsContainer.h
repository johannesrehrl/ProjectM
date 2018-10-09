#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "ResourceHandler.h"

class MainStatisticsContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<ResourceHandler> resourceHandler;

	sf::RectangleShape head;
	sf::RectangleShape body;

public:
	MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler);
	~MainStatisticsContainer();
	void update();
	void draw();
};