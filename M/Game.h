#pragma once
#include "Window.h"
#include "Settings.h"
#include "ResourceHandler.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include <iostream>

class Game
{
private:
	std::shared_ptr<Window> window;
	bool running;
	sf::Text fpsText;
	std::shared_ptr<Settings> settings;
	std::shared_ptr<ResourceHandler> resourceHandler;
	std::unique_ptr<GameState> currentGameState;
	enum allStates { MAINMENU, SETTINGS, LOAD, PLAY };

public:
	Game(std::shared_ptr<Settings> settings, std::shared_ptr<ResourceHandler> resourceHandler);
	~Game();
	void update();
	void draw();
	std::shared_ptr<Window> &getWindow(){ return this->window; }
	bool isRunning() { return this->running; }
	void checkStateChange();
};