#include <iostream>
#include "Game.h"
#include "Settings.h"
#include "AssetsHandler.h"
#include <fstream>

int main()
{
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