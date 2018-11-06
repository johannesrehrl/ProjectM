#pragma once
#include <Thor/Time.hpp>
#include <iostream>
#include "Tooltip.h"
#include "Window.h"
#include "AssetsHandler.h"

class Cursor
{
private:
	std::shared_ptr<Tooltip> currentTooltip;
	std::shared_ptr<AssetsHandler> assetsHandler;
	bool displayTooltip;
	bool enoughTimeElapsed;

	thor::StopWatch stopWatch;

public:
	Cursor(std::shared_ptr<AssetsHandler> assetsHandler);
	~Cursor();
	void update();
	void draw();

	void setTooltip(std::shared_ptr<Tooltip> newTooltip) { this->currentTooltip = newTooltip; }
	void setDisplayTooltip(bool val) { this->displayTooltip = val; }
	bool getDisplayTooltip() { return this->displayTooltip; }
};