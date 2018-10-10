#pragma once
#include "GameState.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "ViewState.h"
#include "MainViewState.h"
#include "PauseViewState.h"

class PlayState : public GameState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

	std::shared_ptr<ViewState> currentViewState;
	std::shared_ptr<ViewState> mainViewState;
	std::shared_ptr<ViewState> pauseViewState;

public:
	PlayState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~PlayState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
	void checkStateChange();
};