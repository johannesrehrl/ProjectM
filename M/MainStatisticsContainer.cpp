#include "MainStatisticsContainer.h"
#define LOCAL_X ((float)this->window->getDesktop().front().width / 100) * 77.5
#define LOCAL_Y ((float)this->window->getDesktop().front().height / 100) * 5

MainStatisticsContainer::MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler,
	std::shared_ptr<TurnManager> turnManager, std::shared_ptr<ResourceManager> resourceManager, std::shared_ptr<Player> player)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->turnManager = turnManager;
	this->resourceManager = resourceManager;
	this->player = player;

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

	this->presidentNameText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->presidentNameText.setCharacterSize(20);
	this->presidentNameText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->presidentNameText.setString("President: " + this->player->getName());
	this->presidentNameText.setPosition(LOCAL_X + 20, LOCAL_Y + 100);

	this->influenceText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->influenceText.setCharacterSize(20);
	this->influenceText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->influenceText.setString(std::to_string((int)this->resourceManager->getInfluenceResource()->getInfluence()) + " " + 
		std::to_string((int)this->resourceManager->getInfluenceResource()->getEndTurnChange()));
	this->influenceText.setPosition(LOCAL_X + 50, LOCAL_Y + 130);

	this->stabilityText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->stabilityText.setCharacterSize(20);
	this->stabilityText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->stabilityText.setString(std::to_string((int)this->resourceManager->getNationalStability()->getStability()) + "%");
	this->stabilityText.setPosition(LOCAL_X + 50, LOCAL_Y + 160);

	this->influenceSprite.setTexture(this->assetsHandler->getTextureHolder()["influence-icon"]);
	this->influenceSprite.setPosition(LOCAL_X + 20, LOCAL_Y + 130 + 2);

	this->stabilitySprite.setTexture(this->assetsHandler->getTextureHolder()["stability-icon"]);
	this->stabilitySprite.setPosition(LOCAL_X + 20, LOCAL_Y + 160 + 2);
}

void MainStatisticsContainer::updateEndTurn()
{
	this->dateText.setString(this->turnManager->getDate());
	this->presidentNameText.setString("President: " + this->player->getName());
	this->stabilityText.setString(std::to_string((int)this->resourceManager->getNationalStability()->getStability()) + "%");

	if (this->resourceManager->getInfluenceResource()->getEndTurnChange() < 0)
	{
		this->influenceText.setFillColor(this->assetsHandler->getColorHolder()["red215"]);
		this->influenceText.setString(std::to_string((int)this->resourceManager->getInfluenceResource()->getInfluence()) + "" +
			std::to_string((int)this->resourceManager->getInfluenceResource()->getEndTurnChange()));
	}

	else
	{
		this->influenceText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
		this->influenceText.setString(std::to_string((int)this->resourceManager->getInfluenceResource()->getInfluence()) + "+" +
			std::to_string((int)this->resourceManager->getInfluenceResource()->getEndTurnChange()));
	}
}

void MainStatisticsContainer::draw()
{
	this->window->getWindow()->draw(bodyShadow);
	this->window->getWindow()->draw(body);
	this->window->getWindow()->draw(headline);
	this->window->getWindow()->draw(dateText);
	this->window->getWindow()->draw(presidentNameText);
	this->window->getWindow()->draw(influenceText);
	this->window->getWindow()->draw(stabilityText);
	this->window->getWindow()->draw(influenceSprite);
	this->window->getWindow()->draw(stabilitySprite);
}

MainStatisticsContainer::~MainStatisticsContainer()
{

}