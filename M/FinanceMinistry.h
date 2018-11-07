#pragma once
#include "Ministry.h"
#include "Minister.h"
#include "Modifier.h"

class FinanceMinistry : public Ministry
{
private:


public:
	FinanceMinistry(std::string name, std::shared_ptr<Minister> minister, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~FinanceMinistry();

	void updateEndTurn();
};