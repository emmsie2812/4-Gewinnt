#pragma once
#include <iostream>

/*********************************************************************

Starts the game

*********************************************************************/

class StartGame {

    public:
        StartGame();
        int* columnsRowsWinCoins;
        void startGame();
        bool endGame(int winlose);
        void jumpToNextLevel();
};