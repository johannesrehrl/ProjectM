#pragma once
#include "Modifier.h"
#include "Tooltip.h"
#include "Window.h"
#include "AssetsHandler.h"
#include <vector>

class InfluenceResource
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	float influence;
	float endTurnChange;
	std::vector<std::shared_ptr<Modifier>> resourceModifier;
	std::shared_ptr<Tooltip> myTooltip;

public:
	InfluenceResource(float influence, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~InfluenceResource();
	void updateEndTurn();
	void makeTooltip();

	float getValue() { return this->influence; }
	float getEndTurnChange() { return this->endTurnChange; }

	void setInfluence(float val) { this->influence = val; }
	void setEndTurnChange(float val) { this->endTurnChange = val; }

	void addInfluence(float val) { this->influence += val; }
	void subInfluence(float val) { this->influence -= val; }

	std::vector<std::shared_ptr<Modifier>> getInfluenceModifiers() { return this->resourceModifier; }
	std::shared_ptr<Modifier> getInfluenceModifierById(std::string id);
	void addInfluenceModifier(std::shared_ptr<Modifier> val);
	void subInfluenceModifier(std::string id);

	std::shared_ptr<Tooltip> getTooltip() { return this->myTooltip; }
};