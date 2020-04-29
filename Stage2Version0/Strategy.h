//Game strategy

#ifndef Strategy_h
#define Strategy_h

#include <stdio.h>
#include <vector>
using namespace std;
//enum GameResult{WIN, LOST, DRAW};
//Strategy is used only to calculate scores, the result is judged by the game system

class Strategy{
public:
    virtual unsigned calculateCredits(const vector<int>& results) = 0;
};

class AddRemaind6:public Strategy{
public:
    virtual unsigned calculateCredits(const vector<int>& results) override;
    
};

class MulRemaind6:public Strategy{
public:
    virtual unsigned calculateCredits(const vector<int>& results) override;
};

#endif /* Strategy_h */
