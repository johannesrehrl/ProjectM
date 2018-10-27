#include "Government.h"

Government::Government()
{
	this->president = std::make_shared<President>();
	this->financeMinistry = std::make_shared<FinanceMinistry>("Ministry of Finance", 
		std::make_shared<Minister>("dieter_arfeld", "Dieter Arfeld", 652));
	this->defenceMinistry = std::make_shared<FinanceMinistry>("Ministry of Defence",
		std::make_shared<Minister>("herman_klen", "Herman Klen", 554));
}

void Government::updateEndTurn()
{
	this->financeMinistry->updateEndTurn();
	this->defenceMinistry->updateEndTurn();
}

Government::~Government()
{

}