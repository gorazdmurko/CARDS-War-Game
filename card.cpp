#include <iostream>
#include "Card.h"

Card::Card() {};

void Card::printSuit() {
	if (suit == Suits::CLUBS) {
		std::cout << "clubs";
	}
	else if (suit == Suits::DIAMONDS) {
		std::cout << "diamonds";
	}
	else if (suit == Suits::HEARDS) {
		std::cout << "hearts";
	}
	else if (suit == Suits::SPADES) {
		std::cout << "spades";
	}
}

void Card::printValue() {
	if (name == Ranks::JACK) {
		std::cout << "JACK";
	}
	else if (name == Ranks::QUEEN) {
		std::cout << "QUEEN";
	}
	else if (name == Ranks::KING) {
		std::cout << "KING";
	}
	else if (name == Ranks::ACE) {
		std::cout << "ACE";
	}
	else {
		std::cout << (int)value;
	}
}

std::string Card::getSuit() {
	std::string cardSuit;
	if (suit == Suits::CLUBS) {
		cardSuit = "clubs";
	}
	else if (suit == Suits::DIAMONDS) {
		cardSuit = "diamonds";
	}
	else if (suit == Suits::HEARDS) {
		cardSuit = "hearts";
	}
	else if (suit == Suits::SPADES) {
		cardSuit = "spades";
	}
	return cardSuit;
}

std::string Card::getValue() {
	std::string cardValue;
	if (name == Ranks::JACK) {
		cardValue = "JACK";
	}
	else if (name == Ranks::QUEEN) {
		cardValue = "QUEEN";
	}
	else if (name == Ranks::KING) {
		cardValue = "KING";
	}
	else if (name == Ranks::ACE) {
		cardValue = "ACE";
	}
	else {
		cardValue = std::to_string((int)value);
	}
	return cardValue;
}

void Card::printCard() {
	printValue();
	std::cout << " of ";
	printSuit();
	std::cout << std::endl;
}

std::string Card::getCardName() {
	return getValue() + " of " + getSuit();
}
