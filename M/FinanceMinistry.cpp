#include "FinanceMinistry.h"

FinanceMinistry::FinanceMinistry(std::string name, std::shared_ptr<Minister> minister, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler) : Ministry(name, minister, window, assetsHandler)
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