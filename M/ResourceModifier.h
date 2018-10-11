#pragma once
#include <string>

class ResourceModifier
{
private:
	std::string id;
	std::string text;
	float value;
	bool finite;
	int duration;

public:
	ResourceModifier(std::string id, std::string text, float value) { this->id = id; this->text = text; this->value = value; this->finite = false; }
	ResourceModifier(std::string id, std::string text, float value, int duration) { this->id = id; this->text = text; this->value = value;
	this->finite = true; this->duration = duration;}
	~ResourceModifier(){}

	void setId(std::string val) { this->id = val; }
	void setText(std::string val) { this->text = val; }
	void setText(float val) { this->value = val; }
	void setFinite(bool val) { this->finite = val; }
	void setDuration(int val) { this->duration = duration; }

	std::string getId() { return this->id; }
	std::string getText() { return this->text; }
	float getValue() { return this->value; }
	bool isFinite() { return this->finite; }
	int getDuration() { return this->duration; }
};