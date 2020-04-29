

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <vector>
#include <string>
#include "Strategy.h"
#include "Dice.h"
using namespace std;
class DiceGame;
class Player{
private:
    enum PlayerState {OFFLINE, ONLINE, PREPARED, PLAYING};
    enum WinState {WIN, LOST, DRAW};
    vector<int> rollResults; // keep track of points get from dice
    //DiceGame* myGameState;
    //char curCommand;
    //unsigned turnNum;
    Strategy* strategy;
    int curScore;
protected:
    string name;
    char inputCommand();
    void rollDice(Dice& dice);
    void showResult();
    void setScore();
public:
    void initialize();
    Player(string name):name(name), curScore(0),rollResults(){}
    void setStrategy(unsigned choice);
    Strategy* getStrategy(){return strategy;}
    string getName() const {return name;}
    vector<int> getRollResults() const;
    void play(Dice& dice);
    int getCurScore() const {return curScore;}
    bool operator < (const Player& p) const {return p.getName() < this->getName();}
};
#endif /* Player_h */
