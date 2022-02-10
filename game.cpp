#include <iostream>
#include "Game.h"


Game::Game() {
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	instantiatePlayers(player_1, player_2);
	deal();
};

void Game::instantiatePlayers(Player& p1, Player& p2) {
	p1.setName("PLAYER 1");
	p2.setName("PLAYER 2");
}

void Game::deal() {
	std::cout << "\n------------------------------------------------------------------------------\n";

	// deal to player 1
	for (int i = 0; i < deck.vCard.size(); i++) {
		if (i % 2 == 0) {
			Card card = deck.vCard[i];;
			player_1.pCards.push_back(card);
		}
	}
	// deal to player 2
	for (int i = 0; i < deck.vCard.size(); i++) {
		if (i % 2 != 0) {
			Card card = deck.vCard[i];
			player_2.pCards.push_back(card);
		}
	}
	std::cout << "\nPress ENTER to deal the cards to both players.\n";
	std::cin.get();
	printPlayersCards(player_1);
	printPlayersCards(player_2);
	std::cout << "\nPress ENTER to start the game.\n";
	std::cin.get();
}

void Game::printPlayersCards(Player& p) {
	std::cout << "\n\n\n" << p.getName() << " GETS:\n\n";
	for (int i = 0; i < p.pCards.size(); i++) {
		p.pCards[i].printCardName();

		/*i < 10 ? std::cout << " " << i << ")  " << p.pCards[i].getCardName()
			   : std::cout << i << ")  " << p.pCards[i].getCardName();*/
	}
}

void Game::startGame() {

	Card card_1;
	Card card_2;

	while (!hasWinner) {

		bool isEmpty = isDeckEmpty(player_1, player_2, 1);
		if (isEmpty) {
			hasWinner = true;
			if (player_1.pCards.size() > player_2.pCards.size()) {
				std::cout << "\n	" << player_1.getName() << " puts all of the cards from this round into its own deck." << std::endl;
				//system("color 04");
				SetConsoleTextAttribute(color, 4);
				std::cout << "\n	ULTIMATE WINNER IS " << player_1.getName() << std::endl;
				SetConsoleTextAttribute(color, 7);
			}
			else {
				std::cout << "\n	" << player_2.getName() << " puts all of the cards from this round into its own deck." << std::endl;
				//system("color 04");
				SetConsoleTextAttribute(color, 4);
				std::cout << "\n	ULTIMATE WINNER IS " << player_2.getName() << std::endl;
				SetConsoleTextAttribute(color, 7);
			}
			break;
		}


		SetConsoleTextAttribute(color, 2);
		std::cout << "\n\n  - ROUND " << round << " -\n\n";
		SetConsoleTextAttribute(color, 7);
		std::cout << "Player_1 deck size before move: " << player_1.pCards.size() << std::endl;
		std::cout << "Player_2 deck size before move: " << player_2.pCards.size() << std::endl;
		SetConsoleTextAttribute(color, 5);
		std::cout << "Player's 1 cards before move:\n" << player_1.printAllPlayersCards() << std::endl;
		SetConsoleTextAttribute(color, 6);
		std::cout << "Player's 2 cards before move:\n" << player_2.printAllPlayersCards() << std::endl;
		SetConsoleTextAttribute(color, 7);
		std::cout << "\nTake next card...\n" << std::endl;

		card_1 = player_1.pCards[0];
		std::cout << "  " << player_1.getName() << " picked up:	" << card_1.getCardName() << std::endl;
		card_2 = player_2.pCards[0];
		std::cout << "  " << player_2.getName() << " picked up:	" << card_2.getCardName() << std::endl;

		if (card_1.value > card_2.value) {
			std::cout << "  " << card_1.getCardName() << " is greater than " << card_2.getCardName() << std::endl;
			std::cout << "  " << player_1.getName() << " is a winner of " << round << ". round" << std::endl;
			player_1.pCards.erase(player_1.pCards.begin());
			player_1.pCards.push_back(card_1);
			player_2.pCards.erase(player_2.pCards.begin());
			player_1.pCards.push_back(card_2);
			round++;
		}
		else if (card_1.value < card_2.value) {
			std::cout << "  " << card_2.getCardName() << " is greater than " << card_1.getCardName() << std::endl;
			std::cout << "  " << player_2.getName() << " is a winner of " << round << ". round" << std::endl;
			player_2.pCards.erase(player_2.pCards.begin());
			player_2.pCards.push_back(card_2);
			player_1.pCards.erase(player_1.pCards.begin());
			player_2.pCards.push_back(card_1);
			round++;
		}
		else {
			// both players have same card value
			player_1.pCards.erase(player_1.pCards.begin());
			player_2.pCards.erase(player_2.pCards.begin());
			sameValuesCase(card_1, card_2, {}, {});
			round++;
		}
	}
}

