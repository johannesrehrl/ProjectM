#include "FinanceMinistry.h"

FinanceMinistry::FinanceMinistry(std::string name, std::shared_ptr<Minister> minister) : Ministry(name, minister)
{
	
}

void FinanceMinistry::updateEndTurn()
{
	float newCorruption = 1 - ((((this->minister->getLoyality() / 100) * 2) / 100) * this->minister->getPower());

	if (this->corruptionRate->getCorruptionModifierById("minister") != nullptr)
	{
		this->corruptionRate->addCorruptionModifier(std::make_shared<Modifier>
			("minister", "Minister", "Corruption change from Minister.", newCorruption));
	}

	else
	{
		this->corruptionRate->getCorruptionModifierById("minister")->setValue(newCorruption);
	}

	this->minister->updateEndTurn();
	this->corruptionRate->updateEndTurn();
}

FinanceMinistry::~FinanceMinistry()
{

}