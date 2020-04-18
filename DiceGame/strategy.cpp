#include "strategy.h"

EGameResult CAddRemaind6::judge(CPlayer& player1, CPlayer& player2)
{
	unsigned res_player1 = calCredit(player1), res_player2 = calCredit(player2);
	if (res_player1 < res_player2)
		return LOST;
	if (res_player1 > res_player2)
		return WIN;
	return DRAW;
}

EGameResult CMutRemaind6::judge(CPlayer& player1, CPlayer& player2)
{
	unsigned res_player1 = calCredit(player1), res_player2 = calCredit(player2);
	if (res_player1 < res_player2)
		return LOST;
	if (res_player1 > res_player2)
		return WIN;
	return DRAW;
}

unsigned CAddRemaind6::calCredit(const CPlayer& player)
{
	unsigned sum = 0;
	vector<CDice>dices = player.getDices();
	for (auto dice : dices)
		sum += dice.getVal();
	return sum % 6;
}

unsigned CMutRemaind6::calCredit(const CPlayer& player)
{
	unsigned res = 1;
	vector<CDice>dices = player.getDices();
	for (auto dice : dices)
		res *= dice.getVal();
	return res % 6;
}


