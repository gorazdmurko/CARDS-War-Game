#include <iostream>
#include <stdlib.h>	// windows.h
#include "Game.h"


void helloMessage() {
	// prints out hello message to the console

	system("color 06");
	std::cout << "\n\n";
	std::cout << "  ****************************************************\n";
	std::cout << "  *                                                  *\n";
	std::cout << "  *          -- W A R  - of -   C A R D S --         *\n";
	std::cout << "  *                                                  *\n";
	std::cout << "  *                                                  *\n";
	std::cout << "  *           - developed by Gorazd Murko -          *\n";
	std::cout << "  *                                                  *\n";
	std::cout << "  ****************************************************\n";
}

void run() {
	helloMessage();
	std::cout << "\nPress ENTER to show all cards awailable.\n";
	std::cin.get();
	Game game;
	game.startGame();
}


int main(int argc, char* argv[]) {

	run();

	return 0;
}