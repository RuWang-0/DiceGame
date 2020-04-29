
#include "DiceGame.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
unsigned int random(int x){
    return rand() % x;
}


DiceGame::DiceGame():gameState(WAITING){
    srand(time(nullptr));
}

DiceGame::DiceGame(Player* p1, Player* p2):gameState(PLAYING){
    srand(time(nullptr));
    players.push_back(p1);
    players.push_back(p2);
}

void DiceGame::play(){
    cout<<"Welcome to the game!"<<endl<<endl;
    cout<<"Players, choose your strategy: 0 for addition and 1 for multiplication. Your result is the remainder divided by 6."<<endl<<endl;
    cout<<"Plyer1, what is your choice?"<<endl<<endl;
    unsigned choice;
    cin>>choice;
    players.front()->setStrategy(choice);
    cout<<"Player2, what is your choice?"<<endl<<endl;
    cin>>choice;
    players.back()->setStrategy(choice);
    while(gameState != CLOSED){
        players.front()->play(dice);
        players.back()->play(dice);
        judge.judge(*players.front(), *players.back());
        advanceTurn();
    }
}

void DiceGame::printGameResults(){
    vector<GameResult> res = judge.getResults();
    for (int i = 0; i < res.size(); i++) {
        cout << "Winner of Round "<<i+1<<": "<<res.at(i).winer<<endl;
    }
    cout<<endl;
}

bool askEnd(Player* player){
    cout<<player->getName()<<" , Do you want to end the game? 1 for yes and 0 for no."<<endl<<endl;
    bool isEnd;
    cin>>isEnd;
    return isEnd;
}

void DiceGame::advanceTurn(){
    printGameResults();
    players.front()->initialize();
    players.back()->initialize();
    bool isEnd = askEnd(players.front());
    if(isEnd){
        gameState = CLOSED;
        cout <<"BYE-BYE!"<<endl;
    }
}
