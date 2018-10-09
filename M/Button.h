#pragma once
#include <SFML/Graphics.hpp>
#include "UiObj.h"
#include "ResourceHandler.h"
#include "Window.h"
#include <string>

class Button : public UiObj
{
private:
	std::shared_ptr<ResourceHandler> resourceHandler;
	std::shared_ptr<Window> window;
	sf::Text text;
	bool active;
	std::function<void()> onSelect;
	bool selected;
	sf::RenderTexture textureDefault;
	sf::RenderTexture textureSelected;
	sf::Sprite buttonSprite;

public:
	enum style { STANDARD };
	Button(std::shared_ptr<ResourceHandler> resourceHandler, std::shared_ptr<Window> window, std::string string, style choosenStyle, sf::Vector2f pos);
	~Button();
	bool isActive() { return active; }
	void setActive(bool val) { this->active = val; }
	void update(sf::Vector2i mousePos);
	void draw();
	void setOnSelect(const std::function<void()> &onSelect) { this->onSelect = onSelect; }
	bool isSelected() { return selected; }
};
