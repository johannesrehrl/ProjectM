#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHandler.h"

class Window {
private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<ResourceHandler> resourceHandler;
	std::vector<sf::VideoMode> desktop;
	float fps;
	bool focus;
	float deltaTime;
	sf::Clock clock;
	sf::String title;

public:
	Window(sf::String title, std::shared_ptr<ResourceHandler> resourceHandler);
	~Window();
	std::shared_ptr<sf::RenderWindow> getWindow() { return this->window; }
	bool isFocused() { return focus; }
	bool isRunning() { return this->window->isOpen(); }
	float getFps() { return fps; }
	float getDeltaTime() { return deltaTime; }
	std::vector<sf::VideoMode> getDesktop() { return desktop; }
	void update();
};