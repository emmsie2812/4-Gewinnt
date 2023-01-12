#pragma once
#include "field.hpp"
#include <iostream>
#include<limits>

class GameLogic{

    private:
        int userInput;

    public:
        void placeChipUser(int columns, int row);
        void placeChipRandom(int columns, int row);
        bool invalidInputUser(int columns, int row, int userInput);
        bool invalidInputEnemy(int columns, int row, int userInput);
        int winLose(int columns, int row, int winCoins);
        int diagonalWinLose(int columns, int row,int winCoins);
        int verticalWinLose(int columns, int row,int winCoins);
        int horizontalWinLose(int columns, int row,int winCoins);
        Field field;
        GameLogic();
        GameLogic(Field &gameField);
};