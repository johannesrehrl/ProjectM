#pragma once
#include <vector>
#include <iostream>
#include "Modifier.h"

class AbstractPower
{
private:
	float power;
	std::vector<std::shared_ptr<Modifier>> powerModifiers;

public:
	AbstractPower();
	~AbstractPower();
	void updateEndTurn();

	float getPower() { return this->power; }
	void addPowerModifier(std::shared_ptr<Modifier> mod) { this->powerModifiers.push_back(mod); this->recalcPower(); }
	void subPowerModifier(std::string id);

	void recalcPower();
};