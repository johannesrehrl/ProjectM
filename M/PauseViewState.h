#pragma once
#include "ViewState.h"
#include "Window.h"
#include "ResourceHandler.h"

class PauseViewState : public ViewState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<ResourceHandler> resourceHandler;
public:
	PauseViewState(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler);
	~PauseViewState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};