#pragma once
#include "GameState.h"
#include "Settings.h"
#include "Window.h"
#include "MenuItem.h"
#include "AssetsHandler.h"
#include "PlayState.h"
#include "TextInputField.h"
#include "ResourceModifier.h"
#include "Button.h"

class SetupState : public GameState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<PlayState> playState;

	sf::Text inputLabelText;
	sf::Text signatureText;
	std::shared_ptr<TextInputField> nameInputField;
	std::shared_ptr<Button> singButton;

	sf::Sprite presidentialOrderSprite;

public:
	SetupState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<PlayState> playState);
	~SetupState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
	std::shared_ptr<TextInputField> getNameInputField() { return this->nameInputField; }
};