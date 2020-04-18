#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H

#include "player.h"

enum EGameResult{ WIN,LOST,DRAW };

class IGameStrategy
{
protected:
	virtual unsigned calCredit(const CPlayer& player) = 0;
public:
	// WIN for player1 win...
	virtual EGameResult judge(CPlayer& player1, CPlayer& player2) = 0;
};

class CAddRemaind6:public IGameStrategy
{
public:
	virtual unsigned calCredit(const CPlayer& player) override;
	virtual EGameResult judge(CPlayer& player1, CPlayer& player2) override;
};

class CMutRemaind6:public IGameStrategy
{
public:
	virtual unsigned calCredit(const CPlayer& player) override;
	virtual EGameResult judge(CPlayer& player1, CPlayer& player2) override;
};


#endif // !STRATEGY_H

