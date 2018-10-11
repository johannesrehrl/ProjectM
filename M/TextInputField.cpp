//
// Created by Thomas Lienbacher on 19.09.2018. (https://github.com/thomaslienbacher)
// Modified by Johannes Rehrl on 11.10.2018
//

#include "TextInputField.h"

TextInputField::TextInputField(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler)
{
	this->window = window;
	this->assetsHandler = assetsHandler;
}

void TextInputField::update() {
	time += this->window->getDeltaTime();

	if (time > BLINK_TIME) {
		time -= BLINK_TIME;
		showUnderscore = !showUnderscore;
	}

	sf::Event event;

	while (this->window->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode < 128) {
				if (event.text.unicode == 8) { // backspace
					if (raw.length() > 0) raw = raw.substr(0, raw.size() - 1);
					limitReached = false;
				}
				else if (event.text.unicode == 13) { // enter
					entered = true;
				}
				else {
					if (canCharFit() && !limitReached) raw += (char)event.text.unicode;
				}
			}
		}
	}
}

void TextInputField::draw() {
	if (text.getLocalBounds().width > (size.width - PADDING * 2)) {
		raw = raw.substr(0, raw.size() - 1);
		limitReached = true;
	}

	if (showUnderscore && canCharFit() && !limitReached) text.setString(raw + "_");
	else text.setString(raw);

	this->window->getWindow()->draw(box);
	this->window->getWindow()->draw(text);
}

inline bool TextInputField::canCharFit() {
	return text.getLocalBounds().width < (size.width - PADDING * 2);
}

std::string TextInputField::getInput() {
	return raw;
}

void TextInputField::setFont(sf::Font &font) {
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
}

void TextInputField::setSize(sf::FloatRect floatRect) {
	size = floatRect;

	box.setFillColor(sf::Color::White);
	box.setOutlineColor(sf::Color::Black);
	box.setOutlineThickness(5.0f);
	box.setPosition(size.left, size.top);
	box.setSize({ size.width, size.height });

	text.setPosition(size.left + PADDING, size.top + size.height / 2 - text.getCharacterSize() / 2);
}
bool TextInputField::isEntered() const {
	return entered;
}