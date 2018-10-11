#include "SetupState.h"

SetupState::SetupState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<PlayState> playState)
{
	this->stateChange = "";
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->playState = playState;

	this->playState->getResourceManager()->getInfluenceResource()->addInfluenceModifier
	(std::make_shared<ResourceModifier>("base", "Base influence per month.", 2));
	this->playState->getResourceManager()->getInfluenceResource()->addInfluenceModifier
	(std::make_shared<ResourceModifier>("coup_d_etat", "The recent coup d'etat leaves the nations administration in chaos.", -1, 6));

	this->playState->getResourceManager()->getNationalStability()->addStabilityModifier
	(std::make_shared<ResourceModifier>("base", "Base stability.", 50));
	this->playState->getResourceManager()->getNationalStability()->addStabilityModifier
	(std::make_shared<ResourceModifier>("coup_d_etat", "The recent coup d'etat leaves the nation unstable.", -20));

	//Temporary fix, may cause problems in the future.
	this->playState->getMainViewState()->updateEndTurn();

	//this->nameInputField = std::make_shared<TextInputField>(window, assetsHandler);
	//this->nameInputField->setFont(this->assetsHandler->getFontHolder()["expressway"]);
	//this->nameInputField->setSize(sf::FloatRect(100,100,400,60));
}

void SetupState::update()
{
	//this->nameInputField->update();
	this->stateChange = "PLAY";
}

void SetupState::handleInput()
{

}

void SetupState::draw()
{
	//this->nameInputField->draw();
}

SetupState::~SetupState()
{

}