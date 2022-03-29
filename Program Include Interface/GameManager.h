#pragma once
#include "Player.h"
#include "Board3x3.h"

class GameManager
{
protected:
	Board *Board3x3_1 = new Board3x3();
	Player Player_1;
	Player Player_2;
	char Symbol_1;
	char Symbol_2;
	int Match_Count;

public:
	GameManager();
	GameManager(Player, Player, char, char);
	void initialize();
	void turn(char);
	void play();
	char check_win();
};

