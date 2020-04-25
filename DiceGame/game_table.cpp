#include "game_table.h"
#include "message_print.h"

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

void CGameTable::startGame()
{
	CMessagePrint::printWelcome();
	setStrategy();
	bool tag=true;
	while (m_table_state!=CLOSED)
	{
		if(tag)
			tag = dealCommand(inputRoundCommand());
		else
			tag = dealCommand(inputCommand());
	}
}

bool CGameTable::dealCommand(const char command)
{
	unsigned *res_1=nullptr,*res_2=nullptr;
	switch (command)
	{
	case 'q':
		m_table_state=CLOSED;
		showHisResult();
		refreshTable();
		return true;
	case 's':
		m_player1->initialize();
		m_player2->initialize();
		return false;
	case 'r':
		rollDices(res_1,res_2);
		return showResult(*res_1,*res_2,m_game_round);
	}
}

void CGameTable::rollDices(unsigned *res_1, unsigned *res_2)
{
	*res_1=m_player1->rollDice(m_game_round);
	*res_2=m_player2->rollDice(m_game_round);	
	++m_game_round;
}

bool CGameTable::showResult(unsigned res_1, unsigned res_2, unsigned round)
{
	CMessagePrint::printDiceRes(m_player1->getName(),m_player2->getName(),res_1,res_2);
	if(round>=2)
	{
		dealFinal();
		return true;
	}
	return false;
}

void CGameTable::dealFinal()
{
	auto res = m_game_strategy->judge(*m_player1,*m_player2);
	m_history_result.push_back(*res);
	CMessagePrint::printRes(*res,m_player1->getName(),m_player2->getName());
	m_game_round=0;
}

void CGameTable::showHisResult() const
{
	if(!m_history_result.empty())
		CMessagePrint::printHisRes(m_history_result,m_player1->getName(),m_player2->getName());
}

void CGameTable::setStrategy()
{
	const unsigned res = inputStrategy();
	switch (res)
	{
	case 0:
		m_game_strategy = new CAddRemaind6;
		return;
	case 1:
		m_game_strategy = new CMutRemaind6;
		return;
	}
}

char CGameTable::inputRoundCommand() const
{
	CMessagePrint::printRoundCommand();
	char res;
	cin>>res;
	return res;
}

char CGameTable::inputCommand() const
{
	CMessagePrint::printCommand();
	char res;
	cin>>res;
	return res;
}

unsigned CGameTable::inputStrategy() const
{
	CMessagePrint::printStrategy();
	unsigned res;
	cin>>res;
	return res;
}

void CGameTable::refreshTable()
{
	m_player1=m_player2=nullptr;
	delete m_game_strategy;
	m_game_strategy = nullptr;
	m_table_state=CLOSED;
	m_history_result.clear();
	m_round=0;
	m_game_round = 0;
}

