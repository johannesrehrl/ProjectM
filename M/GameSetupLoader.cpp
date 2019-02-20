#include "GameSetupLoader.h"

GameSetupLoader::GameSetupLoader(std::shared_ptr<PlayState> playState, std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->playState = playState;
	this->window = window;
	this->assetsHandler = assetsHandler;
}

void GameSetupLoader::load()
{
	this->loadMinisters();
}

void GameSetupLoader::loadMinisters()
{
	nlohmann::json loadedJson;

	this->loadingStream.open("gamefiles\\data\\ministers\\ministers.json");
	loadedJson = nlohmann::json::parse(loadingStream);
	this->loadingStream.close();

	for (int i = 0; i < loadedJson["allMinisters"].size(); i++)
	{
		std::shared_ptr<Minister> min = std::make_shared<Minister>(
			loadedJson["allMinisters"].at(i)["id"],
			loadedJson["allMinisters"].at(i)["name"],
			loadedJson["allMinisters"].at(i)["age"],
			loadedJson["allMinisters"].at(i)["available"],
			this->window,
			this->assetsHandler
			);

		for (int x = 0; x < loadedJson["allMinisters"].at(i)["loyality"]["loyalityModifiers"].size(); x++)
		{
			min->getLoyality()->addLoyalityModifier(std::make_shared<Modifier>(
				loadedJson["allMinisters"].at(i)["loyality"]["loyalityModifiers"].at(x)["id"],
				loadedJson["allMinisters"].at(i)["loyality"]["loyalityModifiers"].at(x)["shortText"],
				loadedJson["allMinisters"].at(i)["loyality"]["loyalityModifiers"].at(x)["longText"],
				loadedJson["allMinisters"].at(i)["loyality"]["loyalityModifiers"].at(x)["value"],
				loadedJson["allMinisters"].at(i)["loyality"]["loyalityModifiers"].at(x)["finite"],
				loadedJson["allMinisters"].at(i)["loyality"]["loyalityModifiers"].at(x)["duration"]
				));
		}

		for (int x = 0; x < loadedJson["allMinisters"].at(i)["power"]["powerModifiers"].size(); x++)
		{
			min->getPower()->addPowerModifier(std::make_shared<Modifier>(
				loadedJson["allMinisters"].at(i)["power"]["powerModifiers"].at(x)["id"],
				loadedJson["allMinisters"].at(i)["power"]["powerModifiers"].at(x)["shortText"],
				loadedJson["allMinisters"].at(i)["power"]["powerModifiers"].at(x)["longText"],
				loadedJson["allMinisters"].at(i)["power"]["powerModifiers"].at(x)["value"],
				loadedJson["allMinisters"].at(i)["power"]["powerModifiers"].at(x)["finite"],
				loadedJson["allMinisters"].at(i)["power"]["powerModifiers"].at(x)["duration"]
				));
		}

		this->playState->getMinisterManager()->addMinister(min);
	}
}

void GameSetupLoader::loadEvents()
{
	nlohmann::json loadedJson;

	this->loadingStream.open("gamefiles\\data\\events\\events.json");
	loadedJson = nlohmann::json::parse(loadingStream);
	this->loadingStream.close();

	for (int i = 0; i < loadedJson["allEvents"].size(); i++)
	{	
		
	}
}

GameSetupLoader::~GameSetupLoader()
{

}