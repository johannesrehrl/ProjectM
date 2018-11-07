#pragma once
#include "Ministry.h"
#include "Minister.h"
#include "Modifier.h"

class DefenceMinistry : public Ministry
{
private:


public:
	DefenceMinistry(std::string name, std::shared_ptr<Minister> minister, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~DefenceMinistry();

	void updateEndTurn();
};