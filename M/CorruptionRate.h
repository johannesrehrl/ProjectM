#pragma once
#include <vector>
#include "Modifier.h"
#include "Tooltip.h"
#include "Window.h"
#include "AssetsHandler.h"

class CorruptionRate
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	float corruption;
	float endTurnChange;
	std::vector<std::shared_ptr<Modifier>> resourceModifier;
	std::shared_ptr<Tooltip> myTooltip;

public:
	CorruptionRate(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~CorruptionRate();
	void updateEndTurn();
	void makeTooltip();

	float getValue() { return this->corruption; }
	float getEndTurnChange() { return this->endTurnChange; }

	void setCorruption(float val) { this->corruption = val; }
	void setEndTurnChange(float val) { this->endTurnChange = val; }

	void addCorruption(float val) { this->corruption += val; }
	void subCorruption(float val) { this->corruption -= val; }

	std::vector<std::shared_ptr<Modifier>> getCorruptionModifiers() { return this->resourceModifier; }
	std::shared_ptr<Modifier> getCorruptionModifierById(std::string val);
	void addCorruptionModifier(std::shared_ptr<Modifier> id);
	void subCorruptionModifier(std::string id);

	void recalcCorruption();

	std::shared_ptr<Tooltip> getTooltip() { return this->myTooltip; }
};