//
//  DiceGame.h
//  DiceGame
//
//

#ifndef DiceGame_h
#define DiceGame_h

#include <stdio.h>
#include "Player.h"
#include "Dice.h"
using namespace std;

class DiceGame{
public:
    
    void startGame();
    DiceGame();
    void showBasicInfo();
private:
    Player player;
    Dice dice;
};

#endif /* DiceGame_h */
