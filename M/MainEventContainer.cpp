#include "MainEventContainer.h"
#define LOCAL_X ((float)this->window->getDesktop().front().width / 100) * 25
#define LOCAL_Y ((float)this->window->getDesktop().front().height / 100) * 5

MainEventContainer::MainEventContainer(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Cursor> cursor)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->cursor = cursor;

	this->body.setSize(sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 50, 
		((float)this->window->getDesktop().front().height / 100) * 90));
	this->bodyShadow.setSize(sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 50 - 10, 
		((float)this->window->getDesktop().front().height / 100) * 90 - 10));
	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
	this->bodyShadow.setFillColor(this->assetsHandler->getColorHolder()["grey30"]);
	this->body.setPosition(LOCAL_X, LOCAL_Y);
	this->bodyShadow.setPosition(LOCAL_X + 20, LOCAL_Y + 20);

	this->headline.setFont(this->assetsHandler->getFontHolder()["squares-bold"]);
	this->headline.setCharacterSize(25);
	this->headline.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->headline.setString("Events and Notifications");
	this->headline.setPosition(LOCAL_X + 20, LOCAL_Y + 20);
}

void MainEventContainer::updateEndTurn()
{

}

void MainEventContainer::draw()
{
	this->window->getWindow()->draw(bodyShadow);
	this->window->getWindow()->draw(body);
	this->window->getWindow()->draw(headline);
}

MainEventContainer::~MainEventContainer()
{

}