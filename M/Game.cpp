#include "Game.h"
#include "Thor\Resources.hpp"

Game::Game(std::shared_ptr<Settings> settings, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->settings = settings;
	this->assetsHandler = assetsHandler;

	this->window = std::make_shared<Window>("Window", assetsHandler);
	this->window->getWindow()->setVerticalSyncEnabled(this->settings->getUseVSynch());
	this->running = true;

	this->fpsText.setFont(this->assetsHandler->getFontHolder()["expressway"]);
	this->fpsText.setFillColor(sf::Color::Red);
	this->fpsText.setCharacterSize(20);
	this->fpsText.setPosition(sf::Vector2f(20,20));

	this->currentGameState = std::make_unique<MainMenuState>(this->settings, this->window, this->assetsHandler);
}

void Game::update()
{
	running = this->window->isRunning();
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
	window->getWindow()->display();
}

void Game::checkStateChange()
{
	if (this->currentGameState->getStateChange() == "MAINMENU")
	{
		this->currentGameState.reset();
		this->currentGameState = std::make_unique<MainMenuState>(this->settings, this->window, this->assetsHandler);
	}

	else if (this->currentGameState->getStateChange() == "PLAY")
	{
		this->currentGameState.reset();
		this->currentGameState = std::make_unique<PlayState>(this->window, this->assetsHandler);
	}
}

Game::~Game()
{

}