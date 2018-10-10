#include "PauseViewState.h"

PauseViewState::PauseViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->stateChange = "";

	this->mainMenuButton = std::make_shared<Button>(this->assetsHandler, this->window, "Back to Menu", Button::style::STANDARD,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 - 75));
	this->mainMenuButton->setOnSelect([this] {
		this->setStateChange("TOP:MAINMENU");
	});

	this->exitButton = std::make_shared<Button>(this->assetsHandler, this->window, "Exit", Button::style::STANDARD,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 - 25));
	this->exitButton->setOnSelect([window] {
		window->getWindow()->close();
	});

	this->saveButton = std::make_shared<Button>(this->assetsHandler, this->window, "Save", Button::style::STANDARD,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 + 25));
	this->saveButton->setOnSelect([this] {
		this->setStateChange("TOP:SAVE");
	});

	this->backButton = std::make_shared<Button>(this->assetsHandler, this->window, "Back to Game", Button::style::STANDARD,
		sf::Vector2f(this->window->getDesktop().front().width / 2, this->window->getDesktop().front().height / 2 + 75));
	this->backButton->setOnSelect([this] {
		this->setStateChange("MAIN");
	});
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
	this->mainMenuButton->draw();
	this->exitButton->draw();
	this->saveButton->draw();
	this->backButton->draw();
}

PauseViewState::~PauseViewState()
{

}