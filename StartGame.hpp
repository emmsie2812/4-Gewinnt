#pragma once
#include <iostream>

/*********************************************************************

Starts the game

*********************************************************************/

class StartGame{
    public:
        StartGame();
        int* columnsRowsWinCoins;
        void startGame();
        bool end_game(int winlose);
        void jumpToNextLevel();

};