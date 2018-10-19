#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "AssetsHandler.h"

class Tooltip
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

	sf::RectangleShape body;
	sf::Text text;
	sf::RenderTexture texture;
	sf::Sprite sprite;

	bool display;

public:
	Tooltip(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, sf::Text text, sf::Vector2f pos);
	~Tooltip();

	void setText(sf::Text text, sf::Vector2f pos);
	void update();
	void draw();

	void setDisplay(bool val) { this->display = display; }
	bool getDisplay() { return this->display; }
};