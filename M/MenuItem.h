#pragma once
#include <SFML/Graphics.hpp>
#include "UiObj.h"
#include "ResourceHandler.h"

class MenuItem : public UiObj
{
private:
	std::shared_ptr<ResourceHandler> resourceHandler;
	sf::Text text;
	sf::RectangleShape rect;
	sf::RectangleShape hitBox;
	bool active;
	float posX;
	std::function<void()> onSelect;
	bool selected;

public:
	MenuItem(std::shared_ptr<ResourceHandler> resourceHandler, std::string text, sf::Vector2i pos);
	~MenuItem();
	bool isActive() { return active; }
	void setActive(bool val) { this->active = val; }
	void update(sf::Vector2i mousePos, int fps);
	void draw(std::shared_ptr<sf::RenderWindow> window);
	void setOnSelect(const std::function<void()> &onSelect) { this->onSelect = onSelect; }
	bool isSelected() { return selected; }
	void fireOnSelect();
};