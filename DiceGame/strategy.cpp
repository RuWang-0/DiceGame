#include "strategy.h"

shared_ptr<CGameRes> CAddRemaind6::judge(CPlayer& player1, CPlayer& player2)
{
	unsigned res_player1 = calCredit(player1), res_player2 = calCredit(player2);
	shared_ptr<CGameRes>res(new CGameRes);
	res->setRes(res_player1,res_player2);
	return res;
}

shared_ptr<CGameRes> CMutRemaind6::judge(CPlayer& player1, CPlayer& player2)
{
	unsigned res_player1 = calCredit(player1), res_player2 = calCredit(player2);
	shared_ptr<CGameRes>res(new CGameRes);
	res->setRes(res_player1,res_player2);
	return res;
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


