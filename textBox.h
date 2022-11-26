#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define DELETE_KEY 8
#define ENTER_KEY 13

class textBox {
private:
	sf::Text text;
	std::ostringstream input;
	bool isSelected;

	void inputLog(int charTyped) {
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY)
			input << static_cast<char>(charTyped);

		else if (charTyped == DELETE_KEY) {
			if (input.str().length() > 0) {
				deleteLast();
			}
		}

		text.setString(input.str() + "|");

	}

	void deleteLast() {
		std::string t = input.str();
		std::string newT = "";

		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}

		input.str("");
		input << newT;

		text.setString(input.str());
	}

public:
	textBox(){}

	textBox(bool sel) {
		text.setCharacterSize(25);
		text.setColor(sf::Color::Black);
		isSelected = sel;
		if (sel)
			text.setString("|");

		else
			text.setString("");
	}

	void setFont(sf::Font& font) {
		text.setFont(font);
	}

	void setPosition(sf::Vector2f pos) {
		text.setPosition(pos);
	}

	void setSelected(bool sel) {
		isSelected = sel;
		if (!sel && !input.str().empty()) {
			std::string t = input.str();
			std::string newT = "";

			for (int i = 0; i < t.length(); i++) {
				newT += t[i];
			}
			text.setString(newT);
		}

		else if (sel) {
			text.setString(input.str() + "|");
		}
	}

	std::string getText() {
		return input.str();
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(text);
	}

	void typedOn(sf::Event in) {
		if (isSelected) {
			int charTyped = in.text.unicode;
			if (charTyped < 128)
				inputLog(charTyped);
			
		}
	}
};
