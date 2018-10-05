#include "MenuItem.h"
#define RECT_LENGTH 50
#define RECT_TEXT_DIFF 10
#define MOVE_BY_SEC 400

MenuItem::MenuItem(std::shared_ptr<ResourceHandler> resourceHandler, std::string text, sf::Vector2i pos)
{
	this->resourceHandler = resourceHandler;
	this->text.setFont(this->resourceHandler->getFontHolder()["squares-bold"]);
	this->text.setString(text);
	this->text.setCharacterSize(40);
	this->text.setFillColor(sf::Color::Black);
	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(0, textRect.top + textRect.height / 2.0f);
	this->text.setPosition(pos.x, pos.y);

	this->rect.setFillColor(sf::Color::Black);
	this->rect.setSize(sf::Vector2f(0,10));
	this->rect.setOrigin(0,5);
	this->rect.setPosition(pos.x - RECT_TEXT_DIFF, pos.y);

	this->hitBox.setSize(sf::Vector2f(this->rect.getSize().x + 15 + textRect.width, 40));
	this->hitBox.setOrigin(0, 20);
	this->hitBox.setPosition(pos.x, pos.y);

	this->posX = pos.x;

	this->selected = false;
}

void MenuItem::update(sf::Vector2i mousePos, int fps)
{
	if (!active && this->text.getFillColor() != this->resourceHandler->getColorHolder()["grey"])
	{
		this->text.setFillColor(this->resourceHandler->getColorHolder()["grey"]);
		return;
	} else if (!active) return;

	this->hitBox.setSize(sf::Vector2f(this->rect.getSize().x + 20 + this->text.getLocalBounds().width, 50));
	if (this->hitBox.getGlobalBounds().contains((float) mousePos.x, (float) mousePos.y))
	{
		if (this->rect.getSize().x < RECT_LENGTH)
		{
			this->rect.setSize(sf::Vector2f(this->rect.getSize().x + (MOVE_BY_SEC / fps), this->rect.getSize().y));
			this->text.setPosition(this->text.getPosition().x + (MOVE_BY_SEC / fps), this->text.getPosition().y);
		}

		if (this->rect.getSize().x > RECT_LENGTH)
		{
			this->rect.setSize(sf::Vector2f(RECT_LENGTH, this->rect.getSize().y));
			this->text.setPosition(RECT_LENGTH + posX, this->text.getPosition().y);
		}

		this->selected = true;
	}

	else
	{
		if (this->rect.getSize().x > 0)
		{
			this->rect.setSize(sf::Vector2f(this->rect.getSize().x - (MOVE_BY_SEC / fps), this->rect.getSize().y));
			this->text.setPosition(this->text.getPosition().x - (MOVE_BY_SEC / fps), this->text.getPosition().y);
		}

		if (this->rect.getSize().x < 0 || this->text.getPosition().x < posX)
		{
			this->rect.setSize(sf::Vector2f(0, this->rect.getSize().y));
			this->text.setPosition(posX, this->text.getPosition().y);
		}

		this->selected = false;
	}

	if (this->onSelect == NULL)
	{
		this->active = false;
	}
}

void MenuItem::draw(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(this->text);
	window->draw(this->rect);
}

void MenuItem::fireOnSelect()
{
	this->onSelect();
}

MenuItem::~MenuItem()
{
	
}
