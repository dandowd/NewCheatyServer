#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"

class Player
{
public:
	Player();
	Player(std::string, sockaddr_in);
	~Player();

private:
	struct sockaddr_in _address;
	std::string _name;
};



#endif // !PLAYER_H
