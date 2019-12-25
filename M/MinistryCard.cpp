#include "MinistryCard.h"

MinistryCard::MinistryCard(std::shared_ptr<Ministry> ministry, sf::Vector2f size, sf::Vector2f pos, std::shared_ptr<Window> window,
	std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Cursor> cursor)
{
	this->ministry = ministry;
	this->window = window;
	this->cursor = cursor;
	this->assetsHandler = assetsHandler;
	this->cursor = cursor;

	this->body.setPosition(pos);
	this->body.setSize(size);
	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);

	this->nameText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->nameText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->nameText.setCharacterSize(20);
	this->nameText.setString(this->ministry->getName());
	this->nameText.setPosition(pos.x + 15, pos.y + 10);

	this->corruptionText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->corruptionText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->corruptionText.setCharacterSize(15);
	this->corruptionText.setString(std::to_string((int) this->ministry->getCorruptionRate()->getValue()) + "%");
	this->corruptionText.setPosition(pos.x + 50, pos.y + 40);

	this->ministerText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->ministerText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->ministerText.setCharacterSize(15);
	this->ministerText.setString("Minister - " + this->ministry->getMinister()->getName());
	this->ministerText.setPosition(pos.x + 15, pos.y + 65);

	this->loyalityText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->loyalityText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->loyalityText.setCharacterSize(15);
	this->loyalityText.setString(std::to_string((int) this->ministry->getMinister()->getLoyality()->getValue()));
	this->loyalityText.setPosition(pos.x + 40, pos.y + 85);

	this->powerText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->powerText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->powerText.setCharacterSize(15);
	this->powerText.setString(std::to_string((int)this->ministry->getMinister()->getPower()->getValue()));
	this->powerText.setPosition(pos.x + (size.x / 2) + 25, pos.y + 85);

	this->corruptionIconSprite.setTexture(this->assetsHandler->getTextureHolder()["corruption-icon"]);
	this->corruptionIconSprite.setPosition(pos.x + 15, pos.y + 40);

	this->loyalityIconSprite.setTexture(this->assetsHandler->getTextureHolder()["loyality-icon"]);
	this->loyalityIconSprite.setPosition(pos.x + 15, pos.y + 85);

	this->powerIconSprite.setTexture(this->assetsHandler->getTextureHolder()["power-icon"]);
	this->powerIconSprite.setPosition(pos.x + (size.x / 2), pos.y + 80);
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

	if (this->corruptionText.getGlobalBounds().contains(mousePos.x, mousePos.y) || this->corruptionIconSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		this->cursor->setTooltip(this->ministry->getCorruptionRate()->getTooltip());
		this->cursor->setDisplayTooltip(true);
	}

	if (this->powerText.getGlobalBounds().contains(mousePos.x, mousePos.y) || this->powerIconSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		this->cursor->setTooltip(this->ministry->getMinister()->getPower()->getTooltip());
		this->cursor->setDisplayTooltip(true);
	}

	if (this->loyalityText.getGlobalBounds().contains(mousePos.x, mousePos.y) || this->loyalityIconSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		this->cursor->setTooltip(this->ministry->getMinister()->getLoyality()->getTooltip());
		this->cursor->setDisplayTooltip(true);
	}
}

void MinistryCard::updateEndTurn()
{
	this->nameText.setString(this->ministry->getName());
	this->corruptionText.setString(std::to_string((int)this->ministry->getCorruptionRate()->getValue()) + "%");
	this->ministerText.setString("Minister - " + this->ministry->getMinister()->getName());
	this->loyalityText.setString(std::to_string((int)this->ministry->getMinister()->getLoyality()->getValue()));
	this->powerText.setString(std::to_string((int)this->ministry->getMinister()->getPower()->getValue()));
}

void MinistryCard::draw()
{
	this->window->getWindow()->draw(this->body);
	this->window->getWindow()->draw(this->nameText);
	this->window->getWindow()->draw(this->ministerText);
	this->window->getWindow()->draw(this->powerText);
	this->window->getWindow()->draw(this->loyalityText);
	this->window->getWindow()->draw(this->corruptionText);

	this->window->getWindow()->draw(this->corruptionIconSprite);
	this->window->getWindow()->draw(this->loyalityIconSprite);
	this->window->getWindow()->draw(this->powerIconSprite);
}

MinistryCard::~MinistryCard()
{

}