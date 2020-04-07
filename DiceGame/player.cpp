#include "player.h"
#include <iostream>
using std::cin;
using std::cout;

const unsigned CPlayer::WinVal = 7;
const unsigned CPlayer::DiceNum = 2;

void CPlayer::playGame()
{
    printWelcome();
	while (!m_isFinished)
	{
		const char command = inputCommand();
		playCommand(command);
	}
}

void CPlayer::playCommand(const char command)
{
    switch (command) {
    case 'q':
        m_isFinished = true;
        printBye();
        break;
    case 's':
        initialize();
        printWelcome();
        break;
    case 'r':
        rollDice();
        showResult();
    default:
        break;
    }
}

void CPlayer::rollDice() {
    if (m_turn_round > 2)
        return;
    m_dices[m_turn_round].rollDice();
    m_turn_round++;
}

void CPlayer::showResult() {
    cout << "Dice is rolling..." << endl << endl;
    const string sRound = m_turn_round == 1 ? "first" : "second";
    unsigned sum = 0;
    for (auto dice : m_dices)
        sum += dice.showVal();
    cout << "The " << sRound << " dice rolling result is " << m_dices[m_turn_round-1].showVal()
        << endl << endl;
    if (m_turn_round == 2)
        showFinal(sum);
}

void CPlayer::showFinal(unsigned sum)
{
    cout << "The final result is " << sum << endl << endl;
    judge(sum);
    if (m_isWon) {
        cout << "Congratulations!!! You have WON this game!" << endl << endl;
    }
    else {
        cout << "Sorry, you have lost this game this time. Why not again?" << endl << endl;
    }
    initialize();
}

char CPlayer::inputCommand() {
    cout << "Please input your command('s' to start, 'r' to roll the dice ,'q' to quit)"
        << endl << endl;
    cin >> m_curCommand;
    return m_curCommand;
}
