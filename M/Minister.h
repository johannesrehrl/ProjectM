#pragma once
#include <string>
#include <vector>
#include "Modifier.h"
#include "AbstractLoyality.h"
#include "AbstractPower.h"
#include "Window.h"
#include "AssetsHandler.h"

class Minister
{
private:
	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;
	std::string id;
	std::string name;
	int age;

	std::shared_ptr<AbstractLoyality> loyality;
	std::shared_ptr<AbstractPower> power;

public:
	Minister(std::string id, std::string name, int age, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);
	~Minister();
	void updateEndTurn();

	void setId(std::string id) { this->id = id; }
	void setName(std::string name) { this->name = name; }
	void setAge(int age) { this->age = age;  }

	std::string getId() { return this->id; }
	std::string getName() { return this->name; }
	int getAge() { return this->age; }

	std::shared_ptr<AbstractLoyality> getLoyality() { return loyality; }
	std::shared_ptr<AbstractPower> getPower() { return power; }
};