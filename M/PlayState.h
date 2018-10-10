#pragma once
#include "GameState.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "ViewState.h"
#include "MainViewState.h"

class PlayState : public GameState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<ViewState> currentViewState;

public:
	PlayState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~PlayState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};