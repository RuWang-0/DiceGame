//
//  DiceGame.cpp
//  DiceGame
//
//

#include "DiceGame.h"

DiceGame::DiceGame():player(),dice(){}

void DiceGame::startGame(){
    srand(time(nullptr));
    player.play(dice);
}
