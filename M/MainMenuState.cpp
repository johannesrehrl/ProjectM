#include "MainMenuState.h"

MainMenuState::MainMenuState(std::shared_ptr<Settings> settings, std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler)
{
	this->settings = settings;
	this->window = window;
	this->resourceHandler = resourceHandler;

	this->itemList.push_back(std::make_shared<MenuItem>
		(this->resourceHandler, "Start", sf::Vector2i(100, this->window->getDesktop().front().height - 300)));

	this->itemList.push_back(std::make_shared<MenuItem>
		(this->resourceHandler, "Setting", sf::Vector2i(100, this->window->getDesktop().front().height - 240)));

	this->itemList.push_back(std::make_shared<MenuItem>
		(this->resourceHandler, "Load", sf::Vector2i(100, this->window->getDesktop().front().height - 180)));

	this->itemList.push_back(std::make_shared<MenuItem>(
		this->resourceHandler, "Exit", sf::Vector2i(100, this->window->getDesktop().front().height - 120)));
	this->itemList.at(3)->setOnSelect([window] {
		window->getWindow()->close();
	});
}

void MainMenuState::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	for (int i = 0; i < this->itemList.size(); i++){ this->itemList.at(i)->update(mousePos, this->window->getFps()); }
}

void MainMenuState::handleInput()
{
	if (this->resourceHandler->getActionMap().isActive("leftRelease"))
	{
		for (int i = 0; i < this->itemList.size(); i++)
		{
			if (this->itemList.at(i)->isSelected())
			{
				this->itemList.at(i)->fireOnSelect();
			}
		}
	}
}

void MainMenuState::draw()
{
	for (int i = 0; i < this->itemList.size(); i++) { this->itemList.at(i)->draw(this->window->getWindow()); }
}

MainMenuState::~MainMenuState()
{

}