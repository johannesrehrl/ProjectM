#include "FinanceMinistry.h"

FinanceMinistry::FinanceMinistry(std::string name, std::shared_ptr<Minister> minister, float corruption)
	: Ministry(name, minister, corruption)
{
	
}

void FinanceMinistry::updateEndTurn()
{
	this->minister->updateEndTurn();
}

FinanceMinistry::~FinanceMinistry()
{

}