bool Game::isDeckEmpty(Player& p1, Player& p2, int minimumSize) {
	if (p1.pCards.size() < minimumSize) {
		return true;
	}
	else if (p2.pCards.size() < minimumSize) {
		return true;
	}
	else {
		return false;
	}
}


int Game::sameValuesCase(Card& c1, Card& c2, std::vector<Card> deck1, std::vector<Card> deck2) {
	std::cout << "  Both cards are of same value. Each player must take 4 more cards from its own deck." << std::endl;

	std::vector<Card> tempDeck_1 = deck1;
	std::vector<Card> tempDeck_2 = deck2;
	// both cards of the same value are pushed back into a temp array
	tempDeck_1.push_back(c1);
	tempDeck_2.push_back(c2);

	bool isEmpty = isDeckEmpty(player_1, player_2, 4);
	if (isEmpty) {
		hasWinner = true;
		if (player_1.pCards.size() > player_2.pCards.size()) {
			std::cout << "\n  " << player_2.getName() << " does not have enough cards anymore." << std::endl;
			std::cout << "\n	" << player_1.getName() << " puts all of the cards from this round into its own deck." << std::endl;
			//system("color 04");
			SetConsoleTextAttribute(color, 4);
			std::cout << "\n	ULTIMATE WINNER IS " << player_1.getName() << std::endl;
			SetConsoleTextAttribute(color, 7);
		}
		else {
			std::cout << "\n  " << player_1.getName() << " does not have enough cards anymore." << std::endl;
			std::cout << "\n	" << player_2.getName() << " puts all of the cards from this round into its own deck." << std::endl;
			//system("color 04");
			SetConsoleTextAttribute(color, 4);
			std::cout << "\n	ULTIMATE WINNER IS " << player_2.getName() << std::endl;
			SetConsoleTextAttribute(color, 7);
		}
		return 0;
	}

	// each player must take 4 more cards from its own deck and put it into a temp array
	for (int i = 0; i < 4; i++) {
		c1 = player_1.pCards[0];	// 0 - from top of the deck
		c2 = player_2.pCards[0];
		tempDeck_1.push_back(c1);
		tempDeck_2.push_back(c2);
		// all 4 cards must be deleted from both players arrray
		player_1.pCards.erase(player_1.pCards.begin());
		player_2.pCards.erase(player_2.pCards.begin());
	}

	int lastIdx = tempDeck_1.size() - 1;
	// get both last cards from temp arrays
	Card lastCard_1 = tempDeck_1[lastIdx];
	Card lastCard_2 = tempDeck_2[lastIdx];

	std::cout << "  " << player_1.getName() << " picked up:	" << lastCard_1.getCardName() << std::endl;
	std::cout << "  " << player_2.getName() << " picked up:	" << lastCard_2.getCardName() << std::endl;


	// compare values of both last cards
	if (lastCard_1.value > lastCard_2.value) {
		std::cout << "  " << lastCard_1.getCardName() << " is greater than " << lastCard_2.getCardName() << std::endl;
		std::cout << "\n	" << player_1.getName() << " puts all of the cards from this round into its own deck." << std::endl;
		std::cout << "  " << player_1.getName() << " is a winner of " << round << ". round" << std::endl;
		for (int i = 0; i < tempDeck_1.size(); i++) {
			player_1.pCards.push_back(tempDeck_1[i]);
			player_1.pCards.push_back(tempDeck_2[i]);
		}
		// reassign temp arrays to its innitial values
		tempDeck_1 = {};
		tempDeck_2 = {};
	}
	else if (lastCard_2.value > lastCard_1.value) {
		std::cout << "  " << lastCard_2.getCardName() << " is greater than " << lastCard_1.getCardName() << std::endl;
		std::cout << "\n	" << player_2.getName() << " puts all of the cards from this round into its own deck." << std::endl;
		std::cout << "  " << player_2.getName() << " is a winner of " << round << ". round" << std::endl;
		for (int i = 0; i < tempDeck_2.size(); i++) {
			player_2.pCards.push_back(tempDeck_2[i]);
			player_2.pCards.push_back(tempDeck_1[i]);
		}
		// reassign temp arrays to its innitial values
		tempDeck_1 = {};
		tempDeck_2 = {};
	}
	else {
		// have to pop_back last card from temp array because it is pushed-in again in next recursive call (lastCard_1, lastCard_2)
		tempDeck_1.pop_back();
		tempDeck_2.pop_back();
		sameValuesCase(lastCard_1, lastCard_2, tempDeck_1, tempDeck_2);
	}

	return 1;
}
