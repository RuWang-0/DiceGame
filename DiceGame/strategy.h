#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H

#include "player.h"
#include "game_res.h"


class IGameStrategy
{
protected:
	virtual unsigned calCredit(const CPlayer& player) = 0;
public:
	// WIN for player1 win...
	virtual shared_ptr<CGameRes> judge(CPlayer& player1, CPlayer& player2) = 0;
};

class CAddRemaind6:public IGameStrategy
{
public:
	virtual unsigned calCredit(const CPlayer& player) override;
	virtual shared_ptr<CGameRes> judge(CPlayer& player1, CPlayer& player2) override;
};

class CMutRemaind6:public IGameStrategy
{
public:
	virtual unsigned calCredit(const CPlayer& player) override;
	virtual shared_ptr<CGameRes> judge(CPlayer& player1, CPlayer& player2) override;
};


#endif // !STRATEGY_H

