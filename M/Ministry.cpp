#include "Ministry.h"

Ministry::Ministry(std::string name, std::shared_ptr<Minister> minister)
{
	this->name = name;
	this->minister = minister;
	this->corruptionRate = std::make_shared<CorruptionRate>();
	this->corruptionRate->addCorruption(20);
	this->minister->getLoyality()->addLoyalityModifier(std::make_shared<Modifier>("base_loyality", "Base loyality", "Base loyality", 50));
	this->minister->getPower()->addPowerModifier(std::make_shared<Modifier>("base_power", "Base power", "Base power", 50));
}

void Ministry::recalcCorruption()
{
	float newCorruption = ((1 - ((this->minister->getLoyality()->getValue() / 100) * 2)) / 100) *
		this->minister->getPower()->getValue();

	if (this->corruptionRate->getCorruptionModifierById("minister") == nullptr)
	{
		this->corruptionRate->addCorruptionModifier(std::make_shared<Modifier>
			("minister", "Minister", "Corruption change from Minister.", newCorruption));
	}

	else
	{
		this->corruptionRate->getCorruptionModifierById("minister")->setValue(newCorruption);
	}
}

Ministry::~Ministry()
{

}