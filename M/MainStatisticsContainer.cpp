#include "MainStatisticsContainer.h"
#define LOCAL_X ((float)this->window->getDesktop().front().width / 100) * 77.5
#define LOCAL_Y ((float)this->window->getDesktop().front().height / 100) * 5

MainStatisticsContainer::MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler,
	std::shared_ptr<TurnManager> turnManager, std::shared_ptr<ResourceManager> resourceManager)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->turnManager = turnManager;
	this->resourceManager = resourceManager;

	this->body.setSize(sf::Vector2f(((float) this->window->getDesktop().front().width / 100) * 20, ((float) this->window->getDesktop().front().height / 100) * 70));
	this->bodyShadow.setSize(sf::Vector2f(((float) this->window->getDesktop().front().width / 100) * 20 - 10, ((float) this->window->getDesktop().front().height / 100) * 70 - 10));
	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
	this->bodyShadow.setFillColor(this->assetsHandler->getColorHolder()["grey30"]);
	this->body.setPosition(LOCAL_X, LOCAL_Y);
	this->bodyShadow.setPosition(LOCAL_X + 20, LOCAL_Y + 20);

	this->headline.setFont(this->assetsHandler->getFontHolder()["squares-bold"]);
	this->headline.setCharacterSize(25);
	this->headline.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->headline.setString("National Statistics");
	this->headline.setPosition(LOCAL_X + 20, LOCAL_Y + 20);

	this->dateText.setFont(this->assetsHandler->getFontHolder()["aquifer"]);
	this->dateText.setCharacterSize(20);
	this->dateText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->dateText.setString(this->turnManager->getDate());
	this->dateText.setPosition(LOCAL_X + 20, LOCAL_Y + 60);

	this->influenceText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->influenceText.setCharacterSize(20);
	this->influenceText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->influenceText.setString("Influence: " + std::to_string((int)this->resourceManager->getInfluenceResource()->getInfluence()));
	this->influenceText.setPosition(LOCAL_X + 20, LOCAL_Y + 100);

	this->stabilityText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->stabilityText.setCharacterSize(20);
	this->stabilityText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->stabilityText.setString("Stability: " + std::to_string((int)this->resourceManager->getNationalStability()->getStability()) + "%");
	this->stabilityText.setPosition(LOCAL_X + 20, LOCAL_Y + 125);
}

void MainStatisticsContainer::updateEndTurn()
{
	this->dateText.setString(this->turnManager->getDate());
	this->influenceText.setString("Influence: " + std::to_string((int)this->resourceManager->getInfluenceResource()->getInfluence()));
	this->stabilityText.setString("Stability: " + std::to_string((int)this->resourceManager->getNationalStability()->getStability()) + "%");
}

void MainStatisticsContainer::draw()
{
	this->window->getWindow()->draw(bodyShadow);
	this->window->getWindow()->draw(body);
	this->window->getWindow()->draw(headline);
	this->window->getWindow()->draw(dateText);
	this->window->getWindow()->draw(influenceText);
	this->window->getWindow()->draw(stabilityText);
}

MainStatisticsContainer::~MainStatisticsContainer()
{

}