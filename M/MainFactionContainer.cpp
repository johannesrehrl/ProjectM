#include "MainFactionContainer.h"
#define LOCAL_X ((float)this->window->getDesktop().front().width / 100) * 2.5
#define LOCAL_Y ((float)this->window->getDesktop().front().height / 100) * 5
#define CARD_SIZE 120

MainFactionContainer::MainFactionContainer(std::shared_ptr<Government> government,std::shared_ptr<AssetsHandler> assetsHandler,
	std::shared_ptr<Window> window, std::shared_ptr<Cursor> cursor)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->government = government;
	this->cursor = cursor;

	this->body.setSize(sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 20,
		((float)this->window->getDesktop().front().height / 100) * 90));
	this->bodyShadow.setSize(sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 20 - 10,
		((float)this->window->getDesktop().front().height / 100) * 90 - 10));
	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
	this->bodyShadow.setFillColor(this->assetsHandler->getColorHolder()["grey30"]);
	this->body.setPosition(LOCAL_X, LOCAL_Y);
	this->bodyShadow.setPosition(LOCAL_X + 20, LOCAL_Y + 20);

	this->headline.setFont(this->assetsHandler->getFontHolder()["squares-bold"]);
	this->headline.setCharacterSize(25);
	this->headline.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->headline.setString("Ministries and \nFactions");
	this->headline.setPosition(LOCAL_X + 20, LOCAL_Y + 20);

	this->financeMinistryCard = std::make_shared<MinistryCard>(this->government->getFinanceMinistry(),
		sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 20, 115),
		sf::Vector2f(LOCAL_X, LOCAL_Y + CARD_SIZE), this->window, this->assetsHandler);

	this->defenceMinistryCard = std::make_shared<MinistryCard>(this->government->getDefenceMinistry(),
		sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 20, 115),
		sf::Vector2f(LOCAL_X, LOCAL_Y + CARD_SIZE * 2), this->window, this->assetsHandler);
}

void MainFactionContainer::updateEndTurn()
{
	this->financeMinistryCard->updateEndTurn();
	this->defenceMinistryCard->updateEndTurn();
}

void MainFactionContainer::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	this->financeMinistryCard->update(mousePos);
	this->defenceMinistryCard->update(mousePos);
}

void MainFactionContainer::draw()
{
	this->window->getWindow()->draw(bodyShadow);
	this->window->getWindow()->draw(body);
	this->window->getWindow()->draw(headline);
	this->financeMinistryCard->draw();
	this->defenceMinistryCard->draw();
}

MainFactionContainer::~MainFactionContainer()
{

}