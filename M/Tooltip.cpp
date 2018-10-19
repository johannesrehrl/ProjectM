#include "Tooltip.h"
#define OUTLINE 3

Tooltip::Tooltip(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, sf::Text text, sf::Vector2f pos)
{
	this->display = false;
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->text = text;

	this->body.setSize(sf::Vector2f(this->text.getGlobalBounds().width + 10, this->text.getGlobalBounds().height + 10));
	this->body.setPosition(OUTLINE, OUTLINE);
	this->body.setOutlineThickness(OUTLINE);
	this->body.setOutlineColor(this->assetsHandler->getColorHolder()["black"]);
	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);

	this->text.setPosition(5 + OUTLINE, 5 + OUTLINE);

	this->texture.create(this->body.getSize().x + OUTLINE * 2, this->body.getSize().y + OUTLINE * 2);
	this->texture.draw(this->body);
	this->texture.draw(this->text);
	this->texture.display();

	this->sprite.setTexture(this->texture.getTexture());

	if (pos.x + this->sprite.getGlobalBounds().width <= this->window->getDesktop().front().width)
	{
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width, this->sprite.getOrigin().y);
	}

	else
	{
		this->sprite.setOrigin(0, this->sprite.getOrigin().y);
	}

	if (pos.y + this->sprite.getGlobalBounds().height <= this->window->getDesktop().front().height)
	{
		this->sprite.setOrigin(this->sprite.getOrigin().x, this->sprite.getGlobalBounds().height);
	}

	else
	{
		this->sprite.setOrigin(this->sprite.getOrigin().x, 0);
	}

	this->sprite.setPosition(pos);
}

void Tooltip::setText(sf::Text text, sf::Vector2f pos)
{
	this->text = text;

	this->body.setSize(sf::Vector2f(this->text.getGlobalBounds().width + 10, this->text.getGlobalBounds().height + 10));
	this->body.setPosition(OUTLINE, OUTLINE);
	this->text.setPosition(5 + OUTLINE, 5 + OUTLINE);

	this->texture.create(this->body.getSize().x + OUTLINE * 2, this->body.getSize().y + OUTLINE * 2);
	this->texture.draw(this->body);
	this->texture.draw(this->text);
	this->texture.display();

	this->sprite.setTexture(this->texture.getTexture());

	if (pos.x + this->sprite.getGlobalBounds().width <= this->window->getDesktop().front().width)
	{
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width, this->sprite.getOrigin().y);
	}

	else
	{
		this->sprite.setOrigin(0, this->sprite.getOrigin().y);
	}

	if (pos.y + this->sprite.getGlobalBounds().height <= this->window->getDesktop().front().height)
	{
		this->sprite.setOrigin(this->sprite.getOrigin().x, this->sprite.getGlobalBounds().height);
	}

	else
	{
		this->sprite.setOrigin(this->sprite.getOrigin().x, 0);
	}

	this->sprite.setPosition(pos);
}

void Tooltip::update()
{

}

void Tooltip::draw()
{
	this->window->getWindow()->draw(this->sprite);
}

Tooltip::~Tooltip()
{

}