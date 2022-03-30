#include "RegulerObserver.h"

void RegulerObserver::update(int match_count, Player player1, Player player2)
{
	std::cout << "\nStatistika: " << std::endl;
	std::cout << "PLAYER 1 \n" << "Username: " << player1.get_username() << "\n" << "Win: " << player1.get_win_count() << std::endl << std::endl;
	std::cout << "PLAYER 2 \n" << "Username: " << player2.get_username() << "\n" << "Win: " << player2.get_win_count() << std::endl << std::endl;
	std::cout << "TOTAL MATCH: " << match_count << std::endl;
}

void RegulerObserver::notify_winner(Player player)
{
	std::cout << std::endl;
	std::cout << player.get_username() << " Win::YOU'RE THE WINNER" << std::endl;
}

void RegulerObserver::notify_losser(Player player)
{
	std::cout << std::endl;
	std::cout << player.get_username() << " Lose::YOU'RE LOSSER" << std::endl;
}