#pragma once
#ifndef DICE_GAME
#define DICE_GAME
#include <list>
#include "player.h"

unsigned int random(int x);

class CDiceGame
{
private:
	list<CPlayer*>m_players;
public:
	CDiceGame();
	
	void startGame()
	{
		m_players.push_back(new CPlayer);
		m_players.back()->playGame();
	}
};



#endif
