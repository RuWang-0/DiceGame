

#include <iostream>
#include <chrono>
#include "DiceGamePlatform.h"

int main(int argc, const char * argv[]) {
    DiceGamePlatform* platform = DiceGamePlatform::getInstance();
    platform->initialize();
    return 0;
}
