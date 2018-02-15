#!/bin/sh

g++ -c FoodSprite.cpp -ggdb
g++ -c GameClock.cpp  -ggdb
g++ -c GlobalSettings.cpp  -ggdb
g++ -c SnakeBoard.cpp  -ggdb
g++ -c SnakeSprite.cpp  -ggdb
g++ -c main.cpp  -ggdb
g++ FoodSprite.o GameClock.o GlobalSettings.o main.o SnakeBoard.o SnakeSprite.o -o main  -ggdb
rm *.o
