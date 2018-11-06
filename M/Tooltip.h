#pragma once
#include <string>
#include "AssetsHandler.h"
#include "Window.h"

class Tooltip
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

	sf::Sprite sprite;
	sf::RectangleShape body;
	sf::Text headLineText;
	std::vector<sf::Text> allLines;
	std::shared_ptr<sf::RenderTexture> tex;

public:
	Tooltip(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~Tooltip();
	void updateTexture();
	void draw();

	void setHeadLine(std::string headLineString) { this->headLineText.setString(headLineString); this->updateTexture(); }
	void addLine(std::string lineString);
	void setPosition(sf::Vector2i pos);

	void clearAllLines() { this->allLines.clear(); }
};