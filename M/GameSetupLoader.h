#pragma once
#include <nlohmann\json.hpp>
#include <fstream>
#include "PlayState.h"
#include "Minister.h"

class GameSetupLoader
{
private:
	std::shared_ptr<PlayState> playState;
	std::ifstream loadingStream;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

public:
	GameSetupLoader(std::shared_ptr<PlayState> playState, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~GameSetupLoader();

	void load(); 
	void loadMinisters();
	void loadEvents();
};