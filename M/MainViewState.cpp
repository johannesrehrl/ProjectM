#include "MainViewState.h"

MainViewState::MainViewState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->mainStatisticsContainer = std::make_shared<MainStatisticsContainer>(this->window, this->assetsHandler);
	this->mainEventContainer = std::make_shared<MainEventContainer>(this->window, this->assetsHandler);
	this->mainFactionContainer = std::make_shared<MainFactionContainer>(this->window, this->assetsHandler);
}

void MainViewState::update()
{
	this->mainStatisticsContainer->update();
	this->mainEventContainer->update();
	this->mainFactionContainer->update();
}

void MainViewState::handleInput()
{

}

void MainViewState::draw()
{
	this->mainStatisticsContainer->draw();
	this->mainEventContainer->draw();
	this->mainFactionContainer->draw();
}

MainViewState::~MainViewState()
{

}