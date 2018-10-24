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

	void setStability(float val) { this->stability = val; }
	float getStability() { return this->stability; }

	std::vector<std::shared_ptr<Modifier>> getStabilityModifier() { return this->resourceModifier; }
	void addStabilityModifier(std::shared_ptr<Modifier> val);
	void subStabilityModifier(std::string id);
};