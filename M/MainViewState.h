#pragma once
#include "ViewState.h"
#include "Window.h"
#include "ResourceHandler.h"

class MainViewState : public ViewState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<ResourceHandler> resourceHandler;

public:
	MainViewState(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler);
	~MainViewState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};