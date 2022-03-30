#pragma once
#include <iostream>

class Player
{
protected:
	std::string Name;
	int Win_Count;

public:
	Player();
	Player(std::string);
	// setting username
	void set_username(std::string);
	std::string get_username();
	// setting win
	void set_win_count(int);
	int get_win_count();
};

