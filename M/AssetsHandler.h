#pragma once
#include <Thor/Resources.hpp>
#include <Thor/Input.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class AssetsHandler
{
private:
	thor::ResourceHolder<sf::Font, std::string> fontHolder;
	thor::ResourceHolder<sf::Texture, std::string> textureHolder;
	std::map<std::string, sf::Color> colorHolder;
	thor::ActionMap<std::string> actionMap;

public:
	AssetsHandler();
	~AssetsHandler();
	thor::ResourceHolder<sf::Font, std::string>& getFontHolder() { return this->fontHolder; }
	thor::ResourceHolder<sf::Texture, std::string>& getTextureHolder() { return this->textureHolder; }
	std::map<std::string, sf::Color>& getColorHolder() { return this->colorHolder; }
	thor::ActionMap<std::string>& getActionMap() { return this->actionMap; }
};