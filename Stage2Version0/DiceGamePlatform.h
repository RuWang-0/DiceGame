
#ifndef DiceGamePlatform_h
#define DiceGamePlatform_h

#include <stdio.h>
#include "DiceGame.h"
#include <set>
#include <memory>
#include <vector>
class DiceGamePlatform{
private:
    vector<DiceGame> curGames; // a platform has multiple games
    //set<Player&> registerdPlayers; // and some players
    vector<Player> registerdPlayers;
    static DiceGamePlatform* singleInstance;
    //for further inhancement, random number generator
    //minstd_rand rng;
protected:
    DiceGamePlatform();
    void startGame(Player* p1, Player* p2);
public:
    static DiceGamePlatform* getInstance(){
        return singleInstance;
    }
    void initialize();
    //shared_ptr<Player> regPlayer(string name);
    void regPlayer(string name);
    int findIndex(string name);
};
#endif /* DiceGamePlatform_h */
