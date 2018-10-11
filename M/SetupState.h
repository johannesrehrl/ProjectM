#pragma once
#include "GameState.h"
#include "Settings.h"
#include "Window.h"
#include "MenuItem.h"
#include "AssetsHandler.h"
#include "PlayState.h"
#include "TextInputField.h"
#include "ResourceModifier.h"

class SetupState : public GameState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<PlayState> playState;

	std::shared_ptr<TextInputField> nameInputField;

public:
	SetupState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<PlayState> playState);
	~SetupState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
};