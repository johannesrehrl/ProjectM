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

	std::vector<std::shared_ptr<Modifier>> loyalityModifiers;

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

	void addModifier(std::shared_ptr<Modifier> mod) { this->loyalityModifiers.push_back(mod); }

	void subModifier(std::string id)
	{
		for (int i = 0; i < this->loyalityModifiers.size(); i++)
		{
			if (this->loyalityModifiers.at(i)->getId() == id)
			{
				this->loyalityModifiers.erase(loyalityModifiers.begin() + i);
			}
		}
	}
};