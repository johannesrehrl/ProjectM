#include "MainStatisticsContainer.h"

MainStatisticsContainer::MainStatisticsContainer(std::shared_ptr<Window> window, std::shared_ptr<ResourceHandler> resourceHandler)
{
	this->window = window;
	this->resourceHandler = resourceHandler;

	this->body.setSize(sf::Vector2f(((float) this->window->getDesktop().front().width / 100) * 20, ((float) this->window->getDesktop().front().height / 100) * 80));
	this->body.setFillColor(this->resourceHandler->getColorHolder()["grey160"]);
	this->body.setPosition(((float) this->window->getDesktop().front().width / 100) * 75, ((float) this->window->getDesktop().front().height / 100) * 10);
}

void MainStatisticsContainer::update()
{

}

void MainStatisticsContainer::draw()
{
	this->window->getWindow()->draw(body);
}

MainStatisticsContainer::~MainStatisticsContainer()
{

}