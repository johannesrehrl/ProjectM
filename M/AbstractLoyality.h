#pragma once
#include <vector>
#include <iostream>
#include "Modifier.h"
#include "Tooltip.h"
#include "Window.h"
#include "AssetsHandler.h"

class AbstractLoyality
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	float loyality;
	std::vector<std::shared_ptr<Modifier>> loyalityModifiers;
	std::shared_ptr<Tooltip> myTooltip;

public:
	AbstractLoyality(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~AbstractLoyality();
	void updateEndTurn();
	void makeTooltip();

	float getValue() { return this->loyality; }
	void addLoyalityModifier(std::shared_ptr<Modifier> mod) { this->loyalityModifiers.push_back(mod); this->recalcLoyality(); }
	void subLoyalityModifier(std::string id);

	void recalcLoyality();

	std::shared_ptr<Tooltip> getTooltip() { return this->myTooltip; }
};