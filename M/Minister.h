#pragma once
#include <string>

class Minister
{
private:
	std::string id;
	std::string name;
	int age;

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
};