#include "dice_game.h"
#include <cstdlib>
#include <ctime>

// random will return a random int value between [0,x)
unsigned int random(int x)
{
	return rand() % x;
}

CDiceGame::CDiceGame()
{
	srand(time(nullptr));
}
