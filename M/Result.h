#pragma once
#include <vector>
#include <map>
#include <string>
#include "FlagManager.h"
#include "ResourceManager.h"
#include "Government.h"
#include "Modifier.h"
#include "Flag.h"

class Result
{
private:
	int position;

	float basicInfluence;
	std::vector<Modifier> addInfluenceMod;
	std::vector<std::string> subInfluenceMod;

	std::vector<Modifier> addStabiltyMod;
	std::vector<std::string> subStabiltyMod;

	std::vector<std::pair<std::string, int>> basicCorruption;

	std::vector<std::pair<std::string, Modifier>> addCorruptionMod;
	std::vector<std::pair<std::string, std::string>> subCorruptionMod;

	std::vector<std::pair<std::string, Modifier>> addPowerMod;
	std::vector<std::pair<std::string, std::string>> subPowerMod;

	std::vector<std::pair<std::string, Modifier>> addLoyalityMod;
	std::vector<std::pair<std::string, std::string>> subLoyalityMod;

	std::vector<Flag> addFlag;
	std::vector<std::string> subFlag;

public:
	Result(int position,
	float basicInfluence,
	std::vector<Modifier> addInfluenceMod,
	std::vector<std::string> subInfluenceMod,

	std::vector<Modifier> addStabiltyMod,
	std::vector<std::string> subStabiltyMod,

	std::vector<std::pair<std::string, int>> basicCorruption,

	std::vector<std::pair<std::string, Modifier>> addCorruptionMod,
	std::vector<std::pair<std::string, std::string>> subCorruptionMod,

	std::vector<std::pair<std::string, Modifier>> addPowerMod,
	std::vector<std::pair<std::string, std::string>> subPowerMod,

	std::vector<std::pair<std::string, Modifier>> addLoyalityMod,
	std::vector<std::pair<std::string, std::string>> subLoyalityMod,

	std::vector<Flag> addFlag,
	std::vector<std::string> subFlag
	);
	~Result();

	void applyResults(std::shared_ptr<FlagManager> flagManager, std::shared_ptr<ResourceManager> resourceManager, 
		std::shared_ptr<Government> government, std::shared_ptr<MinisterManager> ministerManager);
	int getPosition() { return this->position; }
};