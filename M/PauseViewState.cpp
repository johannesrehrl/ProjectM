#include "PauseViewState.h"

PauseViewState::PauseViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->stateChange = "";

	this->mainMenuButton = std::make_shared<Button>(this->assetsHandler, this->window, "Main Menu", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2,
			this->window->getDesktop().front().height / 2 - (this->window->getDesktop().front().height / 100) * 12));
	this->mainMenuButton->setOnSelect([this] {
		this->setStateChange("TOP:MAINMENU");
	});

	this->saveButton = std::make_shared<Button>(this->assetsHandler, this->window, "Save", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2,
			this->window->getDesktop().front().height / 2 - (this->window->getDesktop().front().height / 100) * 4));
	this->saveButton->setOnSelect([this] {
		this->setStateChange("TOP:SAVE");
	});

	this->backButton = std::make_shared<Button>(this->assetsHandler, this->window, "Back", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2,
			this->window->getDesktop().front().height / 2 + (this->window->getDesktop().front().height / 100) * 4));
	this->backButton->setOnSelect([this] {
		this->setStateChange("MAIN");
	});

	this->exitButton = std::make_shared<Button>(this->assetsHandler, this->window, "Exit", Button::style::PAUSE_MENU,
		sf::Vector2f(this->window->getDesktop().front().width / 2,
			this->window->getDesktop().front().height / 2 + (this->window->getDesktop().front().height / 100) * 12));
	this->exitButton->setOnSelect([window] {
		window->getWindow()->close();
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