#include "stdafx.h"
#include "Player.h"

Player::Player() {

}

Player::Player(std::string name, sockaddr_in addr)
{
	_name = name;
	_address = addr;
}

Player::~Player()
{

}