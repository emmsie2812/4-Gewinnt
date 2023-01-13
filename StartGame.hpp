#pragma once
#include <iostream>

/*********************************************************************

Starts the game

*********************************************************************/

class StartGame{
    
    public:
        StartGame();
        void startGame();
        bool end_game(int winlose);
        void jumpToNextLevel();

};