#pragma once

#include <vector>
#include <iostream>
#include "Card.h"

class Deck {
private:
	int counter = 0;
public:
	std::vector<Card> vCard = {};
public:
	Deck();

	/**
	* @brief sets up a deck of cards as a vector
	*/
	void setupCards();

	/**
	 * @brief prints out all cards by names and values
	 *
	 */
	void printAllCards();

	/**
	 * @brief randomly shuffles a deck of cards
	 *
	 * @param std::vector accepts a card of typename Card as an argument
	 * @return std::vector<Card>
	 */
	std::vector<Card> shuffleCards(std::vector<Card>& vector);
};
