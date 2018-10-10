#include "Button.h"
#define STANDARD_HEIGHT 40
#define STANDARD_WIDTH 150

Button::Button(std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<Window> window, std::string string, style choosenStyle, sf::Vector2f pos)
{
	this->assetsHandler = assetsHandler;
	this->window = window;

	sf::Text textComp;
	sf::RectangleShape rectComp;
	sf::FloatRect textRect;

	switch (choosenStyle)
	{
	case style::STANDARD:
		textComp.setFont(this->assetsHandler->getFontHolder()["expressway"]);
		textComp.setCharacterSize(20);
		textComp.setFillColor(this->assetsHandler->getColorHolder()["black"]);
		textComp.setString(string);
		textRect = textComp.getLocalBounds();
		textComp.setOrigin(textRect.width / 2, textRect.top + textRect.height / 2);

		rectComp.setSize(sf::Vector2f(STANDARD_WIDTH, STANDARD_HEIGHT));
		rectComp.setOutlineThickness(3);
		rectComp.setOutlineColor(this->assetsHandler->getColorHolder()["black"]);
		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey160"]);
		rectComp.setOrigin(rectComp.getSize().x / 2, rectComp.getSize().y / 2);

		textComp.setPosition(STANDARD_WIDTH / 2 + 3, STANDARD_HEIGHT / 2 + 3);
		rectComp.setPosition(STANDARD_WIDTH / 2 + 3, STANDARD_HEIGHT / 2 + 3);

		this->textureDefault.create(STANDARD_WIDTH + 6, STANDARD_HEIGHT + 6);
		this->textureDefault.draw(rectComp);
		this->textureDefault.draw(textComp);
		this->textureDefault.display();

		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey185"]);

		this->textureSelected.create(STANDARD_WIDTH + 6, STANDARD_HEIGHT + 6);
		this->textureSelected.draw(rectComp);
		this->textureSelected.draw(textComp);
		this->textureSelected.display();
		break;
	default:
		break;
	}

	this->buttonSprite.setTexture(this->textureDefault.getTexture());
	this->buttonSprite.setPosition(pos);
	this->buttonSprite.setOrigin(this->buttonSprite.getTextureRect().width / 2, this->buttonSprite.getTextureRect().height / 2);
}

void Button::update(sf::Vector2i mousePos)
{
	if (this->buttonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		this->selected = true;

		this->buttonSprite.setTexture(this->textureSelected.getTexture());

		if (this->assetsHandler->getActionMap().isActive("leftRelease"))
		{
			this->onSelect();
		}
	}

	else
	{
		this->buttonSprite.setTexture(this->textureDefault.getTexture());
	}
}

void Button::draw()
{
	this->window->getWindow()->draw(buttonSprite);
}

Button::~Button()
{

}