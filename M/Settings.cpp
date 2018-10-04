#include "Settings.h"

Settings::Settings()
{
	std::string line = "";
	this->loadFile.open("gamefiles\\settings.txt");
	//Fps displayal setting.
	this->loadFile >> line;
	this->displayFps = stoi(line.substr(line.find("=") + 1));
	//VSynch setting.
	this->loadFile >> line;
	this->useVSynch = stoi(line.substr(line.find("=") + 1));
	this->loadFile.close();
}

Settings::~Settings()
{
	this->saveFile.open("gamefiles\\settings.txt");
	//Fps displayal setting.
	this->saveFile << "displayFps=" << this->displayFps << std::endl;
	this->saveFile << "useVSynch=" << this->useVSynch << std::endl;
	this->saveFile.close();
}