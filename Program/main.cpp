#include "GameManager.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::string name;
	
	std::cout << "MELAMELA TIC TAC TOE, LET'S PLAY\n" << std::endl;

	std::cout << "Player 1 [X] Set a Username: ";
	std::cin >> name;
	Player player_1(name);
	std::cout << "Player 2 [O] Set a Username: ";
	std::cin >> name;
	Player player_2(name);

	GameManager gamemanager(player_1, player_2, 'X', 'O'); std::cout << std::endl;

	gamemanager.initialize(); std::cout << std::endl;
	gamemanager.play();

	std::cin.get();
	return 0;
}