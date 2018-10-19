#pragma once
#include "President.h"
#include "Ministry.h"
#include "Minister.h"
#include "FinanceMinistry.h"

class Government
{
private:
	std::shared_ptr<President> president;
	std::shared_ptr<FinanceMinistry> financeMinistry;

public:
	Government();
	~Government();
	void updateEndTurn();

	std::shared_ptr<President> getPresident() { return this->president; }
	std::shared_ptr<FinanceMinistry> getFinanceMinistry() { return this->financeMinistry; }
};