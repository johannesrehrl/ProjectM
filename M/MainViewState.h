#pragma once
#include "ViewState.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "MainStatisticsContainer.h" 
#include "MainEventContainer.h" 
#include "MainFactionContainer.h" 
#include "Button.h" 
#include "TurnManager.h" 
#include "FlagManager.h" 
#include "Flag.h" 
#include "ResourceManager.h" 

class MainViewState : public ViewState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<TurnManager> turnManager;
	std::shared_ptr<FlagManager> flagManager;
	std::shared_ptr<ResourceManager> resourceManager;

	std::shared_ptr<MainStatisticsContainer> mainStatisticsContainer;
	std::shared_ptr<MainEventContainer> mainEventContainer;
	std::shared_ptr<MainFactionContainer> mainFactionContainer;

	std::shared_ptr<Button> nextTurnButton;

public:
	MainViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<TurnManager> turnManager,
		std::shared_ptr<FlagManager> flagManager, std::shared_ptr<ResourceManager> resourceManager);
	~MainViewState();
	void update();
	void updateEndTurn();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
	void setStateChange(std::string state) { this->stateChange = state; }
};