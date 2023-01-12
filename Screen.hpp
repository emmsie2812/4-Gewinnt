#pragma once
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Screens and logic behind the screens 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Screen{
    private: 
        //gameController* StartEnd; 
    public:
        Screen();
        void loseCout();
        void winCout();
        void startMenuCout();
        void startNewCout();
        void startWithLevel();
        void getInput1Or2();
        void invalidInputCout();
        void clearScreen();
        void levelDescriptioncout(int* columnsLinesWinCoins,int resentLevel);
        void levelDescription();
        void startMenu();
        void endMenuWin();
        void endMenuLose();

};