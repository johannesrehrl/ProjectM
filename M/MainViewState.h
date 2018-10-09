#pragma once
#include "ViewState.h"
#include "Window.h"
#include "ResourceHandler.h"
#include "MainStatisticsContainer.h" 

class MainViewState : public ViewState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<ResourceHandler> resourceHandler;
	std::shared_ptr<MainStatisticsContainer> mainStatisticsContainer;

public:
	MainViewState(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler);
	~MainViewState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};