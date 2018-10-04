#pragma once
#include "GameState.h"
#include "Settings.h"
#include "Window.h"
#include "MenuItem.h"
#include "ResourceHandler.h"
#include <vector>

class MainMenuState : public GameState
{
private:
	std::string stateChange;
	std::shared_ptr<Settings> settings;
	std::shared_ptr<Window> window;
	std::shared_ptr<ResourceHandler> resourceHandler;
	std::vector<std::shared_ptr<MenuItem>> itemList;

public:
	MainMenuState(std::shared_ptr<Settings> settings, std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler);
	~MainMenuState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};