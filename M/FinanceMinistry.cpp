#include "FinanceMinistry.h"

FinanceMinistry::FinanceMinistry(std::string name, std::shared_ptr<Minister> minister, float loyality, float corruption)
	: Ministry(name, minister, loyality, corruption)
{
	
}

void FinanceMinistry::updateEndTurn()
{
	this->minister->updateEndTurn();
}

FinanceMinistry::~FinanceMinistry()
{

}