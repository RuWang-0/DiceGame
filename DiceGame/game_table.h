#pragma once
#ifndef GAME_TABLE_H
#define GAME_TABLE_H
#include "player.h"
#include "strategy.h"


class CGameTable
{
private:
	shared_ptr<CPlayer>m_player1, m_player2;
	enum ETableState{CLOSED,WAITING,PLAYING};
	ETableState m_table_state;
	unsigned m_round;
	vector<EGameResult>m_history_result;

public:
	CGameTable() { m_player1 = m_player2 = nullptr; m_table_state = CLOSED; }

	bool joinTable(shared_ptr<CPlayer>player);
	
};

#endif // !GAME_TABLE_H

