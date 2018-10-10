#pragma once
#include "ViewState.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "Button.h"

class PauseViewState : public ViewState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

	std::shared_ptr<Button> mainMenuButton;
	std::shared_ptr<Button> exitButton;
	std::shared_ptr<Button> saveButton;
	std::shared_ptr<Button> backButton;

public:
	PauseViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~PauseViewState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
	void setStateChange(std::string state) { this->stateChange = state; }
};