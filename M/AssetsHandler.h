#pragma once
#include <Thor/Resources.hpp>
#include <Thor/Input.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class AssetsHandler
{
private:
	thor::ResourceHolder<sf::Font, std::string> fontHolder;
	std::map<std::string, sf::Color> colorHolder;
	thor::ActionMap<std::string> actionMap;

public:
	AssetsHandler();
	~AssetsHandler();
	thor::ResourceHolder<sf::Font, std::string>& getFontHolder() { return fontHolder; }
	std::map<std::string, sf::Color>& getColorHolder() { return colorHolder; }
	thor::ActionMap<std::string>& getActionMap() { return actionMap; }
};