#include "PlayState.h"

PlayState::PlayState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->stateChange = "";
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->currentViewState = std::make_shared<MainViewState>(this->window, this->assetsHandler);
}

void PlayState::update()
{
	this->currentViewState->update();
}

void PlayState::handleInput()
{
	this->currentViewState->handleInput();
}

void PlayState::draw()
{
	this->currentViewState->draw();
}

PlayState::~PlayState()
{

}