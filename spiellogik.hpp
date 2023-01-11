#pragma once
#include "field.hpp"
#include <iostream>
#include<limits>

class Spiellogik{

    private:
        int userInput;

    public:
        void placeChipUser(int columns, int lines);
        void placeChipRandom(int columns, int lines);
        bool invalidInput(int columns, int lines, int userInput);
        int winLose(int columns, int lines, int winCoins);
        int diagonalWinLose(int columns, int lines,int winCoins);
        int verticalWinLose(int columns, int lines,int winCoins);
        int horizontalWinLose(int columns, int lines,int winCoins);
        Field field;
        Spiellogik();
        Spiellogik(Field &gameField);
};