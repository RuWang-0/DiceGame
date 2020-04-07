#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"

class CPlayer
{
private:
	CDice m_dice1, m_dice2;
	bool m_isFinished, m_isWon;
	char m_curCommand;
protected:
	char readCommand();
public:
	CPlayer() :m_isFinished(false), m_isWon(false) {};
	void playGame();
	
};










#endif




