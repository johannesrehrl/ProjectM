#pragma once
#include <vector>
#include "Modifier.h"

class NationalStability
{
private:
	float stability;
	std::vector<std::shared_ptr<Modifier>> resourceModifier;

public:
	NationalStability();
	~NationalStability();
	void updateEndTurn();

	float getValue() { return this->stability; }

	std::vector<std::shared_ptr<Modifier>> getStabilityModifier() { return this->resourceModifier; }
	std::shared_ptr<Modifier> getStabilityModifierById(std::string id);
	void addStabilityModifier(std::shared_ptr<Modifier> val);
	void subStabilityModifier(std::string id);
};