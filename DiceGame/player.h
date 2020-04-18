#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CPlayer
{
private:
	enum ESessionState { OFFLINE, ONLINE, PREPARED, PLAYING };
	static unsigned undefined_name_num;		//TODO: need to ensure thread security
	static const unsigned WinVal;
	static const unsigned DiceNum;
	vector<CDice>m_dices;
	bool m_isFinished, m_isWon;
	unsigned m_turn_round;
	char m_curCommand;
protected:
	string name;
	char inputCommand();
	void printWelcome() {
		cout << "Let's start playing games!" << endl << endl;
	}
	void printBye() {
		cout << "BYE-BYE!" << endl << endl;
	}
	void initialize() {
		m_turn_round = m_isFinished = m_isWon = 0;
		for (auto dice : m_dices)
			dice.reset();
	}
	void judge(const unsigned sum) {
		m_isWon = (sum == WinVal) ? true : false;
	}
	void rollDice();
	void playCommand(const char command);
	void showResult();
	void showFinal(unsigned sum);
	char getCurrentCommand() const { return m_curCommand; }
	// TODO: thread security ensure 
	unsigned getUndefinedNum()const
	{
		return undefined_name_num;
	}
	static void IncUndefinedNum()
	{
		++undefined_name_num;
	}
public:
	CPlayer() : m_dices(DiceNum), m_isFinished(false), m_isWon(false),m_turn_round(0) ,m_curCommand(0)
	{
		name = "undefined name" + to_string(getUndefinedNum());
		IncUndefinedNum();
	};
	CPlayer(string& _name) :m_dices(DiceNum), m_isFinished(false), m_isWon(false), m_turn_round(0), m_curCommand(0), name(_name) { ; }
	void playGame();
	const vector<CDice>& getDices()const { return m_dices; }

	bool operator==(const CPlayer& another_player)const
	{
		return this->name == another_player.name;
	}
	
};










#endif




