#pragma once
#include"FactoryManager.h"
#include"Player.h"

class GameManager
{
public:
	void startGame();
	void loadGameStatus();
	void saveGameStatus();
private:
	Player player1, player2;
};

