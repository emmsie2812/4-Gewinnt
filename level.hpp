#pragma once
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//definition of each level and return methods 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Level{
    int columnsLinesWinCoins[3];

    public:
        int* level_1();
        int* level_2();
        int* level_3();
        int* level_4();
        int* level_5();
        int* level_6();
        int* level_7();
        int getLevel();
        void saveLevel(int newLevel);
        int* levelSetup();
        void incrementLevelInFile();
};
