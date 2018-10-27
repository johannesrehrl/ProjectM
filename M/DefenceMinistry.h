#pragma once
#include "Ministry.h"
#include "Minister.h"
#include "Modifier.h"

class DefenceMinistry : public Ministry
{
private:


public:
	DefenceMinistry(std::string name, std::shared_ptr<Minister> minister);
	~DefenceMinistry();

	void updateEndTurn();
};