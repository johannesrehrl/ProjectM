#include "ResourceHandler.h"

ResourceHandler::ResourceHandler()
{
	this->fontHolder.acquire("expressway", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\expressway_rg.ttf"));
	this->fontHolder.acquire("aquifer", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\aquifer.regular.ttf"));
	this->fontHolder.acquire("arcadeclassic", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\ARCADECLASSIC.TTF"));
	this->fontHolder.acquire("bombardier", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\bombardier.regular.ttf"));
	this->fontHolder.acquire("pixelverdana", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\PixelFJVerdana12pt.ttf"));
	this->fontHolder.acquire("rothwell", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\rothwell.army.ttf"));
	this->fontHolder.acquire("squares-bold", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\squares-bold.regular.otf"));

	this->colorHolder["background"] = sf::Color(187, 190, 193);
	this->colorHolder["grey"] = sf::Color(80, 80, 80);

	this->actionMap["leftRelease"] = thor::Action(sf::Mouse::Left, thor::Action::ReleaseOnce);
	this->actionMap["rightRelease"] = thor::Action(sf::Mouse::Right, thor::Action::ReleaseOnce);
	this->actionMap["gainedFocus"] = thor::Action(sf::Event::GainedFocus);
	this->actionMap["lostFocus"] = thor::Action(sf::Event::LostFocus);
	this->actionMap["closedWindow"] = thor::Action(sf::Event::Closed);
}

ResourceHandler::~ResourceHandler()
{
	this->fontHolder.release("expressway");
	this->fontHolder.release("aquifer");
	this->fontHolder.release("arcadeclassic");
	this->fontHolder.release("bombardier");
	this->fontHolder.release("pixelverdana");
	this->fontHolder.release("rothwell");
	this->fontHolder.release("squares-bold");

	this->actionMap.clearEvents();
}