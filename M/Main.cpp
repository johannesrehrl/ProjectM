#include <nlohmann\json.hpp>
#include <iostream>
#include "Game.h"
#include "Settings.h"
#include "AssetsHandler.h"

using json = nlohmann::json;

int main()
{
	// create an empty structure (null)
	json j;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j["pi"] = 3.141;

	std::shared_ptr<Settings> settings = std::make_shared<Settings>();
	std::shared_ptr<AssetsHandler> assetsHandler = std::make_shared<AssetsHandler>();
	std::shared_ptr<Game> game = std::make_shared<Game>(settings, assetsHandler);

	while (game->isRunning())
	{
		game->update();
		game->draw();
		game->checkStateChange();
	}

    return 0;
}