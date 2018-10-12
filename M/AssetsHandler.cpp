#include "AssetsHandler.h"

AssetsHandler::AssetsHandler()
{
	this->fontHolder.acquire("expressway", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\expressway_rg.ttf"));
	this->fontHolder.acquire("aquifer", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\aquifer.regular.ttf"));
	this->fontHolder.acquire("arcadeclassic", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\ARCADECLASSIC.TTF"));
	this->fontHolder.acquire("bombardier", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\bombardier.regular.ttf"));
	this->fontHolder.acquire("pixelverdana", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\PixelFJVerdana12pt.ttf"));
	this->fontHolder.acquire("rothwell", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\rothwell.army.ttf"));
	this->fontHolder.acquire("squares-bold", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\squares-bold.regular.otf"));
	this->fontHolder.acquire("arty-signature", thor::Resources::fromFile<sf::Font>("gamefiles\\assets\\fonts\\Arty_Signature.otf"));

	this->textureHolder.acquire("influence-icon", thor::Resources::fromFile<sf::Texture>("gamefiles\\assets\\textures\\influence_icon.png"));
	this->textureHolder.acquire("stability-icon", thor::Resources::fromFile<sf::Texture>("gamefiles\\assets\\textures\\stability_icon.png"));

	this->colorHolder["background"] = sf::Color(200, 200, 200);
	this->colorHolder["grey30"] = sf::Color(30, 30, 30);
	this->colorHolder["grey80"] = sf::Color(80, 80, 80);
	this->colorHolder["grey160"] = sf::Color(160, 160, 160);
	this->colorHolder["grey170"] = sf::Color(170, 170, 170);
	this->colorHolder["grey185"] = sf::Color(185, 185, 185);
	this->colorHolder["grey200"] = sf::Color(200, 200, 200);
	this->colorHolder["red215"] = sf::Color(215, 0, 0);
	this->colorHolder["black"] = sf::Color::Black;

	this->actionMap["leftRelease"] = thor::Action(sf::Mouse::Left, thor::Action::ReleaseOnce);
	this->actionMap["rightRelease"] = thor::Action(sf::Mouse::Right, thor::Action::ReleaseOnce);
	this->actionMap["escapeRelease"] = thor::Action(sf::Keyboard::Escape, thor::Action::ReleaseOnce);
	this->actionMap["gainedFocus"] = thor::Action(sf::Event::GainedFocus);
	this->actionMap["lostFocus"] = thor::Action(sf::Event::LostFocus);
	this->actionMap["closedWindow"] = thor::Action(sf::Event::Closed);
	this->actionMap["textEntered"] = thor::Action(sf::Event::TextEntered);
}

AssetsHandler::~AssetsHandler()
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