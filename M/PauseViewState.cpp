#include "PauseViewState.h"

PauseViewState::PauseViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->stateChange = "";

	this->mainMenuButton = std::make_shared<Button>(this->assetsHandler, this->window, "Main Menu", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 - 150));
	this->mainMenuButton->setOnSelect([this] {
		this->setStateChange("TOP:MAINMENU");
	});

	this->saveButton = std::make_shared<Button>(this->assetsHandler, this->window, "Save", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 - 50));
	this->saveButton->setOnSelect([this] {
		this->setStateChange("TOP:SAVE");
	});

	this->backButton = std::make_shared<Button>(this->assetsHandler, this->window, "Back", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 + 50));
	this->backButton->setOnSelect([this] {
		this->setStateChange("MAIN");
	});

	this->exitButton = std::make_shared<Button>(this->assetsHandler, this->window, "Exit", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 + 150));
	this->exitButton->setOnSelect([window] {
		window->getWindow()->close();
	});

	this->body.setSize(sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 30, ((float)this->window->getDesktop().front().height / 100) * 70));
	this->bodyShadow.setSize(sf::Vector2f(((float)this->window->getDesktop().front().width / 100) * 30 - 10, ((float)this->window->getDesktop().front().height / 100) * 70 - 10));
	this->body.setOrigin(this->body.getSize().x / 2, this->body.getSize().y / 2);
	this->bodyShadow.setOrigin(this->bodyShadow.getSize().x / 2, this->bodyShadow.getSize().y / 2);
	this->body.setFillColor(this->assetsHandler->getColorHolder()["grey170"]);
	this->bodyShadow.setFillColor(this->assetsHandler->getColorHolder()["grey30"]);
	this->body.setPosition((float) this->window->getDesktop().front().width / 2, (float)this->window->getDesktop().front().height / 2);
	this->bodyShadow.setPosition((float)this->window->getDesktop().front().width / 2 + 20, (float)this->window->getDesktop().front().height / 2 + 20);
}

void PauseViewState::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	this->mainMenuButton->update(mousePos);
	this->exitButton->update(mousePos);
	this->saveButton->update(mousePos);
	this->backButton->update(mousePos);
}

void PauseViewState::handleInput()
{
	if (this->assetsHandler->getActionMap().isActive("escapeRelease"))
	{
		this->stateChange = "MAIN";
	}
}

void PauseViewState::draw()
{
	this->window->getWindow()->draw(bodyShadow);
	this->window->getWindow()->draw(body);

	this->mainMenuButton->draw();
	this->exitButton->draw();
	this->saveButton->draw();
	this->backButton->draw();
}

PauseViewState::~PauseViewState()
{

}