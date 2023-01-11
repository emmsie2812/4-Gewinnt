#include "startEnd.hpp"
#include "field.hpp"
#include "spiellogik.hpp"
#include "screens.hpp"
#include "level.hpp"
#include <iostream>

Screens screen;

void StartEnd::startGame(){
    screen.startMenu();
    
    Level level;
    int* columnsLinesWinCoins;
    columnsLinesWinCoins = level.levelSetup();
    int columns = columnsLinesWinCoins[0];
    int lines = columnsLinesWinCoins[1];
    int wincoins = columnsLinesWinCoins[2];

    ///////////////////////////////////////////////
    //Erklärung was in Level

    Field *gameField = new Field();
    Spiellogik *spiellogik = new Spiellogik(*gameField);
    bool time = true;
    while(time){ 
        screen.clear();
        spiellogik->field.fieldOutput(columns, lines);
        std::cout<<"Your Turn:";
        spiellogik->placeChipUser(columns,lines);
        spiellogik->field.fieldOutput(columns, lines); //Größe des Spielfeldes
        int winlose = spiellogik->winLose(columns,lines,wincoins);
        //4 steht fuer wie viele Coins du brauchst um zu gewinnen, abgepasst um deine Level einfacher zu gestalten
        if(end_game(winlose)){ //Kontrolle ob gewonnen oder verloren 
            break; //Hier erreicht dann spiel beendet hier kannst du was einfügen um ins nächste Level zu gelangen
        }
        std::cout<<"Enemy Turn: \n";
        //sleep(1);
        spiellogik->placeChipRandom(columns,lines);
        //spiellogik->field.fieldOutput(columns, lines);
        winlose = spiellogik->winLose(columns,lines,wincoins);
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
        case 3:
            screen.endMenuWin();
            return true;
        case 4:
            screen.endMenuLose();
            return true;
        case 5:
            screen.endMenuWin();
            return true;
        case 6:
            screen.endMenuLose();
            return true;    
        default:
            return false;
        }
}
