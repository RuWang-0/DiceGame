//
//  Dice.cpp
//  DiceGame
//
//

#include "Dice.h"
#include <ctime>
#include <cstdlib>
Dice::Dice():up_face(1){
    
}

void Dice::roll(){
    up_face = rand() % 6 + 1;
}

int Dice::get_upface(){
    return up_face;
}
