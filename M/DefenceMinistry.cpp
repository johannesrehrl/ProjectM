#include "DefenceMinistry.h"

DefenceMinistry::DefenceMinistry(std::string name, std::shared_ptr<Minister> minister) : Ministry(name, minister)
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