#pragma once
#include <string>

class Modifier
{
private:
	std::string id;
	std::string shortText;
	std::string longText;
	double value;
	bool finite;
	int duration;

public:
	Modifier(std::string id, std::string shortText, std::string longText, double value)
	{
		this->id = id; this->shortText = shortText; this->longText = longText; this->value = value; this->finite = false; this->duration = 0;
	}
	Modifier(std::string id, std::string shortText, std::string longText, double value, int duration)
	{
		this->id = id; this->shortText = shortText; this->longText = longText; this->value = value; this->finite = true; this->duration = duration;
	}
	Modifier(std::string id, std::string shortText, std::string longText, double value, bool finite, int duration)
	{
		this->id = id; this->shortText = shortText; this->longText = longText; this->value = value; this->finite = finite; this->duration = duration;
	}
	~Modifier() {}

	void setId(std::string val) { this->id = val; }
	void setShortText(std::string val) { this->shortText = val; }
	void setLongText(std::string val) { this->longText = val; }
	void setValue(float val) { this->value = val; }
	void setFinite(bool val) { this->finite = val; }
	void setDuration(int val) { this->duration = val; }

	std::string getId() { return this->id; }
	std::string getShortText() { return this->shortText; }
	std::string getLongText() { return this->longText; }
	double getValue() { return this->value; }
	bool isFinite() { return this->finite; }
	int getDuration() { return this->duration; }
};