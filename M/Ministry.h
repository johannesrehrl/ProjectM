#pragma once
#include <string>
#include "Minister.h"
#include "Modifier.h"
#include "Window.h"
#include "AssetsHandler.h"
#include "CorruptionRate.h"

class Ministry
{
protected:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::shared_ptr<Minister> minister;
	std::shared_ptr<CorruptionRate> corruptionRate;
	std::string name;

public:
	Ministry(std::string name, std::shared_ptr<Minister> minister, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~Ministry();

	virtual void updateEndTurn() = 0;

	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }

	void setMinister(std::shared_ptr<Minister> minister) { this->minister.reset(); this->minister = minister; }
	std::shared_ptr<Minister> getMinister() { return this->minister; }

	std::shared_ptr<CorruptionRate> getCorruptionRate() { return this->corruptionRate; }

	void recalcCorruption();
};