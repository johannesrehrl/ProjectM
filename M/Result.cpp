#include "Result.h"

Result::Result(int position,
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
)
{
	this->position = position;

	this->basicInfluence = basicInfluence;
	this->addInfluenceMod = addInfluenceMod;
	this->subInfluenceMod = subInfluenceMod;

	this->addStabiltyMod = addStabiltyMod;
	this->subStabiltyMod = subStabiltyMod;

	this->basicCorruption = basicCorruption;
	this->addCorruptionMod = addCorruptionMod;
	this->subCorruptionMod = subCorruptionMod;

	this->addPowerMod = addPowerMod;
	this->subPowerMod = subPowerMod;

	this->addLoyalityMod = addLoyalityMod;
	this->subLoyalityMod = subLoyalityMod;

	this->addFlag = addFlag;
	this->subFlag = subFlag;
}

void Result::applyResults(std::shared_ptr<FlagManager> flagManager, std::shared_ptr<ResourceManager> resourceManager, 
	std::shared_ptr<Government> government, std::shared_ptr<MinisterManager> ministerManager)
{
	resourceManager->getInfluenceResource()->addInfluence(this->basicInfluence);

	//Influence Modifiers.
	for (int i = 0; i < this->addInfluenceMod.size(); i++)
	{
		resourceManager->getInfluenceResource()->addInfluenceModifier(std::make_shared<Modifier>(this->addInfluenceMod.at(i)));
	}

	for (int i = 0; i < this->subInfluenceMod.size(); i++)
	{
		resourceManager->getInfluenceResource()->subInfluenceModifier(this->addInfluenceMod.at(i).getId());
	}

	//Stability Modifiers.
	for (int i = 0; i < this->addStabiltyMod.size(); i++)
	{
		resourceManager->getNationalStability()->addStabilityModifier(std::make_shared<Modifier>(this->addStabiltyMod.at(i)));
	}

	for (int i = 0; i < this->addStabiltyMod.size(); i++)
	{
		resourceManager->getNationalStability()->subStabilityModifier(this->addStabiltyMod.at(i).getId());
	}

	//Corruption Modifiers.
	for (int i = 0; i < this->basicCorruption.size(); i++)
	{
		if (this->basicCorruption.at(i).first == "finance")
		{
			government->getFinanceMinistry()->getCorruptionRate()->addCorruption(basicCorruption.at(i).second);
		}

		else if (this->basicCorruption.at(i).first == "defence")
		{
			government->getDefenceMinistry()->getCorruptionRate()->addCorruption(basicCorruption.at(i).second);
		}
	}

	for (int i = 0; i < this->addCorruptionMod.size(); i++)
	{
		if (this->addCorruptionMod.at(i).first == "finance")
		{
			government->getFinanceMinistry()->getCorruptionRate()->addCorruptionModifier(std::make_shared<Modifier>(addCorruptionMod.at(i).second));
		}

		else if (this->basicCorruption.at(i).first == "defence")
		{
			government->getDefenceMinistry()->getCorruptionRate()->addCorruptionModifier(std::make_shared<Modifier>(addCorruptionMod.at(i).second));
		}
	}

	for (int i = 0; i < this->subCorruptionMod.size(); i++)
	{
		if (this->addCorruptionMod.at(i).first == "finance")
		{
			government->getFinanceMinistry()->getCorruptionRate()->subCorruptionModifier(this->subCorruptionMod.at(i).second));
		}

		else if (this->basicCorruption.at(i).first == "defence")
		{
			government->getDefenceMinistry()->getCorruptionRate()->subCorruptionModifier(this->subCorruptionMod.at(i).second));
		}
	}

	//Power Modifiers
	for (int i = 0; i < this->addPowerMod.size(); i++)
	{
		if (this->addCorruptionMod.at(i).first == "finance")
		{
			government->getFinanceMinistry()->getMinister()->getPower()->addPowerModifier(std::make_shared<Modifier>(this->addPowerMod.at(i).second));
		}

		else if (this->basicCorruption.at(i).first == "defence")
		{
			government->getDefenceMinistry()->getMinister()->getPower->addPowerModifier(std::make_shared<Modifier>(this->addPowerMod.at(i).second));
		}

		for (int x = 0; x < ministerManager->getMinisterList().size(); x++)
		{
			if (this->addCorruptionMod.at(i).first == ministerManager->getMinisterList().at(x)->getId)
			{
				ministerManager->getMinisterList().at(x)->getPower()->addPowerModifier(std::make_shared<Modifier>(this->addPowerMod.at(i).second));
			}
		}
	}

	for (int i = 0; i < this->subCorruptionMod.size(); i++)
	{
		if (this->addCorruptionMod.at(i).first == "finance")
		{
			government->getFinanceMinistry()->getCorruptionRate()->subCorruptionModifier(this->subCorruptionMod.at(i).second));
		}

		else if (this->basicCorruption.at(i).first == "defence")
		{
			government->getDefenceMinistry()->getCorruptionRate()->subCorruptionModifier(this->subCorruptionMod.at(i).second));
		}
	}

	//Flag setting.
	for (int i = 0; i < this->addFlag.size(); i++)
	{
		if (flagManager->doesFlagExist(this->addFlag.at(i).getId()))
		{
			flagManager->getFlag(this->addFlag.at(i).getId())->setActive(true);
		}

		else
		{
			flagManager->addFlag(std::make_shared<Flag>(this->addFlag.at(i)));
		}
	}

	for (int i = 0; i < this->subFlag.size(); i++)
	{
		if (flagManager->doesFlagExist(this->subFlag.at(i)))
		{
			flagManager->deleteFlag(this->subFlag.at(i));
		}
	}
}

Result::~Result()
{

}