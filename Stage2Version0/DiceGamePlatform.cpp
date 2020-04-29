
#include "DiceGamePlatform.h"
#include <iostream>
using namespace std;

DiceGamePlatform* DiceGamePlatform::singleInstance = new DiceGamePlatform();

DiceGamePlatform::DiceGamePlatform():curGames(),registerdPlayers()
{
}


int DiceGamePlatform::findIndex(string name){
    for (int i = 0; i < registerdPlayers.size(); i++) {
        if (name == registerdPlayers.at(i).getName()) {
            return i;
        }
    }
    return -1;
}


void DiceGamePlatform::initialize(){
    regPlayer("A");
    regPlayer("B");
    cout << "One Game waiting to be joined. Player1, what's your name?"<<endl;
    string name;
    cin>>name;
    int index1 = findIndex(name);
    cout << "Player2, what's your name?"<<endl;
    cin>>name;
    int index2 = findIndex(name);
    startGame(&registerdPlayers.at(index1), &registerdPlayers.at(index2));
    //startGame(regPlayer("A").get(), regPlayer("B").get());
}
/* problems encounterd that I cannot solve
shared_ptr<Player> DiceGamePlatform::regPlayer(string name){
    shared_ptr<Player> newPlayer = make_shared<Player>(name);
    auto res = registerdPlayers.insert(*newPlayer);
    if (res.second) {
        return newPlayer;
    }
    return nullptr;
}
*/

void DiceGamePlatform::regPlayer(string name){
    Player* newPlayer = new Player(name);
    registerdPlayers.push_back(*newPlayer);
}
void DiceGamePlatform::startGame(Player* p1, Player* p2){
    DiceGame newGame(p1, p2);
    curGames.push_back(newGame);
    newGame.play();
}
