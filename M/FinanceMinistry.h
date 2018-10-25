#pragma once
#include "Ministry.h"
#include "Minister.h"
#include "Modifier.h"

class FinanceMinistry : Ministry
{
private:


public:
	FinanceMinistry(std::string name, std::shared_ptr<Minister> minister);
	~FinanceMinistry();

	void updateEndTurn();
};