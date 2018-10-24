#pragma once
#include <string>
#include <vector>
#include "Modifier.h"

class Minister
{
private:
	std::string id;
	std::string name;
	int age;
	float loyality;
	float power;

	std::vector<std::shared_ptr<Modifier>> loyalityModifiers;
	std::vector<std::shared_ptr<Modifier>> powerModifiers;

public:
	Minister(std::string id, std::string name, int age);
	~Minister();
	void updateEndTurn();

	void setId(std::string id) { this->id = id; }
	void setName(std::string name) { this->name = name; }
	void setAge(int age) { this->age = age;  }

	std::string getId() { return this->id; }
	std::string getName() { return this->name; }
	int getAge() { return this->age; }
	float getLoyality() { return this->loyality; }
	float getPower() { return this->power; }

	void addLoyalityModifier(std::shared_ptr<Modifier> mod) { this->loyalityModifiers.push_back(mod); }
	void addPowerModifier(std::shared_ptr<Modifier> mod) { this->powerModifiers.push_back(mod); }

	void subLoyalityModifier(std::string id);
	void subPowerModifier(std::string id);

	void recalcLoyality();
	void recalcPower();
};