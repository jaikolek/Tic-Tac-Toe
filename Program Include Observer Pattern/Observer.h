#pragma once
#include <iostream>
#include "Player.h"

class Observer
{
public:
	virtual void update(int, Player, Player) = 0;
	virtual void notify_winner(Player) = 0;
	virtual void notify_losser(Player) = 0;
};

