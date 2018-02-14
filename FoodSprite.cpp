#include "FoodSprite.h"
#include "GlobalSettings.h"
#include "Tile.h"

#include <ctime>
#include <cstdlib>

Food::Food() {
    srand (time(NULL));
    findNewPos();
}

void Food::setPosition(int x, int y) {
    this->pos.first = x;
    this->pos.second = y;
}

void Food::setPosition(std::pair<int, int> p) {
    this->setPosition(p.first, p.second);
}

std::pair<int, int> Food::getPosition() {
    return this->pos;
}

void Food::findNewPos() {
    GlobalSettings &gs = GlobalSettings::getObject();
    int w = gs.getBoardWidth();
    int h = gs.getBoardHeight();
    SnakeBoard *sb = gs.getSnakeBoard();
    int x, y;

    do {
        x = rand() % w;
        y = rand() % h;
    } while (sb->getPixel(x, y) != BLANK_TILE);

    sb->setPixel(x, y, FOOD_TILE);
}

void Food::digest() {
    GlobalSettings &gs = GlobalSettings::getObject();

    gs.incScore(1);
    this->findNewPos();
}
