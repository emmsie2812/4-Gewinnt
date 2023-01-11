#include "level.hpp"
//#include "CppRandom.hpp"
//#include <random>
#include <iostream>
#include <fstream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Defined levels. An array is returned. 
//At position 0 the columns
//At position 1 the lines
//At position 2 the needed number of stones to win
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int* Level::level_1(){
    columnsLinesWinCoins[0] = 4; //columns
    columnsLinesWinCoins[1] = 4; //lines
    columnsLinesWinCoins[2] = 4; //win_coins
   return columnsLinesWinCoins;
}
int* Level::level_2(){
    columnsLinesWinCoins[0] = 5; //columns
    columnsLinesWinCoins[1] = 5; //lines
    columnsLinesWinCoins[2] = 4; //win_coins
   return columnsLinesWinCoins;
}
int* Level::level_3(){
    columnsLinesWinCoins[0] = 6; //columns
    columnsLinesWinCoins[1] = 6; //lines
    columnsLinesWinCoins[2] = 4; //win_coins
   return columnsLinesWinCoins;
}
int* Level::level_4(){
    columnsLinesWinCoins[0] = 4; //columns
    columnsLinesWinCoins[1] = 6; //lines
    columnsLinesWinCoins[2] = 4; //win_coins
   return columnsLinesWinCoins;
}
int* Level::level_5(){
    columnsLinesWinCoins[0] = 6; //columns
    columnsLinesWinCoins[1] = 6; //lines
    columnsLinesWinCoins[2] = 5; //win_coins
   return columnsLinesWinCoins;
}
int* Level::level_6(){
    columnsLinesWinCoins[0] = 7; //columns
    columnsLinesWinCoins[1] = 7; //lines
    columnsLinesWinCoins[2] = 6; //win_coins
   return columnsLinesWinCoins;
}

int* Level::level_7(){                                                                  //To do
   /* int field_column_random = GetRandomNumberBetween(5,10);
    int field_line_random = GetRandomNumberBetween(5,10);
    int field_win_coins = GetRandomNumberBetween(4,6);

    columnsLinesWinCoins[0] = field_column_random; //columns
    columnsLinesWinCoins[1] = field_line_random; //lines
    columnsLinesWinCoins[2] = field_win_coins; //win_coins
    */
    columnsLinesWinCoins[0] = 7; //columns
    columnsLinesWinCoins[1] = 7; //lines
    columnsLinesWinCoins[2] = 6; //win_coins*/
    return columnsLinesWinCoins;
    //printf("Hier in level 7");
}

int Level::getLevel(){
    std::string levelFromFile;
    std::ifstream fileSavedLevels("saved_levels.txt");
    while(getline(fileSavedLevels, levelFromFile)){
        //std::cout << levelFromFile;
    }
    fileSavedLevels.close();
    int intlevelFromFile = stoi(levelFromFile);
    return intlevelFromFile;
}

void Level::saveLevel(int newLevel){
    std::ofstream saveLevelInFile;
    saveLevelInFile.open("saved_levels.txt");
    saveLevelInFile << newLevel;
    saveLevelInFile.close();
}

int* Level::levelSetup(){
    int levelFromFile;
    levelFromFile = getLevel();
    switch(levelFromFile) {
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

    columnsLinesWinCoins[0] = 4; //columns
    columnsLinesWinCoins[1] = 4; //lines
    columnsLinesWinCoins[2] = 4; //win_coins
    return columnsLinesWinCoins; //Default
}

