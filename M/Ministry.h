#pragma once
#include <string>
#include "Minister.h"

class Ministry
{
protected:
	std::shared_ptr<Minister> minister;
	std::string name;
	float loyality;
	float corruption;

public:
	Ministry(std::string name, std::shared_ptr<Minister> minister, float loyality, float corruption) {
		this->name = name; 
		this->minister = minister;
		this->loyality = loyality;
		this->corruption = corruption;
	}
	~Ministry(){}

	virtual void updateEndTurn() = 0;

	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }

	void setMinister(std::shared_ptr<Minister> minister) { this->minister.reset(); this->minister = minister; }
	std::shared_ptr<Minister> getMinister() { return this->minister; }

	void setLoyality(float loyality) { this->loyality = loyality; }
	float getLoyality() { return this->loyality; }

	void setCorruption(float corruption) { this->corruption = corruption; }
	float getCorruption() { return this->corruption; }
};