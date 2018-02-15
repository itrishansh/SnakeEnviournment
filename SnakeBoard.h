#ifndef SNAKEBOARD_H_INCLUDED
#define SNAKEBOARD_H_INCLUDED

#include <vector>

class SnakeBoard
{
private:
    int width;
    int height;
    std::vector <std::vector <char> > board;

public:
    SnakeBoard(int h, int w);
    char getPixel(int x, int y);
    char getPixel(std::pair<int, int> p);
    void setPixel(int x, int y, char val);
    void printBoard();
};

#endif // SNAKEBOARD_H_INCLUDED
