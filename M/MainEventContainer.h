#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"
#include "Cursor.h"

class MainEventContainer
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<Cursor> cursor;

	sf::RectangleShape body;
	sf::RectangleShape bodyShadow;
	sf::Text headline;

public:
	MainEventContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Cursor> cursor);
	~MainEventContainer();
	void updateEndTurn();
	void draw();
};