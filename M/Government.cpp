#include "Government.h"

Government::Government(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;

	this->president = std::make_shared<President>();
	this->financeMinistry = std::make_shared<FinanceMinistry>("Ministry of Finance", 
		std::make_shared<Minister>("dieter_arfeld", "Dieter Arfeld", 652, this->window, this->assetsHandler), this->window, this->assetsHandler);
	this->defenceMinistry = std::make_shared<FinanceMinistry>("Ministry of Defence",
		std::make_shared<Minister>("herman_klen", "Herman Klen", 554, this->window, this->assetsHandler), this->window, this->assetsHandler);
}

void Government::updateEndTurn()
{
	this->financeMinistry->updateEndTurn();
	this->defenceMinistry->updateEndTurn();
}

Government::~Government()
{

}