#include "startEnd.hpp"
#include "field.hpp"
#include "gameLogic.hpp"
#include "Screen.hpp"
#include "level.hpp"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Start and end the game
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Screen screen;

void StartEnd::startGame(){
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Start game
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Level level;
    int* columnsLinesWinCoins;
    columnsLinesWinCoins = level.levelSetup();      //Get columns, rows and wincoins
    int columns = columnsLinesWinCoins[0];
    int row = columnsLinesWinCoins[1];
    int wincoins = columnsLinesWinCoins[2];

    Field *gameField = new Field();
    GameLogic *gameLogic = new GameLogic(*gameField);
    bool time = true;
    while(time){    //
        screen.clearScreen();
        gameLogic->field.fieldOutput(columns, row);
        std::cout<<"Your Turn:";
        gameLogic->placeChipUser(columns,row);
        gameLogic->field.fieldOutput(columns, row); //Größe des Spielfeldes
        int winlose = gameLogic->winLose(columns,row,wincoins);
        //4 steht fuer wie viele Coins du brauchst um zu gewinnen, abgepasst um deine Level einfacher zu gestalten
        if(end_game(winlose)){ //Kontrolle ob gewonnen oder verloren 
            break; //Hier erreicht dann spiel beendet hier kannst du was einfügen um ins nächste Level zu gelangen
        }
        std::cout<<"Enemy Turn: \n";
        //sleep(1);
        gameLogic->placeChipEnemy(columns,row);
        //gameLogic->field.fieldOutput(columns, row);
        winlose = gameLogic->winLose(columns,row,wincoins);
        if(end_game(winlose)){
            break;
        }   
    }
}

bool StartEnd::end_game(int winlose){

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //break is not needed in this switch case, because the returns catch any case
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //sleep(1);
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
