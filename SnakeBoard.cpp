#include <iostream>

#include "Tile.h"
#include "SnakeBoard.h"
#include "GlobalSettings.h"

SnakeBoard::SnakeBoard(int width, int height)
{
    this->height = height;
    this->width  = width;

    for (int i = 0; i < height; i ++)
    {
        std::vector <char> vec (width, BLANK_TILE);
        this->board.push_back(vec);
        //this->board.push_back(new std::vector<char>(width, BLANK_TILE));
    }
    //create box board
    for(int i = 0; i < this->height; i++){
        setPixel(0, i, WALL_TILE);
        setPixel(this->width - 1, i, WALL_TILE);
    }
    for (int i = 0; i < this->width; i ++) {
        setPixel(i, 0, WALL_TILE);
        setPixel(i, this->height - 1, WALL_TILE);
    }
}

char SnakeBoard::getPixel(int x, int y)
{
    return this->board[y][x];
}

char SnakeBoard::getPixel(std::pair<int, int> p)
{
    return this->getPixel(p.first, p.second);
}

void SnakeBoard::setPixel(int x, int y, char val)
{
    this->board[y][x] = val;
}

void SnakeBoard::printBoard()
{
    //std::cout << this->board[0];
    GlobalSettings &gs = GlobalSettings::getObject();
	std::cout << "StartMarker::." << std::endl;
    std::cout << "Score : " << gs.getScore() << std::endl;
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            std::cout << this->getPixel(j, i) << " ";
        }
        std::cout << std::endl;
    }
	std::cout << "EndMarker::." << std::endl;
	std::cout.flush();
}
