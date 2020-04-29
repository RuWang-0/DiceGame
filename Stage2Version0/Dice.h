
#ifndef Dice_h
#define Dice_h

#include <stdio.h>
unsigned int random(int x);
class Dice{
private:
    unsigned int upValue; //the number facing upwards
public:
    Dice():upValue(0){}
    unsigned rollDice(){
        upValue = random(6) + 1;
        return upValue;
    }
};
#endif /* Dice_h */
