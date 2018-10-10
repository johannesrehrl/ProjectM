#pragma once
#include "ViewState.h"
#include "Window.h"
#include "AssetsHandler.h"

class PauseViewState : public ViewState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
public:
	PauseViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~PauseViewState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};