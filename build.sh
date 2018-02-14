#!/bin/sh

g++ -c FoodSprite.cpp
g++ -c GameClock.cpp
g++ -c GlobalSettings.cpp
g++ -c SnakeBoard.cpp
g++ -c SnakeSprite.cpp
g++ -c main.cpp
g++ FoodSprite.o GameClock.o GlobalSettings.o main.o SnakeBoard.o SnakeSprite.o -o main
rm *.o
