#include <unistd.h>
#include "GameClock.h"

GameClock::GameClock(double timeout) {
    this->timeout = timeout;
}

void GameClock::tick() {
    //usleep(int(this->timeout * 1000000));
    usleep(100000000);
    //sleep(1);
}
