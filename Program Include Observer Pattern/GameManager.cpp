#include "GameManager.h"

GameManager::GameManager()
{
	Symbol_1 = 'S';
	Symbol_2 = 'S';
	Match_Count = 0;
}

GameManager::GameManager(Player Player_1, Player Player_2, char Symbol_1, char Symbol_2)
{
	this->Player_1 = Player_1;
	this->Player_2 = Player_2;
	this->Symbol_1 = Symbol_1;
	this->Symbol_2 = Symbol_2;
	Match_Count = 0;
}

void GameManager::initialize()
{
	Symbol_1 = 'X';
	Symbol_2 = 'O';
	Match_Count++;
	Board3x3_1->clear_board();
}

void GameManager::turn(char Symbol)
{
	int x, y;
	std::cout << "Insert a Symbol in Position (x,y)(Max 2): ";
	std::cin >> x >> y;

	if (x > 2 || y > 2)
	{
		std::cout << "ERROR::Invalid squere index input. Try insert another position." << std::endl;
		turn(Symbol);
	}

	if (Board3x3_1->get_value_at_index(x, y) == '0')
	{
		Board3x3_1->set_value_at_index(x, y, Symbol);
	}
	else
	{
		std::cout << "Squere is filled. Please insert another position." << std::endl;
		turn(Symbol);
	}
}

void GameManager::play()
{
	int step = 0;

	while (!Board3x3_1->is_full() && check_win() == 'F')
	{
		step++;
		// print board
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (Board3x3_1->get_value_at_index(x, y) != '0')
					std::cout << Board3x3_1->get_value_at_index(x, y) << "\t";
				else
					std::cout << "_\t";
			}
			std::cout << std::endl << std::endl;
		}

		if (step % 2 == 1) //player 1 turn
		{
			std::cout << std::endl;
			std::cout << Player_1.get_username() << "'s turn" << std::endl;
			turn(Symbol_1);
		}
		else //player 2 turn
		{
			std::cout << std::endl;
			std::cout << Player_2.get_username() << "'s turn" << std::endl;
			turn(Symbol_2);
		}
		std::cout << std::endl;
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (Board3x3_1->get_value_at_index(x, y) != '0')
				std::cout << Board3x3_1->get_value_at_index(x, y) << "\t";
			else
				std::cout << "_\t";
		}
		std::cout << std::endl << std::endl;
	}

	if (check_win() != 'F')
	{
		if (check_win() == Symbol_1)
		{
			Player_1.set_win_count(Player_1.get_win_count() + 1);
			reguler_observer->notify_winner(Player_1);
			reguler_observer->notify_losser(Player_2);
		}

		if (check_win() == Symbol_2)
		{
			Player_2.set_win_count(Player_2.get_win_count() + 1);
			reguler_observer->notify_winner(Player_2);
			reguler_observer->notify_losser(Player_1);
		}
	}
	else
	{
		std::cout << std::endl;
		std::cout << "MATCH DRAW" << std::endl;
	}

	reguler_observer->update(Match_Count, Player_1, Player_2);
}

char GameManager::check_win()
{
	if (Board3x3_1->check_similiar_value_horizontally() != '0')
		return Board3x3_1->check_similiar_value_horizontally();
	else if (Board3x3_1->check_similiar_value_vertically() != '0')
		return Board3x3_1->check_similiar_value_vertically();
	else if (Board3x3_1->check_similiar_value_sidely() != '0')
		return Board3x3_1->check_similiar_value_sidely();
	else
		return 'F';
}