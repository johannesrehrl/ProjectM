#include "MinistryCard.h"

MinistryCard::MinistryCard(std::shared_ptr<Ministry> ministry, sf::Vector2f size, sf::Vector2f pos,
	std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->ministry = ministry;
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->body.setPosition(pos);
	this->body.setSize(size);
	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
}

void MinistryCard::update(sf::Vector2i mousePos)
{
	if (this->body.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		this->body.setFillColor(this->assetsHandler->getColorHolder()["grey185"]);
	}

	else
	{
		this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
	}
}

void MinistryCard::updateEndTurn()
{

}

void MinistryCard::draw()
{
	this->window->getWindow()->draw(body);
}

MinistryCard::~MinistryCard()
{

}