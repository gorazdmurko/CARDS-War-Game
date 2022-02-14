#pragma once
#include <windows.h>
#include <iostream>

#include "Player.h"
#include "Deck.h"


class Game {
private:
	int round = 1;
	bool hasWinner = false;
	HANDLE color;
public:
	Deck deck;
	Player player_1;
	Player player_2;

	// constructor
	Game();

	/**
	* @brief instantiates both player names
	*/
	void instantiatePlayers(Player& p1, Player& p2);

	/**
	* @brief distributes same number of cards to both players
	*/
	void deal();

	void printPlayersCards(Player& p);

	/**
	* @brief starts a game loop
	*/
	void startGame();

	bool isDeckEmpty(Player& p1, Player& p2, int minimumSize);

	int sameValuesCase(Card& c1, Card& c2, std::vector<Card> deck1, std::vector<Card> deck2);
};
