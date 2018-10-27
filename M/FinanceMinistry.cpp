#include "FinanceMinistry.h"

FinanceMinistry::FinanceMinistry(std::string name, std::shared_ptr<Minister> minister) : Ministry(name, minister)
{
	
}

void FinanceMinistry::updateEndTurn()
{
	this->recalcCorruption();

	this->minister->updateEndTurn();
	this->corruptionRate->updateEndTurn();
}

FinanceMinistry::~FinanceMinistry()
{

}