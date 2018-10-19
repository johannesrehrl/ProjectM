#include "SetupState.h"

SetupState::SetupState(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler, std::shared_ptr<PlayState> playState)
{
	this->stateChange = "";
	this->window = window;
	this->assetsHandler = assetsHandler;
	this->playState = playState;

	this->playState->getResourceManager()->getInfluenceResource()->addInfluenceModifier
	(std::make_shared<ResourceModifier>("base", "Base influence", "Base influence per month.", 2));
	this->playState->getResourceManager()->getInfluenceResource()->addInfluenceModifier
	(std::make_shared<ResourceModifier>("coup_d_etat", "Coup d'etat", "The recent coup d'etat leaves the nations administration in chaos.", -1, 6));

	this->playState->getResourceManager()->getNationalStability()->addStabilityModifier
	(std::make_shared<ResourceModifier>("base", "Base stability", "Base stability.", 50));
	this->playState->getResourceManager()->getNationalStability()->addStabilityModifier
	(std::make_shared<ResourceModifier>("coup_d_etat", "Coup d'etat", "The recent coup d'etat leaves the nation unstable.", -20));

	this->nameInputField = std::make_shared<TextInputField>(window, assetsHandler);
	this->nameInputField->setFont(this->assetsHandler->getFontHolder()["aquifer"]);
	this->nameInputField->setSize(sf::FloatRect(100,150,500,50));

	this->inputLabelText.setFont(this->assetsHandler->getFontHolder()["aquifer"]);
	this->inputLabelText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->inputLabelText.setCharacterSize(25);
	this->inputLabelText.setString("Please enter your name:");
	this->inputLabelText.setPosition(sf::Vector2f(100,100));

	this->singButton = std::make_shared<Button>(this->assetsHandler, this->window, "Sign", Button::style::STANDARD, sf::Vector2f(350, 250));
	this->singButton->setOnSelect([this, playState] {
		this->stateChange = "PLAY";
		playState->getGovernment()->getPresident()->setName(this->getNameInputField()->getInput());

		//Temporary fix, may cause problems in the future.
		playState->getMainViewState()->updateEndTurn();
	});

	this->presidentialOrderSprite.setTexture(this->assetsHandler->getTextureHolder()["presidential-order-00001"]);
	this->presidentialOrderSprite.setPosition(this->window->getDesktop().front().width - 1000, 100);

	this->signatureText.setFont(this->assetsHandler->getFontHolder()["HomemadeApple"]);
	this->signatureText.setCharacterSize(28);
	this->signatureText.setFillColor(this->assetsHandler->getColorHolder()["black"]);
	this->signatureText.setPosition(this->window->getDesktop().front().width - 1000 + 220, 100 + 600);
}

void SetupState::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	this->nameInputField->update();
	this->singButton->update(mousePos);

	this->signatureText.setString(this->nameInputField->getInput());
	sf::FloatRect textRect = this->signatureText.getLocalBounds();
	this->signatureText.setOrigin(textRect.width / 2, textRect.top + textRect.height / 2);
}

void SetupState::handleInput()
{

}

void SetupState::draw()
{
	this->nameInputField->draw();
	this->singButton->draw();
	this->window->getWindow()->draw(this->inputLabelText);
	this->window->getWindow()->draw(this->presidentialOrderSprite);
	this->window->getWindow()->draw(this->signatureText);
}

SetupState::~SetupState()
{

}