#ifndef DiceGame_h
#define DiceGame_h
#include <stdio.h>
#include <list>
#include "Player.h"
#include "Judge.h"
using namespace std;

unsigned int random(int x);

class DiceGame{
private:
    list<Player*> players;
    enum GameState{CLOSED, WAITING, PLAYING};
    GameState gameState;
    Judge judge;
    Dice dice;
    bool isGameEnd;
public:
    DiceGame(Player* p1, Player* p2);
    DiceGame();
    void play();
    void advanceTurn();
    void printGameResults();
};

#endif /* DiceGame_h */
