#ifndef GLOBALSETTINGS_H_INCLUDED
#define GLOBALSETTINGS_H_INCLUDED

#include <string>

#include "SnakeBoard.h"
#include "FoodSprite.h"

#define DEFAULT_CONFIG_FILE_NAME "C:\\Users\\tbhardwa\\SnakeBackend\\snake.conf"
#define BOARD_WIDTH_SETTING "BoardWidth"
#define BOARD_HEIGHT_SETTING "BoardHeight"

class GlobalSettings {
private:
    int boardWidth;
    int boardHeight;
    SnakeBoard *sb;
    int score;
    Food *food;

    //Singleton Object
    GlobalSettings();

public:
    int getBoardWidth();
    int getBoardHeight();
    void load(std::string fname);
    static GlobalSettings& getObject();
    SnakeBoard *getSnakeBoard();
    void setSnakeBoard(SnakeBoard *sb);
    int getScore();
    void setScore(int);
    int incScore(int);
    Food *getFood();
    void setFood(Food *);

private:
    void setKeyVal(const char *key, const char *val);
    //GlobalSettings(GlobalSettings const&);  // Don't Implement
    void operator=(GlobalSettings const&);  // Don't implement
};

#endif // GLOBALSETTINGS_H_INCLUDED
