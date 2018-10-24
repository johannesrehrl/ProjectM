#pragma once
#include "Modifier.h"
#include <vector>

class InfluenceResource
{
private:
	float influence;
	float endTurnChange;
	std::vector<std::shared_ptr<Modifier>> resourceModifier;

public:
	InfluenceResource(float influence);
	~InfluenceResource();
	void updateEndTurn();

	float getInfluence() { return this->influence; }
	float getEndTurnChange() { return this->endTurnChange; }

	void setInfluence(float val) { this->influence = val; }
	void setEndTurnChange(float val) { this->endTurnChange = val; }

	void addInfluence(float val) { this->influence += val; }
	void subInfluence(float val) { this->influence -= val; }

	std::vector<std::shared_ptr<Modifier>> getInfluenceModifiers() { return this->resourceModifier; }
	void addInfluenceModifier(std::shared_ptr<Modifier> val);
	void subInfluenceModifier(std::string id);
};