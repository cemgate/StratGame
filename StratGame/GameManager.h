#pragma once
#include"FactoryManager.h"
#include"Player.h"
#include"BaseOfPlayer.h"

class GameManager
{
public:
	void startGame();
	void loadGameStatus();
	void saveGameStatus();
	void generateMap();

private:
	
	Player player1, player2;
	
	FactoryManager m_FactoryManager;
};

