#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Settings
{
private:
	bool displayFps;
	bool useVSynch;
	std::ifstream loadFile;
	std::ofstream saveFile;

public:
	//Loads settings from the setting file at the start of the game.
	Settings();
	//Saves the settings to the settings file once the game is closed.
	~Settings();
	bool getDisplayFps() { return this->displayFps; }
	void setDisplayFps(bool val) { displayFps = val; }
	bool getUseVSynch() { return this->useVSynch; }
	void setUseVSynch(bool val) { useVSynch = val; }
};