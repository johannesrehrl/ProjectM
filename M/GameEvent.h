#pragma once
#include <string>
#include <vector>
#include <functional>

class GameEvent
{
private:
	std::string id;
	std::string headline;
	std::string text;
	std::vector<std::string> optionText;
	std::vector<std::function<void()>> checkFire;
	std::vector<std::function<void()>> allResults;

public:
	GameEvent(std::string id,
		std::string headline,
		std::string text,
		std::vector<std::string> optionText,
		std::vector<std::function<void()>> checkFire,
		std::vector<std::function<void()>> allResults);
	~GameEvent();
};