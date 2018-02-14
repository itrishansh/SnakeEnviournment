#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "GlobalSettings.h"

GlobalSettings::GlobalSettings()
{
    this->boardHeight = 10;
    this->boardWidth = 10;
    this->load(DEFAULT_CONFIG_FILE_NAME);
    this->score = 0;
    this->food = NULL;
}

GlobalSettings& GlobalSettings::getObject() {
    static GlobalSettings settings;
    return settings;
}

int GlobalSettings::getBoardWidth()
{
    return this->boardWidth;
}

int GlobalSettings::getBoardHeight()
{
    return this->boardHeight;
}

void GlobalSettings::load(std::string fname) {
    std::ifstream fin (fname.c_str());
    std::string line;

    if (!fin.is_open()) {
        std::cout << "Failed to load configuration from " << fname << std::endl;
    }

    while( getline(fin, line)) {
        char *key, *val;
        char *l = strdup(line.c_str());
        key = strtok(l, " :");
        val = strtok(NULL, " :");
        this->setKeyVal(key, val);
    }
    fin.close();
}

void GlobalSettings::setKeyVal(const char *key, const char *val)
{
    //std::cout << "Key : " << key << ", Val : " << val << std::endl;

    if (!strcmp(key, BOARD_WIDTH_SETTING)) {
        this->boardWidth = atoi(val);
    } else if (!strcmp(key, BOARD_HEIGHT_SETTING)) {
        this->boardHeight = atoi(val);
    }
}

SnakeBoard *GlobalSettings::getSnakeBoard() {
    return this->sb;
}

void GlobalSettings::setSnakeBoard(SnakeBoard *sb) {
    this->sb = sb;
}

int GlobalSettings::getScore() {
    return this->score;
}

void GlobalSettings::setScore(int score){
    this->score = score;
}

Food *GlobalSettings::getFood() {
    return this->food;
}

void GlobalSettings::setFood(Food *f) {
    this->food = f;
}

int GlobalSettings::incScore(int score) {
    this->score += score;
    //std::cout << "New Score : " << this->score << std::endl;

    return this->score;
}
