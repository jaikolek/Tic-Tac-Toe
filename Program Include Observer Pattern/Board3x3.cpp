#include "Board3x3.h"

Board3x3::Board3x3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			It_Board[i][j] = '0';
		}
	}
}

bool Board3x3::is_full()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (It_Board[i][j] == '0')
				return false;
		}
	}
	return true;
}

bool Board3x3::is_empty()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (It_Board[i][j] != '0')
				return false;
		}
	}
	return true;
}

void Board3x3::clear_board()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			It_Board[i][j] = '0';
		}
	}
}

char Board3x3::get_value_at_index(int x, int y)
{
	return It_Board[x][y];
}

void Board3x3::set_value_at_index(int x, int y, char Symbol)
{
	It_Board[x][y] = Symbol;
}

char Board3x3::check_similiar_value_vertically()
{
	for (int i = 0; i < 3; i++) 
	{
		if (It_Board[0][i] != '0' && It_Board[0][i] == It_Board[1][i] && It_Board[0][i] == It_Board[2][i])
			return It_Board[0][i];
	}

	return '0';
}

char Board3x3::check_similiar_value_horizontally()
{
	for (int i = 0; i < 3; i++) 
	{
		if (It_Board[i][0] != '0' && It_Board[i][0] == It_Board[i][1] && It_Board[i][0] == It_Board[i][2])
			return It_Board[i][0];
	}

	return '0';
}

char Board3x3::check_similiar_value_sidely()
{
	if (It_Board[0][0] != '0' && It_Board[0][0] == It_Board[1][1] && It_Board[0][0] == It_Board[2][2])
	{
		return It_Board[0][0];
	}
	else if (It_Board[0][2] != '0' && It_Board[0][2] == It_Board[1][1] && It_Board[2][0] == It_Board[0][2])
	{
		return It_Board[0][2];
	}
	else
	{
		return '0';
	}
}

Board3x3::~Board3x3()
{

}