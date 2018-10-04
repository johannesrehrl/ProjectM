#pragma once
#include <string>

class GameState
{
public:
	virtual void update() = 0;
	virtual void handleInput() = 0;
	virtual void draw() = 0;
	virtual std::string getStateChange() = 0;
	~GameState() {}
};