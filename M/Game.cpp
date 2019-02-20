#include "Game.h"
#include "Thor\Resources.hpp"

Game::Game(std::shared_ptr<Settings> settings, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->settings = settings;
	this->assetsHandler = assetsHandler;

	this->window = std::make_shared<Window>("Window", assetsHandler);
	this->window->getWindow()->setVerticalSyncEnabled(this->settings->getUseVSync());
	this->running = true;

	this->cursor = std::make_shared<Cursor>(this->assetsHandler);

	this->fpsText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->fpsText.setFillColor(sf::Color::Red);
	this->fpsText.setCharacterSize(20);
	this->fpsText.setPosition(sf::Vector2f(20,20));

	this->currentGameState = std::make_shared<MainMenuState>(this->settings, this->window, this->assetsHandler);
	this->playState = std::make_shared<PlayState>(this->window, this->assetsHandler, this->cursor);
}

void Game::update()
{
	this->running = this->window->isRunning();
	this->cursor->update();
	this->assetsHandler->getActionMap().update(*(this->window->getWindow()));
	this->window->update();
	this->currentGameState->update();
	this->currentGameState->handleInput();
}

void Game::draw()
{
	window->getWindow()->clear(this->assetsHandler->getColorHolder()["background"]);

	if (settings->getDisplayFps())
	{
		fpsText.setString("FPS: " + std::to_string((int)window->getFps()));
		window->getWindow()->draw(fpsText);
	}
	
	this->currentGameState->draw();
	this->cursor->draw();
	window->getWindow()->display();
}

void Game::checkStateChange()
{
	if (this->currentGameState->getStateChange() == "MAINMENU")
	{
		this->playState.reset();
		this->playState = std::make_shared<PlayState>(this->window, this->assetsHandler, this->cursor);
		this->currentGameState.reset();
		this->currentGameState = std::make_unique<MainMenuState>(this->settings, this->window, this->assetsHandler);
	}

	else if (this->currentGameState->getStateChange() == "SETUP")
	{
		this->currentGameState.reset();
		this->currentGameState = std::make_unique<SetupState>(this->window, this->assetsHandler, this->playState);
	}

	else if (this->currentGameState->getStateChange() == "PLAY")
	{
		this->playState->setStateChange("");
		this->currentGameState.reset();
		this->currentGameState = this->playState;
	}
}

Game::~Game()
{

}