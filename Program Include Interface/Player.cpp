#include "Player.h"

Player::Player()
{
	Name = "Name";
	Win_Count = 0;
}

Player::Player(std::string Name)
{
	this->Name = Name;
	Win_Count = 0;
}

void Player::set_username(std::string Name)
{
	this->Name = Name;
}

std::string Player::get_username()
{
	return Name;
}

void Player::set_win_count(int Win_Count)
{
	this->Win_Count = Win_Count;
}

int Player::get_win_count()
{
	return Win_Count;
}