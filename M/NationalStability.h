#pragma once
#include <vector>
#include "ResourceModifier.h"

class NationalStability
{
private:
	float stability;
	std::vector<std::shared_ptr<ResourceModifier>> resourceModifier;

public:
	NationalStability();
	~NationalStability();
	void updateEndTurn();

	void setStability(float val) { this->stability = val; }
	float getStability() { return this->stability; }

	std::vector<std::shared_ptr<ResourceModifier>> getStabilityModifier() { return this->resourceModifier; }
	void addStabilityModifier(std::shared_ptr<ResourceModifier> val) { this->resourceModifier.push_back(val); }
	void subStabilityModifier(std::string id);
};