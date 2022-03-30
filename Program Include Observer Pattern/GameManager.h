#pragma once
#include "Player.h"
#include "Board3x3.h"
#include "RegulerObserver.h"

class GameManager
{
protected:
	Board *Board3x3_1 = new Board3x3();
	Observer *reguler_observer = new RegulerObserver();
	Player Player_1;
	Player Player_2;
	char Symbol_1;
	char Symbol_2;
	int Match_Count;

public:
	GameManager();
	GameManager(Player, Player, char, char);
	
	std::string get_player_1_username();
	std::string get_player_2_username();
	int get_match_count();

	// game
	void initialize();
	void turn(char);
	void play();
	char check_win();
};

