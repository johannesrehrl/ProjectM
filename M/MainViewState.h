#pragma once
#include "ViewState.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "MainStatisticsContainer.h" 
#include "MainEventContainer.h" 
#include "MainFactionContainer.h" 

class MainViewState : public ViewState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<MainStatisticsContainer> mainStatisticsContainer;
	std::shared_ptr<MainEventContainer> mainEventContainer;
	std::shared_ptr<MainFactionContainer> mainFactionContainer;

public:
	MainViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~MainViewState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};