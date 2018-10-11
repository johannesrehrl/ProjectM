//
// Created by Thomas Lienbacher on 19.09.2018. (https://github.com/thomaslienbacher)
// Modified by Johannes Rehrl on 11.10.2018
//

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.h"
#include "AssetsHandler.h"

class TextInputField {
	static constexpr float BLINK_TIME = 0.35f;
	static constexpr float PADDING = 6.0f;

	std::shared_ptr<Window> window;
	std::shared_ptr<AssetsHandler> assetsHandler;

	std::string raw;
	sf::Text text;
	sf::RectangleShape box;
	sf::FloatRect size;
	float time = 0;
	bool limitReached = false;
	bool showUnderscore = false;
	bool entered = false;

	inline bool canCharFit();

public:
	TextInputField(std::shared_ptr<Window> window, std::shared_ptr<AssetsHandler> assetsHandler);

	void update();
	void draw();
	std::string getInput();

	void setFont(sf::Font &font);
	void setSize(sf::FloatRect floatRect);

	bool isEntered() const;
};