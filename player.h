#pragma once

#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
	std::string pName;
public:
	std::vector<Card> pCards = {};

	Player();
	Player(std::string name);

	std::string getName();

	void setName(std::string name);
	std::string printAllPlayersCards();
};
