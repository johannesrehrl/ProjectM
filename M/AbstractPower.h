#pragma once
#include <vector>
#include <iostream>
#include "Modifier.h"
#include "Tooltip.h"
#include "Window.h"
#include "AssetsHandler.h"

class AbstractPower
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	float power;
	std::vector<std::shared_ptr<Modifier>> powerModifiers;
	std::shared_ptr<Tooltip> myTooltip;

public:
	AbstractPower(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~AbstractPower();
	void updateEndTurn();
	void makeTooltip();

	float getValue() { return this->power; }
	void addPowerModifier(std::shared_ptr<Modifier> mod) { this->powerModifiers.push_back(mod); this->recalcPower(); }
	void subPowerModifier(std::string id);

	void recalcPower();

	std::shared_ptr<Tooltip> getTooltip() { return this->myTooltip; }
};