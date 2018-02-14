CC=gcc
CPP=g++

.FoodSprite.o: FoodSprite.cpp
	$(CPP) -c FoodSprite.cpp

.GameClock.o: GameClock.cpp
	$(CPP) -c GameClock.cpp

.GlobalSettings.o: GlobalSettings.cpp
	$(CPP) -c GlobalSettings.cpp

.main.o: main.cpp
	$(CPP) -c main.cpp

.SnakeBoard.o: SnakeBoard.cpp
	$(CPP) -c SnakeBoard.cpp

.SnakeSprite.o: SnakeSprite.cpp
	$(CPP) -c SnakeSprite.cpp

main: FoodSprite.o GameClock.o GlobalSettings.o main.o SnakeBoard.o SnakeSprite.o
	$(CPP) -o main FoodSprite.o GameClock.o GlobalSettings.o main.o SnakeBoard.o SnakeSprite.o

clean:
	-rm *.o
	-rm main
