#include "PlayState.h"

PlayState::PlayState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->stateChange = "";
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->flagManager = std::make_shared<FlagManager>();
	this->turnManager = std::make_shared<TurnManager>(this->flagManager);
	this->resourceManager = std::make_shared<ResourceManager>(std::make_shared<InfluenceResource>(5), std::make_shared<NationalStability>());

	this->mainViewState = std::make_shared<MainViewState>(this->window, this->assetsHandler, this->turnManager, this->flagManager, this->resourceManager);
	this->pauseViewState = std::make_shared<PauseViewState>(this->window, this->assetsHandler);
	this->currentViewState = this->mainViewState;
}

void PlayState::update()
{
	this->currentViewState->update();
	this->checkStateChange();
	this->turnManager->update();

	if (this->flagManager->doesFlagExist("end_turn"))
	{
		if (this->flagManager->getFlag("end_turn")->isActive())
		{
			this->resourceManager->updateEndTurn();

			this->mainViewState->updateEndTurn();
			this->pauseViewState->updateEndTurn();

			this->flagManager->getFlag("end_turn")->setActive(false);
		}
	}
}

void PlayState::handleInput()
{
	this->currentViewState->handleInput();
}

void PlayState::draw()
{
	this->currentViewState->draw();
}

void PlayState::checkStateChange()
{
	if (this->currentViewState->getStateChange() == "PAUSE")
	{
		this->currentViewState->setStateChange("");
		this->currentViewState.reset();
		this->currentViewState = this->pauseViewState;
	}

	if (this->currentViewState->getStateChange() == "MAIN")
	{
		this->currentViewState->setStateChange("");
		this->currentViewState.reset();
		this->currentViewState = this->mainViewState;
	}

	if (this->currentViewState->getStateChange() == "TOP:MAINMENU")
	{
		this->stateChange = "MAINMENU";
	}

	if (this->currentViewState->getStateChange() == "TOP:SAVE")
	{
		//this->stateChange = "SAVE";
	}
}

PlayState::~PlayState()
{

}