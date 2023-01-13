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

StartGame::StartGame() {}
Screen screen;

void StartGame::startGame() {
/*********************************************************************
Start game
*********************************************************************/

    Level level;
    columnsRowsWinCoins = level.levelSetup();      //Get columns, rows and wincoins
    int columns = columnsRowsWinCoins[0];
    int row = columnsRowsWinCoins[1];
    int wincoins = columnsRowsWinCoins[2];

    Field *gameField = new Field();
    GameLogic *gameLogic = new GameLogic(*gameField);
    bool time = true;

    //gameLogic->field.fieldEmpty(columns, row);

    while (time) {
        screen.clearScreen();
        gameLogic->field.fieldOutput(columns, row);                 //Users turn
        std::cout<<"Your turn, type in a number between 1 and " << columns;
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
