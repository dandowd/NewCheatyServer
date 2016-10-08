#pragma once

#ifndef GAME_H
#define GAME_H

#include "Network.h"
#include "Player.h"
#include <vector>

class Game
{
public:
	void Game::StartGame();
	void Game::GameLoop();
	Game();
	~Game();

private:
	void Game::ParseMessage(std::string);
	string* Game::Split(std::string);
	std::vector<Player> _players;
	Network _netLayer;
};


#endif // !GAME_H