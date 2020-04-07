//
//  Player.h
//  DiceGame
//
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <vector>
#include "Dice.h"
using namespace std;
class Player{
public:
    Player();
    void play(Dice& mydice);
private:
    int number_of_turn; // eg. No.1 roll, No.2 roll etc
    vector<int> roll_result;
    char command;
    bool isFinished;
    bool isWon;
    void welcome();
    void goodBye();
    void showResult();
    void judge(int sum);
    void initialize();
    void rollDice(Dice& mydice);
    char inputCommand();
    char getCurrentCommand();
    void playCommand(Dice& mydice);
};

#endif /* Player_h */
