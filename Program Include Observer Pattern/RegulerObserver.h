#pragma once
#include "Observer.h"

class RegulerObserver : public Observer
{
public:
	void update(int, Player, Player);
	void notify_winner(Player);
	void notify_losser(Player);
};

