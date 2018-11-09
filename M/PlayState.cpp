#include "PlayState.h"

PlayState::PlayState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Cursor> cursor)
{
	this->stateChange = "";
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->cursor = cursor;
	this->flagManager = std::make_shared<FlagManager>();
	this->turnManager = std::make_shared<TurnManager>(this->flagManager);
	this->resourceManager = std::make_shared<ResourceManager>(std::make_shared<InfluenceResource>(5, this->window, this->assetsHandler),
		std::make_shared<NationalStability>(this->window, this->assetsHandler));
	this->eventManager = std::make_shared<EventManager>();

	this->government = std::make_shared<Government>(this->window, this->assetsHandler);

	this->mainViewState = std::make_shared<MainViewState>(this->window, this->assetsHandler, this->turnManager, this->flagManager, 
		this->resourceManager, this->government, this->cursor);
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
			this->updateEndTurn();
			this->flagManager->updateEndTurn();
			this->eventManager->updateEndTurn(this->turnManager->getMonth(), this->turnManager->getYear());

			this->flagManager->getFlag("end_turn")->setActive(false);
		}
	}
}
void PlayState::updateEndTurn()
{
	this->government->updateEndTurn();
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