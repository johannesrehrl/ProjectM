#pragma once
#include <string>

class Modifier
{
private:
	std::string id;
	std::string shortText;
	std::string longText;
	float value;
	bool finite;
	int duration;

public:
	Modifier(std::string id, std::string shortText, std::string longText, float value)
	{
		this->id = id; this->shortText = shortText; this->longText = longText; this->value = value; this->finite = false;
	}
	Modifier(std::string id, std::string shortText, std::string longText, float value, int duration)
	{
		this->id = id; this->shortText = shortText; this->longText = longText; this->value = value; this->finite = true; this->duration = duration;
	}
	~Modifier() {}

	void setId(std::string val) { this->id = val; }
	void setShortText(std::string val) { this->shortText = val; }
	void setLongText(std::string val) { this->longText = val; }
	void setText(float val) { this->value = val; }
	void setFinite(bool val) { this->finite = val; }
	void setDuration(int val) { this->duration = val; }

	std::string getId() { return this->id; }
	std::string getShortText() { return this->shortText; }
	std::string getLongText() { return this->longText; }
	float getValue() { return this->value; }
	bool isFinite() { return this->finite; }
	int getDuration() { return this->duration; }
};