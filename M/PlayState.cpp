#include "PlayState.h"

PlayState::PlayState(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler)
{
	this->stateChange = "";
	this->window = window;
	this->resourceHandler = resourceHandler;
}

void PlayState::update()
{

}

void PlayState::handleInput()
{

}

void PlayState::draw()
{

}

PlayState::~PlayState()
{

}