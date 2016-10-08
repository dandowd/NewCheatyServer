#include "stdafx.h"
#include "Game.h"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

void Game::ParseMessage(std::string message) {
	
}

void Game::StartGame() {

	int playerCount = -1;
	bool serverFull = false;
	int players = 0;
	
	_players = { vector<Player>(players) };

	while (players != playerCount) {
		sockaddr_in si_buf;
		memset(&si_buf, '\0', sizeof(sockaddr_in));
		//receive
		string message = _netLayer.Receive(si_buf);

		if (players > 0) {
			//adding more players

			playerCount++;
		}
		else {
			//first player setup
			ParseMessage(message);
			Player one("one", si_buf);
			playerCount++;
		}
	}
}

void Game::GameLoop() {
	//recieve

	//update

	//send
}