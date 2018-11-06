#pragma once
#include <vector>
#include "Modifier.h"
#include "Tooltip.h"

class NationalStability
{
private:
	float stability;
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::vector<std::shared_ptr<Modifier>> resourceModifier;
	std::shared_ptr<Tooltip> myTooltip;

public:
	NationalStability(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~NationalStability();
	void updateEndTurn();
	void makeTooltip();

	float getValue() { return this->stability; }

	std::vector<std::shared_ptr<Modifier>> getStabilityModifier() { return this->resourceModifier; }
	std::shared_ptr<Modifier> getStabilityModifierById(std::string id);
	void addStabilityModifier(std::shared_ptr<Modifier> val);
	void subStabilityModifier(std::string id);

	std::shared_ptr<Tooltip> getTooltip() { return this->myTooltip; }
};