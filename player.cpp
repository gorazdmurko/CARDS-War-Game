#include "Player.h"


Player::Player() {};
Player::Player(std::string name) {
	this->pName = name;
};


std::string Player::getName() {
	return pName;
}

void Player::setName(std::string name) {
	this->pName = name;
}

std::string Player::printAllPlayersCards() {
	std::string allCards = "";
	for (int i = 0; i < pCards.size(); i++) {
		i == pCards.size() - 1 ? allCards += pCards[i].getCardName() :
			allCards += pCards[i].getCardName() + ", ";
	}
	return allCards;
}