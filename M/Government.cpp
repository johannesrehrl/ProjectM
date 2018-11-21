#include "Government.h"

Government::Government(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<MinisterManager> ministerManager)
{
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->president = std::make_shared<President>();
	this->financeMinistry = std::make_shared<FinanceMinistry>("Ministry of Finance", 
		std::make_shared<Minister>("placeholder", "placeholder", 0, true, this->window, this->assetsHandler), this->window, this->assetsHandler);
	this->defenceMinistry = std::make_shared<FinanceMinistry>("Ministry of Defence",
		std::make_shared<Minister>("placeholder", "placeholder", 0, true, this->window, this->assetsHandler), this->window, this->assetsHandler);
}

void Government::updateEndTurn()
{
	this->financeMinistry->updateEndTurn();
	this->defenceMinistry->updateEndTurn();
}

Government::~Government()
{

}