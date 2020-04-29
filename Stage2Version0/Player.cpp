

#include "Player.h"
#include <iostream>
using namespace std;
void Player::setStrategy(unsigned choice){
    if(choice == 0){
        strategy = new AddRemaind6();
    }else{
        strategy = new MulRemaind6();
    }
}


void Player::initialize(){
    rollResults.clear();
}

void Player::setScore(){
    curScore = strategy->calculateCredits(rollResults);
}

void Player::play(Dice& dice){
    int rollNum = 0;
    while(rollNum < 2){
        rollDice(dice);
        rollNum++;
    }
    setScore();
    showResult();
}

void Player::showResult(){
    cout <<"Player: "<<name<<"'s turn."<<endl;
    cout << "The first roll result: ";
    cout << rollResults.at(0)<<endl;
    cout << "The second roll result: ";
    cout << rollResults.at(1)<<endl;
    cout << "Your Score: "<< curScore <<endl<<endl;
}


void Player::rollDice(Dice& dice){
    unsigned res = dice.rollDice();
    rollResults.push_back(res);
}


