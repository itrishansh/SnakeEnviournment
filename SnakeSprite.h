#ifndef SNAKESPRITE_H_INCLUDED
#define SNAKESPRITE_H_INCLUDED

#include <vector>
#include <utility>

#include "SnakeBoard.h"

class Snake {
public:
    enum Direction {
        DIR_NONE,
        DIR_UP,
        DIR_DOWN,
        DIR_LEFT,
        DIR_RIGHT,
    };

private:
    int length;
    //Snake head is last entry (tail of queue)
    std::vector <std::pair<int, int> > body;
	std::pair<int, int> head;
    bool collide;
    Snake::Direction currDir;
    Snake::Direction nextDir;

    std::pair <int, int> calcNextPixel(Snake::Direction dir);

public:
    Snake(int length);
    void update(SnakeBoard &sb);
    void setNextDirection(Snake::Direction nDir);
    bool isCollide();
};

#endif // SNAKESPITE_H_INCLUDED
