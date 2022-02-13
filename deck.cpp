#include "Deck.h"


Deck::Deck() {
	setupCards();
	printAllCards();
	std::cout << "\nPress ENTER to shuffle the deck.\n";
	std::cin.get();
	shuffleCards(vCard);
	std::cout << "\nALREADY SHUFFLED CARDS:\n\n";
	printAllCards();
}

void Deck::setupCards() {
	std::cout << "\nALL CARDS IN THE DECK:\n\n";
	for (int col = (int)Suits::CLUBS; col <= (int)Suits::SPADES; col++) {
		for (int row = (int)Ranks::TWO; row <= (int)Ranks::ACE; row++) {
			Card card;
			card.suit = (Suits)col;
			card.rank = (Ranks)row;
			//card.value = (int)row;

			if (card.rank == Ranks::JACK) {
				card.value = 11;
			}
			else if (card.rank == Ranks::QUEEN) {
				card.value = 12;
			}
			else if (card.rank == Ranks::KING) {
				card.value = 13;
			}
			else if (card.rank == Ranks::ACE) {
				card.value = 14;
			}
			else {
				card.value = (int)card.rank;
			}

			vCard.push_back(card);
		}
	}
}

void Deck::printAllCards() {
	for (int col = (int)Suits::CLUBS; col <= (int)Suits::SPADES; col++) {
		for (int row = (int)Ranks::TWO; row <= (int)Ranks::ACE; row++) {
			int index = (col * 13) + row - 2;
			vCard[index].printCardName();
		}
		std::cout << std::endl;
	}
}

std::vector<Card> Deck::shuffleCards(std::vector<Card>& vector) {
	srand(time(NULL));
	for (int i = vector.size() - 1; i > 0; --i) {
		int idx = (rand() % i);
		Card temp = vector[i];
		vector[i] = vector[idx];
		vector[idx] = temp;
	}
	// repeats shuffle for 2 more times
	if (counter <= 2) {
		//std::cout << "SHUFFLE COUNTER: " << counter << "\n";
		counter++;
		shuffleCards(vector);
	}

	return vector;
}
