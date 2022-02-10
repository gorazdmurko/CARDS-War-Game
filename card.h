#pragma once

#include <string>

enum Suits { CLUBS, DIAMONDS, HEARDS, SPADES };

enum Ranks {
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

class Card {
public:
	Ranks name;
	Suits suit;
	int value;

	Card();

	void printSuit();

	void printValue();

	std::string getSuit();

	std::string getValue();

	/**
	 * @brief prints out card's name coupled by its value
	 *
	 */
	void printCard();

	std::string getCardName();
};

