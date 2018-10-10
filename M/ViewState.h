#pragma once
#include <string>

class ViewState
{
public:
	virtual void update() = 0;
	virtual void handleInput() = 0;
	virtual void draw() = 0;
	virtual std::string getStateChange() = 0;
	virtual void setStateChange(std::string state) = 0;
	~ViewState() {}
};