#include "DefenceMinistry.h"

DefenceMinistry::DefenceMinistry(std::string name, std::shared_ptr<Minister> minister, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler) : Ministry(name, minister, window, assetsHandler)
{

}

void DefenceMinistry::updateEndTurn()
{
	this->recalcCorruption();

	this->minister->updateEndTurn();
	this->corruptionRate->updateEndTurn();
}

DefenceMinistry::~DefenceMinistry()
{

}