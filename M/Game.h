#pragma once
#include "Window.h"
#include "Settings.h"
#include "AssetsHandler.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "SetupState.h"
#include <iostream>

class Game
{
private:
	std::shared_ptr<Window> window;
	bool running;
	sf::Text fpsText;
	std::shared_ptr<Settings> settings;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<GameState> currentGameState;
	std::shared_ptr<PlayState> playState;
	enum allStates { MAINMENU, SETTINGS, LOAD, PLAY };

public:
	Game(std::shared_ptr<Settings> settings, std::shared_ptr<AssetsHandler> assetsHandler);
	~Game();
	void update();
	void draw();
	std::shared_ptr<Window> &getWindow(){ return this->window; }
	bool isRunning() { return this->running; }
	void checkStateChange();
};