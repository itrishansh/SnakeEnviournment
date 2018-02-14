#ifndef FOODSPRITE_H_INCLUDED
#define FOODSPRITE_H_INCLUDED

#include <utility>

class Food {
private:
    std::pair <int, int> pos;
    void findNewPos();

public:
    Food();
    void setPosition(int, int);
    void setPosition(std::pair<int, int>);
    std::pair<int, int> getPosition();
    void digest();
};

#endif // FOODSPRITE_H_INCLUDED
