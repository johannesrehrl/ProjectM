#include "MainViewState.h"

MainViewState::MainViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler,
	std::shared_ptr<TurnManager> turnManager, std::shared_ptr<FlagManager> flagManager, std::shared_ptr<ResourceManager> resourceManager,
	std::shared_ptr<Government> government)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->turnManager = turnManager;
	this->flagManager = flagManager;
	this->resourceManager = resourceManager;
	this->government = government;

	this->stateChange = "";

	this->mainStatisticsContainer = std::make_shared<MainStatisticsContainer>(this->window, this->assetsHandler, this->turnManager, 
		this->resourceManager, this->government);
	this->mainEventContainer = std::make_shared<MainEventContainer>(this->window, this->assetsHandler);
	this->mainFactionContainer = std::make_shared<MainFactionContainer>(this->government, this->assetsHandler, this->window);

	this->nextTurnButton = std::make_shared<Button>(assetsHandler, window, "Next Turn", Button::style::NEXT_TURN, 
		sf::Vector2f(((float) this->window->getDesktop().front().width / 100) * 87.5, ((float)this->window->getDesktop().front().height / 100) * 85));
	this->nextTurnButton->setOnSelect([turnManager] {
		turnManager->endTurn();
	});
}

void MainViewState::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	this->nextTurnButton->update(mousePos);
	this->mainFactionContainer->update();
}

void MainViewState::updateEndTurn()
{
	this->mainStatisticsContainer->updateEndTurn();
	this->mainEventContainer->updateEndTurn();
	this->mainFactionContainer->updateEndTurn();
}


void MainViewState::handleInput()
{
	if (this->assetsHandler->getActionMap().isActive("escapeRelease"))
	{
		this->stateChange = "PAUSE";
	}
}

void MainViewState::draw()
{
	this->mainStatisticsContainer->draw();
	this->mainEventContainer->draw();
	this->mainFactionContainer->draw();

	this->nextTurnButton->draw();
}

MainViewState::~MainViewState()
{

}