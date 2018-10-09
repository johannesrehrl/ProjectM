#include "MainViewState.h"

MainViewState::MainViewState(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler)
{
	this->mainStatisticsContainer = std::make_shared<MainStatisticsContainer>(window, resourceHandler);
}

void MainViewState::update()
{
	this->mainStatisticsContainer->update();
}

void MainViewState::handleInput()
{

}

void MainViewState::draw()
{
	this->mainStatisticsContainer->draw();
}

MainViewState::~MainViewState()
{

}