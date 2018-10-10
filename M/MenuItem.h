#pragma once
#include <SFML/Graphics.hpp>
#include "UiObj.h"
#include "AssetsHandler.h"
#include "Window.h"

class MenuItem : public UiObj
{
private:
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<Window> window;
	sf::Text text;
	sf::RectangleShape rect;
	sf::RectangleShape hitBox;
	bool active;
	float posX;
	std::function<void()> onSelect;
	bool selected;

public:
	MenuItem(std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Window> window, std::string text, sf::Vector2f pos);
	~MenuItem();
	bool isActive() { return active; }
	void setActive(bool val) { this->active = val; }
	void update(sf::Vector2i mousePos);
	void draw();
	void setOnSelect(const std::function<void()> &onSelect) { this->onSelect = onSelect; }
	bool isSelected() { return selected; }
};