#ifndef GAMECLOCK_H_INCLUDED
#define GAMECLOCK_H_INCLUDED

class GameClock {
private:
    //Mili Seconds
    double timeout;
    //auto lastTick;

public:
    GameClock(double timeout);
    void tick();
};

#endif // GAMECLOCK_H_INCLUDED
