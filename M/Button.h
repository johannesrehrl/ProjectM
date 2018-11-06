#pragma once
#include <SFML/Graphics.hpp>
#include "AssetsHandler.h"
#include "Window.h"
#include <string>

class Button
{
private:
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<Window> window;
	sf::Text text;
	bool active;
	std::function<void()> onSelect;
	bool selected;
	sf::RenderTexture textureDefault;
	sf::RenderTexture textureSelected;
	sf::Sprite buttonSprite;

public:
	enum style { STANDARD, NEXT_TURN, PAUSE_MENU };
	Button(std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Window> window, std::string string, style choosenStyle, sf::Vector2f pos);
	~Button();
	bool isActive() { return active; }
	void setActive(bool val) { this->active = val; }
	void update(sf::Vector2i mousePos);
	void draw();
	void setOnSelect(const std::function<void()> &onSelect) { this->onSelect = onSelect; }
	bool isSelected() { return selected; }
};
