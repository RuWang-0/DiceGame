#pragma once
#ifndef GAME_TABLE_H
#define GAME_TABLE_H
#include "player.h"
#include "strategy.h"
#include "game_res.h"


class CGameTable
{
private:
	shared_ptr<CPlayer>m_player1, m_player2;
	enum ETableState{CLOSED,WAITING,PLAYING};
	ETableState m_table_state;
	unsigned m_game_round;	// indicate how many times dices have been rolled during a round
	unsigned m_round;
	vector<CGameRes>m_history_result;
	IGameStrategy *m_game_strategy;

protected:
	virtual ~CGameTable()
	{
		delete m_game_strategy;
	}
	unsigned inputStrategy() const;
	void setStrategy();
	char inputCommand() const;
	char inputRoundCommand()const;
	void refreshTable();
	bool dealCommand(const char command);
	void rollDices(unsigned *res_1, unsigned *res_2);
	bool showResult(unsigned res_1,unsigned res_2,unsigned round);
	void showHisResult()const;
	void dealFinal();

public:
	CGameTable() { m_player1 = m_player2 = nullptr; m_table_state = CLOSED; m_game_round=0; m_round=0; m_game_strategy=nullptr;}

	bool joinTable(shared_ptr<CPlayer>player);

	void startGame();
	
};

#endif // !GAME_TABLE_H

