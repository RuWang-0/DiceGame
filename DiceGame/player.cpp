#include "player.h"
#include <iostream>
using std::cin;
using std::cout;

const unsigned CPlayer::DiceNum = 2;
unsigned CPlayer::undefined_name_num = 0;


unsigned CPlayer::rollDice(unsigned round) {
    if (round >= 2)
        return 0;
    return m_dices[round].rollDice();
}


