
#ifndef Judge_h
#define Judge_h

#include <stdio.h>
#include <string>
#include <vector>
#include "Strategy.h"
#include "Player.h"
using namespace std;
struct GameResult{
    string winer;
};
//the judge keeps game records and find the winer
class Judge{
private:
    vector<GameResult> gameResults;
public:
    Judge():gameResults(){}
    GameResult judge(Player& p1, Player& p2){
        GameResult result;
        unsigned res1 = 0, res2 = 0;
        res1 = p1.getCurScore();
        res2 = p2.getCurScore();
        if(res1 > res2){
            result.winer = p1.getName();
        }else if(res1 < res2){
            result.winer = p2.getName();
        }else{
            result.winer = "DRAW";
        }
        gameResults.push_back(result);
        return result;
    }
    vector<GameResult>& getResults(){
        return gameResults;
    }
};
#endif /* Judge_h */
