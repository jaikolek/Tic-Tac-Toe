#pragma once
#include <iostream>
#include "Board.h"

class Board3x3 : public Board
{
protected:
	char It_Board[3][3];

public:
	Board3x3();
	// full?
	bool is_full();
	bool is_empty();
	// setting value
	char get_value_at_index(int, int);
	void set_value_at_index(int, int, char);
	// checking
	char check_similiar_value_vertically();
	char check_similiar_value_horizontally();
	char check_similiar_value_sidely();
	~Board3x3();
};

