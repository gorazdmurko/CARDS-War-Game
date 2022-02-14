#pragma once

#include <iostream>
#include <string>
#include <iostream>

enum Suits { CLUBS, DIAMONDS, HEARDS, SPADES };

enum Ranks {
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

class Card {
private:
	std::string name = getCardName();
public:
	Ranks rank;
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
	void printCardName();

	std::string getCardName();
};

