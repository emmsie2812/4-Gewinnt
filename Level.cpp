#include "Level.hpp"
#include "Random.hpp"
#include <random>
#include <iostream>
#include <fstream>

/*********************************************************************
Defined levels. An array is returned.
At position 0 the columns
At position 1 the rows
At position 2 the needed number of stones to win
*********************************************************************/

Level::Level() {

}

int* Level::level_1() {
    columnsRowsWinCoins[0] = 7; //columns
    columnsRowsWinCoins[1] = 7; //rows
    columnsRowsWinCoins[2] = 4; //win_coins 
    return columnsRowsWinCoins;
}

int* Level::level_2() {
    columnsRowsWinCoins[0] = 6; //columns
    columnsRowsWinCoins[1] = 6; //rows
    columnsRowsWinCoins[2] = 4; //win_coins
    return columnsRowsWinCoins;
}

int* Level::level_3() {
    columnsRowsWinCoins[0] = 6; //columns
    columnsRowsWinCoins[1] = 6; //rows
    columnsRowsWinCoins[2] = 4; //win_coins
    return columnsRowsWinCoins;
}

int* Level::level_4() {
    columnsRowsWinCoins[0] = 4; //columns
    columnsRowsWinCoins[1] = 6; //rows
    columnsRowsWinCoins[2] = 4; //win_coins
    return columnsRowsWinCoins;
}

int* Level::level_5() {
    columnsRowsWinCoins[0] = 5; //columns
    columnsRowsWinCoins[1] = 5; //rows
    columnsRowsWinCoins[2] = 4; //win_coins
    return columnsRowsWinCoins;
}

int* Level::level_6() {
    columnsRowsWinCoins[0] = 4; //columns
    columnsRowsWinCoins[1] = 4; //rows
    columnsRowsWinCoins[2] = 4; //win_coins
    return columnsRowsWinCoins;
}

int* Level::level_7() {    
    Random random;
    int field_column_random = random.getRandomNumberBetween(5,10);
    int field_row_random = random.getRandomNumberBetween(5,10);
    int field_win_coins = random.getRandomNumberBetween(4,6);

    columnsRowsWinCoins[0] = field_column_random;   //columns
    columnsRowsWinCoins[1] = field_row_random;      //rows
    columnsRowsWinCoins[2] = field_win_coins;       //win_coins
    return columnsRowsWinCoins;
}

int Level::getLevel() {
/*********************************************************************
returns the last saved level from file
*********************************************************************/

    std::string levelFromFile;
    std::ifstream fileSavedLevels("saved_levels.txt");
    while (getline(fileSavedLevels, levelFromFile)) {
        //std::cout << levelFromFile;
    }
    fileSavedLevels.close();
    int intlevelFromFile = stoi(levelFromFile);
    return intlevelFromFile;
}

void Level::saveLevel(int newLevel) {
/*********************************************************************
stores level in file
*********************************************************************/
    
    std::ofstream saveLevelInFile;
    saveLevelInFile.open("saved_levels.txt");
    saveLevelInFile << newLevel;
    saveLevelInFile.close();
}

int* Level::levelSetup() {
/*********************************************************************
returns the level setup (columns, rows, wincoins) depending on the level stored in the file
*********************************************************************/

    int levelFromFile;
    levelFromFile = getLevel();     //gets level from file

    switch (levelFromFile) {
                case 1:
                    return level_1();
                case 2:
                    return level_2();
                case 3:
                    return level_3();
                case 4:
                    return level_4();
                case 5:
                    return level_5();
                case 6:
                    return level_6();
                case 7:
                    return level_7();
                default:
                    return level_7();
    }
    //default if somethings wrong. Game wouldn't stop
    columnsRowsWinCoins[0] = 4; //columns
    columnsRowsWinCoins[1] = 4; //rows
    columnsRowsWinCoins[2] = 4; //win_coins
    return columnsRowsWinCoins; //Default
}

void Level::incrementLevelInFile() {
/*********************************************************************
increments the level and stores it in the file
*********************************************************************/

    int newLevel;
    newLevel = getLevel() + 1;
    saveLevel(newLevel);
}