#include "MainMenuState.h"

MainMenuState::MainMenuState(std::shared_ptr<Settings> settings, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->stateChange = "";
	this->settings = settings;
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->itemList.push_back(std::make_shared<MenuItem>
		(this->assetsHandler, this->window, "Start", sf::Vector2f(100, this->window->getDesktop().front().height - 300)));
	this->itemList.at(0)->setOnSelect([this] {
		stateChange = "SETUP";
	});

	this->itemList.push_back(std::make_shared<MenuItem>
		(this->assetsHandler, this->window, "Settings", sf::Vector2f(100, this->window->getDesktop().front().height - 240)));

	this->itemList.push_back(std::make_shared<MenuItem>
		(this->assetsHandler, this->window, "Load", sf::Vector2f(100, this->window->getDesktop().front().height - 180)));

	this->itemList.push_back(std::make_shared<MenuItem>(
		this->assetsHandler, this->window, "Exit", sf::Vector2f(100, this->window->getDesktop().front().height - 120)));
	this->itemList.at(3)->setOnSelect([window] {
		window->getWindow()->close();
	});
}

void MainMenuState::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	for (int i = 0; i < this->itemList.size(); i++){ this->itemList.at(i)->update(mousePos); }
}

void MainMenuState::handleInput()
{

}

void MainMenuState::draw()
{
	for (int i = 0; i < this->itemList.size(); i++) { this->itemList.at(i)->draw(); }
}

MainMenuState::~MainMenuState()
{

}