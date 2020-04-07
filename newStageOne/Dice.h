//
//  Dice.h
//  DiceGame
//
//

#ifndef Dice_h
#define Dice_h

#include <stdio.h>

class Dice{
private:
    int up_face;
public:
    Dice();
    void roll();
    int get_upface();
};



#endif /* Dice_h */
