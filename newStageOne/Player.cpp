//
//  Player.cpp
//  DiceGame
//
//  Created by apple on 2020/4/7.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <string>
using namespace std;
Player::Player():number_of_turn(0),roll_result(2),isFinished(0){
}

void Player::rollDice(Dice& mydice){
    mydice.roll();
    roll_result.push_back(mydice.get_upface());
    number_of_turn++;
}

void Player::initialize(){
    number_of_turn = 0;
    roll_result.clear();
    isFinished = 0;
    isWon = 0;
}

void Player::play(Dice& mydice){
    while (!isFinished) {
        inputCommand();
        playCommand(mydice);
    }
}


void Player::showResult(){
    cout<<"Dice is rolling..."<<endl<<endl;
    string s;
    int sum = 0;
    if (number_of_turn == 1) {
        s = "first";
    }else{
        s = "second";
        sum = roll_result.at(0) + roll_result.at(1);
    }
    cout<<"The "<<s<<" dice rolling result is "<<roll_result.at(number_of_turn - 1)
    <<endl<<endl;
    if (number_of_turn == 2) {
        cout<<"The final result is "<<sum<<endl<<endl;
        judge(sum);
        if (isWon) {
            cout<<"Congratulations!!! You have WON this game!"<<endl<<endl;
        }else{
            cout<<"Sorry, you have lost this game this time. Why not again?"<<endl<<endl;
        }
    }
}

void Player::judge(int sum){
    if (sum == 7) {
        isWon = 1;
    }else{
        isWon = 0;
    }
}

void Player::welcome(){
    cout<<"Let's start playing games!"<<endl<<endl;
}

void Player::goodBye(){
    cout<<"BYE-BYE!"<<endl<<endl;
}

void Player::playCommand(Dice& mydice){
    switch (command) {
        case 'q':
            isFinished = 1;
            goodBye();
            break;
        case 's':
            initialize();
            welcome();
            break;
        case 'r':
            rollDice(mydice);
            showResult();
        default:
            break;
    }
}

char Player::inputCommand(){
    cout<<"Please input your command('s' to start, 'r' to roll the dice ,'q' to quit)"
    <<endl<<endl;
    cin>>command;
    return command;
}

char Player::getCurrentCommand(){ //not used
    return command;
}
