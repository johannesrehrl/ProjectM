#include "Button.h"
#define STANDARD_HEIGHT 40
#define STANDARD_WIDTH 150
#define STANDARD_OUTLINE 3

#define NEXT_TURN_HEIGHT ((float)this->window->getDesktop().front().width / 100) * 5
#define NEXT_TURN_WIDTH ((float)this->window->getDesktop().front().width / 100) * 15
#define NEXT_TURN_OUTLINE 5

#define PAUSE_MENU_HEIGHT 75
#define PAUSE_MENU_WIDTH 300
#define PAUSE_MENU_OUTLINE 3

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
		rectComp.setOutlineThickness(STANDARD_OUTLINE);
		rectComp.setOutlineColor(this->assetsHandler->getColorHolder()["black"]);
		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey160"]);
		rectComp.setOrigin(rectComp.getSize().x / 2, rectComp.getSize().y / 2);

		textComp.setPosition(STANDARD_WIDTH / 2 + STANDARD_OUTLINE, STANDARD_HEIGHT / 2 + STANDARD_OUTLINE);
		rectComp.setPosition(STANDARD_WIDTH / 2 + STANDARD_OUTLINE, STANDARD_HEIGHT / 2 + STANDARD_OUTLINE);

		this->textureDefault.create(STANDARD_WIDTH + STANDARD_OUTLINE * 2, STANDARD_HEIGHT + STANDARD_OUTLINE * 2);
		this->textureDefault.draw(rectComp);
		this->textureDefault.draw(textComp);
		this->textureDefault.display();

		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey185"]);

		this->textureSelected.create(STANDARD_WIDTH + STANDARD_OUTLINE * 2, STANDARD_HEIGHT + STANDARD_OUTLINE * 2);
		this->textureSelected.draw(rectComp);
		this->textureSelected.draw(textComp);
		this->textureSelected.display();
		break;

	case style::NEXT_TURN:
		textComp.setFont(this->assetsHandler->getFontHolder()["squares-bold"]);
		textComp.setCharacterSize(35);
		textComp.setFillColor(this->assetsHandler->getColorHolder()["black"]);
		textComp.setString(string);
		textRect = textComp.getLocalBounds();
		textComp.setOrigin(textRect.width / 2, textRect.top + textRect.height / 2);

		rectComp.setSize(sf::Vector2f(NEXT_TURN_WIDTH, NEXT_TURN_HEIGHT));
		rectComp.setOutlineThickness(NEXT_TURN_OUTLINE);
		rectComp.setOutlineColor(this->assetsHandler->getColorHolder()["black"]);
		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
		rectComp.setOrigin(rectComp.getSize().x / 2, rectComp.getSize().y / 2);

		textComp.setPosition(NEXT_TURN_WIDTH / 2 + NEXT_TURN_OUTLINE, NEXT_TURN_HEIGHT / 2 + NEXT_TURN_OUTLINE);
		rectComp.setPosition(NEXT_TURN_WIDTH / 2 + NEXT_TURN_OUTLINE, NEXT_TURN_HEIGHT / 2 + NEXT_TURN_OUTLINE);

		this->textureDefault.create(NEXT_TURN_WIDTH + NEXT_TURN_OUTLINE * 2, NEXT_TURN_HEIGHT + NEXT_TURN_OUTLINE * 2);
		this->textureDefault.draw(rectComp);
		this->textureDefault.draw(textComp);
		this->textureDefault.display();

		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey200"]);

		this->textureSelected.create(NEXT_TURN_WIDTH + NEXT_TURN_OUTLINE * 2, NEXT_TURN_HEIGHT + NEXT_TURN_OUTLINE * 2);
		this->textureSelected.draw(rectComp);
		this->textureSelected.draw(textComp);
		this->textureSelected.display();
		break;

	case style::PAUSE_MENU:
		textComp.setFont(this->assetsHandler->getFontHolder()["expressway"]);
		textComp.setCharacterSize(30);
		textComp.setFillColor(this->assetsHandler->getColorHolder()["black"]);
		textComp.setString(string);
		textRect = textComp.getLocalBounds();
		textComp.setOrigin(textRect.width / 2, textRect.top + textRect.height / 2);

		rectComp.setSize(sf::Vector2f(PAUSE_MENU_WIDTH, PAUSE_MENU_HEIGHT));
		rectComp.setOutlineThickness(PAUSE_MENU_OUTLINE);
		rectComp.setOutlineColor(this->assetsHandler->getColorHolder()["black"]);
		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
		rectComp.setOrigin(rectComp.getSize().x / 2, rectComp.getSize().y / 2);

		textComp.setPosition((PAUSE_MENU_WIDTH / 2) + PAUSE_MENU_OUTLINE, (PAUSE_MENU_HEIGHT / 2) + PAUSE_MENU_OUTLINE);
		rectComp.setPosition((PAUSE_MENU_WIDTH / 2) + PAUSE_MENU_OUTLINE, (PAUSE_MENU_HEIGHT / 2) + PAUSE_MENU_OUTLINE);

		this->textureDefault.create(PAUSE_MENU_WIDTH + (PAUSE_MENU_OUTLINE * 2), PAUSE_MENU_HEIGHT + (PAUSE_MENU_OUTLINE * 2));
		this->textureDefault.draw(rectComp);
		this->textureDefault.draw(textComp);
		this->textureDefault.display();

		rectComp.setFillColor(this->assetsHandler->getColorHolder()["grey200"]);

		this->textureSelected.create(PAUSE_MENU_WIDTH + (PAUSE_MENU_OUTLINE * 2), PAUSE_MENU_HEIGHT + (PAUSE_MENU_OUTLINE * 2));
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
	if (!active) return;

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

	if (!this->onSelect)
	{
		this->active = false;
	}
}

void Button::draw()
{
	this->window->getWindow()->draw(buttonSprite);
}

Button::~Button()
{

}