#include "game_table.h"

//TODO:thread security
bool CGameTable::joinTable(shared_ptr<CPlayer> player)
{
	switch (m_table_state)
	{
	case CLOSED:
		m_player1 = player;
		m_table_state = WAITING;
		return true;
	case WAITING:
		m_player2 = player;
		m_table_state = PLAYING;

		return true;
	case PLAYING:
	default:
		return false;
	}
}
