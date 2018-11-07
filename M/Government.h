#pragma once
#include "President.h"
#include "Ministry.h"
#include "Minister.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "FinanceMinistry.h"
#include "DefenceMinistry.h"

class Government
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<President> president;
	std::shared_ptr<FinanceMinistry> financeMinistry;
	std::shared_ptr<FinanceMinistry> defenceMinistry;

public:
	Government(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~Government();
	void updateEndTurn();

	std::shared_ptr<President> getPresident() { return this->president; }
	std::shared_ptr<FinanceMinistry> getFinanceMinistry() { return this->financeMinistry; }
	std::shared_ptr<FinanceMinistry> getDefenceMinistry() { return this->defenceMinistry; }
};