#pragma once
#include "GameState.h"
#include "Window.h"
#include "ResourceHandler.h"

class PlayState : public GameState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<ResourceHandler> resourceHandler;

public:
	PlayState(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler);
	~PlayState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};