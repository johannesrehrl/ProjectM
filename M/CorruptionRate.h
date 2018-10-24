#pragma once
#include "Modifier.h"
#include <vector>

class CorruptionRate
{
private:
	float corruption;
	float endTurnChange;
	std::vector<std::shared_ptr<Modifier>> resourceModifier;

public:
	CorruptionRate(float corruption);
	~CorruptionRate();
	void updateEndTurn();

	float getCorruption() { return this->corruption; }
	float getEndTurnChange() { return this->endTurnChange; }

	void setCorruption(float val) { this->corruption = val; }
	void setEndTurnChange(float val) { this->endTurnChange = val; }

	void addCorruption(float val) { this->corruption += val; }
	void subCorruption(float val) { this->corruption -= val; }

	std::vector<std::shared_ptr<Modifier>> getCorruptionModifiers() { return this->resourceModifier; }
	void addCorruptionModifier(std::shared_ptr<Modifier> val);
	void subCorruptionModifier(std::string id);

	void recalcCorruption();
};