#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include <iostream>
#include <vector>
using namespace std;

class CPlayer
{
private:
	static const unsigned WinVal;
	static const unsigned DiceNum;
	vector<CDice>m_dices;
	bool m_isFinished, m_isWon;
	unsigned m_turn_round;
	char m_curCommand;
protected:
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
public:
	CPlayer() : m_dices(DiceNum), m_isFinished(false), m_isWon(false),m_turn_round(0) ,m_curCommand(0){};
	void playGame();
	const vector<CDice>& getDices()const { return m_dices; }
	
};










#endif




