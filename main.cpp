#include <iostream>
#include <fstream>

#include "GlobalSettings.h"
#include "SnakeBoard.h"
#include "SnakeSprite.h"
#include "FoodSprite.h"
//GameClock is not able to sleep. Using other approach
//#include "GameClock.h"

using namespace std;

int processInput(Snake &snake) {
    char ch;
    string input;
    do {
		cin >> input;
        for (std::string::iterator it = input.begin(), end = input.end(); it != end; ++it) {
            ch = *it;
            //std::cout << ch << std::endl;
            switch(ch) {
            case 'u':
            case 'U':
                snake.setNextDirection(Snake::DIR_UP);
                break;
            case 'd':
            case 'D':
                snake.setNextDirection(Snake::DIR_DOWN);
                break;
            case 'l':
            case 'L':
                snake.setNextDirection(Snake::DIR_LEFT);
                break;
            case 'r':
            case 'R':
                snake.setNextDirection(Snake::DIR_RIGHT);
                break;
            case 'n':
            case 'N':
                //Input done redraw next
                ch = 'N';
                break;
            case 't':
            case 'T':
                ch = 'T';
                break;
            default:
                cout << "Unknown input " << ch << endl;
            }
        }
    } while(ch != 'N' && ch != 'T');

    return (ch == 'N');
}

int main()
{
    int cont = 1;
    GlobalSettings &gSettings = GlobalSettings::getObject();;
    SnakeBoard sb (gSettings.getBoardWidth(), gSettings.getBoardHeight());
    Snake snake(5);

    gSettings.setSnakeBoard(&sb);
    //GameClock gc(1.0);
    snake.update(sb);
    Food food;
    sb.printBoard();

    while (cont) {
        cont = processInput(snake);
        snake.update(sb);
		cont = (!snake.isCollide()) && cont;
		cout << "GameOver : " << !cont << endl;
        sb.printBoard();
    }

    return 0;
}
