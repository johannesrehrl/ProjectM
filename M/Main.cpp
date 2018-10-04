#include "Game.h"
#include "Settings.h"
#include "ResourceHandler.h"

int main()
{
	std::shared_ptr<Settings> settings = std::make_shared<Settings>();
	std::shared_ptr<ResourceHandler> resourceHandler = std::make_shared<ResourceHandler>();
	std::shared_ptr<Game> game = std::make_shared<Game>(settings, resourceHandler);

	while (game->isRunning())
	{
		game->update();
		game->draw();
		game->checkStateChange();
	}

    return 0;
}