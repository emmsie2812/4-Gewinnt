#pragma once
#include <iostream>

/*********************************************************************

Screens and logic behind the screens 

*********************************************************************/

class Screen {
    private: 
        bool isValidInputFromUserByKeyboard;
        int inputFromUserByKeyboard1Or2;
        //gameController* StartEnd; 
    public:
        Screen();
        void printLose();
        void printWin();
        void printStartMenu();
        void printStartNew();
        void printStartWithLevel();
        void printAskForUserInput1Or2();
        void printInvalidInput();
        void clearScreen();
        void printLevelDescription(int* columnsLinesWinCoins,int resentLevel);
        void levelDescription();
        void startMenu();
        void endMenuWin();
        void endMenuLose();
        bool getInputFromUser();

};