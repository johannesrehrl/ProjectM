#include "Government.h"

Government::Government()
{
	this->president = std::make_shared<President>();
	this->financeMinistry = std::make_shared<FinanceMinistry>("Ministry of Finance", 
		std::make_shared<Minister>("dieter_arfeld", "Dieter Arfeld", 652), 80, 20);
}

void Government::updateEndTurn()
{
	this->financeMinistry->updateEndTurn();
}

Government::~Government()
{

}