#pragma once
#include <vector>
#include <Thor/Math.hpp>
#include "Flag.h"

class FlagManager
{
private:
	std::vector<std::shared_ptr<Flag>> allFlags;

public:
	FlagManager();
	~FlagManager();
	void updateEndTurn();

	bool doesFlagExist(std::string id);
	std::shared_ptr<Flag> getFlag(std::string id);
	void addFlag(std::shared_ptr<Flag> val) { this->allFlags.push_back(val); }
	void deleteFlag(std::string id);
};