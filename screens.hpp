#pragma once
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Screens and logic behind the screens 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Screens{
    
    public:
        Screens();
        void loseCout();
        void winCout();
        void startMenuCout();
        void startNewCout();
        void startWithLevel();
        void getInput1Or2();
        void invalidInputCout();
        void clear();
        void levelDescriptioncout(int* columnsLinesWinCoins,int resentLevel);
        void levelDescription();
        void startMenu();
        void endMenuWin();
        void endMenuLose();

};