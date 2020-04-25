#pragma once
#ifndef MESSAGE_PRINT
#define MESSAGE_PRINT
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::endl;
using std::cout;

class CMessagePrint
{
private:
	static void printAtom(string s)
	{
		cout<<s<<endl<<endl;
	}
	static void printWin(const string &player1, const string &player2, unsigned round, unsigned player1_score, unsigned player2_score)
	{
		string s=player1+"Win! "+player2+" Lose.\n"+player1+"'s score is "+to_string(player1_score)+
		", and "+player2+"'s score is "+to_string(player2_score);
		if(round)
			s= "In round "+to_string(round)+", "+s;
		printAtom(s);
	}
	static void printDraw(unsigned round, unsigned score)
	{
		string s="you draw.\n The scores are both "+to_string(score)+".";
		if(round)
			s= "In round "+to_string(round)+", "+s;
		printAtom(s);
	}
public:
	static void printWelcome()
	{
		printAtom("Let's start playing games!");
	}
	static void printBye()
	{
		printAtom( "BYE-BYE!" );
	}
	static void printStrategy()
	{
		string s="There are 2 built-in strategies to choose.\n 0: Roll dice twice. Compare the remainder of 6 after sum the dice result up."
		"\n1:Roll dice twice. Compare the remainder of 6 after multiplying the dice result.\n"
		"Please input 0/1 for selection.";
		printAtom(s);
	}
	static void printRoundCommand()
	{
		printAtom("Please input your command('s' to start, 'q' to quit)");
	}
	static void printCommand()
	{
		printAtom("Please input your command('r' to roll the dice ,'q' to quit)");
	}
	static void printDiceRes(const string &player1, const string &player2, const unsigned res_1, const unsigned res_2)
	{
		string s="The dices displace that:\n "+player1+"'s dice shows "+to_string(res_1)+", "+player2+"'s dice shows "+to_string(res_2);
		printAtom(s);
	}
	static void printRes(const CGameRes& result, const string& player1, const string& player2, unsigned round=0)
	{
		switch (result.getRes())
			{
			case CGameRes::WIN:
				printWin(player1,player2,round, result.getPlayer1Res(),result.getPlayer2Res());
				break;
			case CGameRes::LOSE:
				printWin(player2,player1,round,result.getPlayer2Res(),result.getPlayer1Res());
				break;
			case CGameRes::DRAW:
				printDraw(round,result.getRes());
				break;
			}
	}
	static void printHisRes(const vector<CGameRes> &results,const string &player1, const string &player2)
	{
		for(unsigned round=0;round<results.size();++round)
		{
			printRes(results[round],player1,player2,round+1);
		}
	}
	
};

#endif // !MESSAGE_PRINT
