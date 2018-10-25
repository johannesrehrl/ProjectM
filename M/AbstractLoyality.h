#pragma once
#include <vector>
#include <iostream>
#include "Modifier.h"

class AbstractLoyality
{
private:
	float loyality;
	std::vector<std::shared_ptr<Modifier>> loyalityModifiers;

public:
	AbstractLoyality();
	~AbstractLoyality();
	void updateEndTurn();

	float getLoyality() { return this->loyality; }
	void addLoyalityModifier(std::shared_ptr<Modifier> mod) { this->loyalityModifiers.push_back(mod); this->recalcLoyality(); }
	void subLoyalityModifier(std::string id);

	void recalcLoyality();
};