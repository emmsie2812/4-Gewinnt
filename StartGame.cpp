#include "StartGame.hpp"
#include "Field.hpp"
#include "GameLogic.hpp"
#include "Screen.hpp"
#include "Level.hpp"
#include <iostream>
#include <unistd.h>

/*********************************************************************
Start and end the game
*********************************************************************/

StartGame::StartGame() {
    //Screen screen;
}
Screen screen;

void StartGame::startGame() {
/*********************************************************************
Start game
*********************************************************************/

    Level level;
    int* columnsLinesWinCoins;
    columnsLinesWinCoins = level.levelSetup();      //Get columns, rows and wincoins
    int columns = columnsLinesWinCoins[0];
    int row = columnsLinesWinCoins[1];
    int wincoins = columnsLinesWinCoins[2];

    Field *gameField = new Field();
    GameLogic *gameLogic = new GameLogic(*gameField);
    bool time = true;

    while (time) {
        screen.clearScreen();
        gameLogic->field.fieldOutput(columns, row);                 //Users turn
        std::cout<<"Your Turn:";
        gameLogic->placeChipUser(columns, row);

        gameLogic->field.fieldOutput(columns, row);                 
        int winlose = gameLogic->winLose(columns, row, wincoins);   //Win and lose check
        
        if (end_game(winlose)) {
            break;
        }
        gameLogic->placeChipEnemy(columns, row);                    //Enemys turn

        winlose = gameLogic->winLose(columns, row, wincoins);       //Win and lose check
        if (end_game(winlose)) { 
            break;
        }   
    }
}

bool StartGame::end_game(int winlose) {
/*********************************************************************
calls the win or lose screen
break is not needed in this switch case, because the returns catch any case
*********************************************************************/

    switch (winlose)
    {
    case 1:
        screen.endMenuWin();
        return true;
    case 2:
        screen.endMenuLose();
        return true;
    default:
        return false;
    }
}
