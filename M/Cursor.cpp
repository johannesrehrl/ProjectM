#include "Cursor.h"

Cursor::Cursor(std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->assetsHandler = assetsHandler;
	this->displayTooltip = false;
	this->enoughTimeElapsed = false;
	this->currentTooltip = nullptr;

	this->stopWatch.start();
}

void Cursor::update()
{
	if (displayTooltip)
	{
		this->currentTooltip->setPosition(sf::Mouse::getPosition());
	}

	this->displayTooltip = false;

	if (this->assetsHandler->getActionMap().isActive("mouseMoved"))
	{
		this->stopWatch.reset();
	}

	this->stopWatch.stop();

	if (this->stopWatch.getElapsedTime().asSeconds() >= 0.25)
	{
		this->enoughTimeElapsed = true;
	}

	else if (!this->displayTooltip)
	{
		this->enoughTimeElapsed = false;
	}

	this->stopWatch.start();
}

void Cursor::draw()
{
	if (displayTooltip && enoughTimeElapsed)
	{
		this->currentTooltip->draw();
	}
}

Cursor::~Cursor()
{

}