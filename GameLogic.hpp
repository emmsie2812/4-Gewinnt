#pragma once
#include "Field.hpp"
#include <iostream>
#include<limits>

/*********************************************************************

Game logic to place the chips and check the input and winning / losing rows

*********************************************************************/

class GameLogic {

    private:
        int userInput;
        
    public:
        void placeChipUser(int columns, int row);
        void placeChipEnemy(int columns, int row);
        bool invalidInputUser(int columns, int row, int userInput);
        bool invalidInputEnemy(int columns, int row, int userInput);
        int winLose(int columns, int row, int winCoins);
        int diagonalWinLose(int columns, int row, int winCoins);
        int verticalWinLose(int columns, int row, int winCoins);
        int horizontalWinLose(int columns, int row, int winCoins);
        Field field;
        GameLogic();
        GameLogic(Field &gameField);
};