#pragma once
#include "GameState.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "ViewState.h"
#include "MainViewState.h"
#include "PauseViewState.h"
#include "TurnManager.h"
#include "FlagManager.h"
#include "ResourceManager.h"
#include "InfluenceResource.h"
#include "NationalStability.h"
#include "Government.h"

class PlayState : public GameState
{
private:
	std::string stateChange;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<TurnManager> turnManager;
	std::shared_ptr<FlagManager> flagManager;
	std::shared_ptr<ResourceManager> resourceManager;

	std::shared_ptr<Government> government;

	std::shared_ptr<ViewState> currentViewState;
	std::shared_ptr<ViewState> mainViewState;
	std::shared_ptr<ViewState> pauseViewState;

public:
	PlayState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~PlayState();
	void update();
	void handleInput();
	void draw();
	std::string getStateChange() { return stateChange; }
	void setStateChange(std::string val) { this->stateChange = val; }
	void checkStateChange();

	std::shared_ptr<ResourceManager> getResourceManager() { return this->resourceManager; }
	std::shared_ptr<FlagManager> getFlagManager() { return this->flagManager; }
	std::shared_ptr<TurnManager> getTurnManager() { return this->turnManager; }
	std::shared_ptr<ViewState> getMainViewState() { return this->mainViewState; }

	std::shared_ptr<Government> getGovernment() { return this->government; }
};