
#include "DiceGamePlatform.h"

DiceGamePlatform* DiceGamePlatform::singleInstance = new DiceGamePlatform();

DiceGamePlatform::DiceGamePlatform():curGames(),registerdPlayers()
{
}

void DiceGamePlatform::initialize(){
    regPlayer("A");
    regPlayer("B");
    startGame(&registerdPlayers.at(0), &registerdPlayers.at(1));
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
