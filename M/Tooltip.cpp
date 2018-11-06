#include "Tooltip.h"

Tooltip::Tooltip(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey180"]);
	this->body.setOutlineThickness(-3);
	this->body.setOutlineColor(this->assetsHandler->getColorHolder()["black"]);

	this->headLineText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->headLineText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->headLineText.setCharacterSize(20);
	this->headLineText.setPosition(10, 10);
	this->headLineText.setString("");
}

void Tooltip::updateTexture()
{
	this->tex.reset();
	this->tex = std::make_shared<sf::RenderTexture>();
	this->tex->create(250, 40 + ((this->allLines.size() * 25) + 5));
	this->body.setSize(sf::Vector2f(250, 40 + ((this->allLines.size() * 25) + 5)));
	this->body.setOutlineThickness(-3);
	this->tex->draw(this->body);
	this->tex->draw(this->headLineText);
	for (int i = 0; i < this->allLines.size(); i++)
	{
		this->tex->draw(this->allLines.at(i));
	}
	this->tex->display();
	this->sprite.setTexture(this->tex->getTexture(), true);
}

void Tooltip::draw()
{
	this->window->getWindow()->draw(sprite);
}

void Tooltip::addLine(std::string lineString)
{
	sf::Text text;
	text.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	text.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	text.setCharacterSize(15);
	text.setString(lineString);
	text.setPosition(10, 40 + (this->allLines.size() * 25));

	this->allLines.push_back(text);

	this->updateTexture();
}

void Tooltip::setPosition(sf::Vector2i pos)
{
	this->sprite.setPosition(pos.x, pos.y);

	if (this->sprite.getGlobalBounds().width + pos.x > this->window->getDesktop().front().width)
	{
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width, this->sprite.getOrigin().y);
	}

	else
	{
		this->sprite.setOrigin(0, this->sprite.getOrigin().y);
	}

	if (this->sprite.getGlobalBounds().height + pos.y > this->window->getDesktop().front().height)
	{
		this->sprite.setOrigin(this->sprite.getOrigin().x, this->sprite.getGlobalBounds().height);
	}

	else
	{
		this->sprite.setOrigin(this->sprite.getOrigin().x, 0);
	}
}

Tooltip::~Tooltip()
{

}