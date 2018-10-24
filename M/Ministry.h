#pragma once
#include <string>
#include "Minister.h"
#include "Modifier.h"

class Ministry
{
protected:
	std::shared_ptr<Minister> minister;
	std::string name;
	float corruption;

public:
	Ministry(std::string name, std::shared_ptr<Minister> minister, float corruption) {
		this->name = name; 
		this->minister = minister;
		this->corruption = corruption;
	}
	~Ministry(){}

	virtual void updateEndTurn() = 0;

	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }

	void setMinister(std::shared_ptr<Minister> minister) { this->minister.reset(); this->minister = minister; }
	std::shared_ptr<Minister> getMinister() { return this->minister; }
};