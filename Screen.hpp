#pragma once
#include <iostream>

/*********************************************************************

Screens and logic behind the screens 

*********************************************************************/

class Screen {

    private: 
        bool isValidInputFromUserByKeyboard;
        int inputFromUserByKeyboard1Or2;
        int inputFromUserByKeyboard1;

    public:
        Screen();
        void printLose();
        void printWin();
        void printStartMenu();
        void printStartNew();
        void printStartWithLevel();
        void printHelpMenu();
        void printAskForUserInput1Or2();
        void printAskForUserInput1Or2Or3();
        void printEnter1ToGetBackToStartMenu();
        void printInvalidInput();
        void clearScreen();
        void printLevelDescription(int* columnsRowsWinCoins, int resentLevel);
        void levelDescription();
        void startMenu();
        void endMenuWin();
        void endMenuLose();
        int getInputFromUser();
        void helpMenu();
};