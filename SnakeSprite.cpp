#include "SnakeSprite.h"
#include "GlobalSettings.h"
#include "Tile.h"

#include <iostream>

Snake::Snake(int length = 3)
{
    int y;
    this->length = length;

    GlobalSettings sett = GlobalSettings::getObject();
    y = sett.getBoardHeight() / 2;  //floor mid value.

    //Generate Snake in board
    for (int i = 0; i < this->length - 1; i++ )
    {
        this->body.push_back(std::make_pair(i+1, y));
    }
	this->head = std::make_pair(this->length, y);
    this->currDir = Snake::DIR_RIGHT;
    this->nextDir = Snake::DIR_RIGHT;
    this->collide = false;
}

void Snake::update(SnakeBoard &sb)
{
    //Recalculate Snake position.
    std::pair<int, int> p;
    //add new tile at end
    Snake::Direction moveDir = this->nextDir;

	//This check is obsulute
	//if (moveDir == Snake::DIR_NONE)
    //    moveDir = this->currDir;
	std::cout << "m:" << moveDir << "c" << this->currDir << std::endl;
	//Snake can not go back. So set direction to current direction
	if((moveDir == Snake::DIR_DOWN && this->currDir == Snake::DIR_UP) ||
		(moveDir == Snake::DIR_UP && this->currDir ==  Snake::DIR_DOWN) ||
		(moveDir == Snake::DIR_LEFT && this->currDir == Snake::DIR_RIGHT) ||
		(moveDir == Snake::DIR_RIGHT && this->currDir == Snake::DIR_LEFT))
		moveDir = this->currDir;
	std::cout << "m:" << moveDir << "c" << this->currDir << std::endl;
    p = this->calcNextPixel(moveDir);

    if(sb.getPixel(p) != BLANK_TILE && sb.getPixel(p) != FOOD_TILE)
        this->collide = true;

    if(sb.getPixel(p) != FOOD_TILE) {
        std::pair<int, int> tail = this->body[0];
        sb.setPixel(tail.first, tail.second, BLANK_TILE);
        this->body.erase(this->body.begin());
    } else {
        GlobalSettings &gs = GlobalSettings::getObject();
        gs.getFood()->digest();
    }

    this->body.push_back(this->head);
	this->head = p;

    for (size_t i = 0; i < this->body.size(); i ++)
    {
        std::pair<int, int> p = this->body[i];
        sb.setPixel(p.first, p.second, SNAKE_TILE);
    }
	sb.setPixel(this->head.first, this->head.second, SNAKE_HEAD_TILE);
	this->currDir = moveDir;
}

void Snake::setNextDirection(Snake::Direction nDir)
{
    this->nextDir = nDir;
}

bool Snake::isCollide() {
    return this->collide;
}

std::pair <int, int> Snake::calcNextPixel(Snake::Direction dir)
{
    std::pair<int, int> p = this->head;
    int x = p.first, y = p.second;

    switch(dir)
    {
    case Snake::DIR_DOWN:
        y = y + 1;
        break;
    case Snake::DIR_UP:
        y = y - 1;
        break;
    case Snake::DIR_LEFT:
        x = x - 1;
        break;
    case Snake::DIR_RIGHT:
        x = x + 1;
        break;
    default:
        std::cout << "FATAL: Snake update direction is none" << std:: endl;
    }
    p.first = x;
    p.second = y;

    return p;
}
