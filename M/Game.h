#pragma once
#include "Window.h"
#include "Settings.h"
#include "ResourceHandler.h"
#include "GameState.h"
#include "MainMenuState.h"

class Game
{
private:
	std::shared_ptr<Window> window;
	bool running;
	sf::Text fpsText;
	std::shared_ptr<Settings> settings;
	std::shared_ptr<ResourceHandler> resourceHandler;
	std::shared_ptr<GameState> currentGameState;

public:
	Game(std::shared_ptr<Settings> settings, std::shared_ptr<ResourceHandler> resourceHandler);
	~Game();
	void update();
	void draw();
	std::shared_ptr<Window> &getWindow(){ return this->window; }
	bool isRunning() { return this->running; }
};