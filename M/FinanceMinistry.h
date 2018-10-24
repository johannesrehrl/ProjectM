#pragma once
#include "Ministry.h"
#include "Minister.h"

class FinanceMinistry : Ministry
{
private:


public:
	FinanceMinistry(std::string name, std::shared_ptr<Minister> minister, float corruption);
	~FinanceMinistry();

	void updateEndTurn();
};