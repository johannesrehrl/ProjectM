#include "Window.h"

Window::Window(sf::String title, std::shared_ptr<ResourceHandler> resourceHandler)
{
	this->resourceHandler = resourceHandler;
	this->title = title;
	this->desktop = sf::VideoMode::getFullscreenModes();
	this->window = std::make_shared<sf::RenderWindow>(desktop.front(), this->title, sf::Style::Fullscreen);
	this->window->setActive(true);
	this->window->clear();
	this->focus = this->window->hasFocus();
}

void Window::update()
{
	this->deltaTime = this->clock.restart().asSeconds();
	this->fps = 1 / deltaTime;

	this->resourceHandler->getActionMap().update(*(this->window));

	if (this->resourceHandler->getActionMap().isActive("closedWindow")) 
	{
		this->window->close();
	}

	if (this->resourceHandler->getActionMap().isActive("gainedFocus"))
	{
		focus = true;
	}

	if (this->resourceHandler->getActionMap().isActive("lostFocus"))
	{
		focus = false;
	}
}

Window::~Window()
{

}