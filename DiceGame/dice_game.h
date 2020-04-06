#pragma once
#ifndef DICE_GAME
#define DICE_GAME
#include <string>
#include <iostream>
using namespace std;

unsigned int random(int x);

class CDiceGame
{
private:
	unsigned int m_firstRes;
	unsigned int m_secondRes;
	
protected:
	enum INFO_TYPE {COMMAND,START,ROLL,ROLL_RES1,ROLL_RES2,FINAL_RES,WIN,LOST,LEAVE,IMPROPER};
	void show_basic_info(const string &s) const
	{
		cout << endl << "SYSTEM INFO:" << endl
			<< s << endl
			<< "INFO FINISHED." << endl;
	}
	void show_info(INFO_TYPE infoType, const unsigned int infoValue = 0) const;
	void initial_game()
	{
		m_firstRes = 0;
		m_secondRes = 0;
	}
	char read_input() const
	{
		// TODO: READ EXCEPTION CATCH AND DISPOSE
		char input;
		cin >> input;
		return input;
	}
	void loop_game();
	void roll_dice();
	void cal_res();
public:
	CDiceGame();
	
	void startGame()
	{
		initial_game();
		loop_game();
	}
};

// class CDiceGamePlatform
// {
// private:
// 	static CDiceGame* uniqueGame;
// public:
// 	static CDiceGame& getGame()
// 	{
// 		if (uniqueGame == nullptr)
// 			uniqueGame = new CDiceGame;
// 		return *uniqueGame;
// 	}
// };




#endif
