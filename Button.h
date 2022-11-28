#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>

class Button {
private: 
	sf::RectangleShape button;
	sf::Text text;

public:

	Button() {}

	Button(std::string bText, sf::Vector2f size, int charSize) {
		text.setString(bText);
		text.setColor(sf::Color::Black);
		text.setCharacterSize(charSize);

		button.setSize(size);
		button.setFillColor(sf::Color(220, 220, 220));
		button.setOutlineThickness(2.f);
		button.setOutlineColor(sf::Color(90, 90, 90));
	}

	void setFont(sf::Font& font) {
		text.setFont(font);
	}

	void setPosition(sf::Vector2f pos) {
		button.setPosition(pos);

		float x = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
		float y = -10 + (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);

		text.setPosition( { x, y } );
	}

	void setBgColor(sf::Color color) {
		button.setFillColor(color);
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(button);
		window.draw(text);
	}

	bool isMouseTouching(sf::RenderWindow& window) {
		auto mousePos = sf::Mouse::getPosition(window);

		if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			return true;
		}

		return false;
	}

		
};