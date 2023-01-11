#pragma once
#include <iostream>

class Screens{
    
    public:
        Screens();
        void loseCout();
        void winCout();
        /*
        void winScreenVertical();
        void winScreenHorizontal();
        void winScreenDiagonal();
        void loseScreenVertical();
        void loseScreenHorizontal();
        void loseScreenDiagonal();*/
        void startMenuCout();
        void startNewCout();
        void startWithLevel();
        void getInput1Or2();
        void invalidInputCout();
        void clear();
        int startMenu();
        void endMenuWin();
        void endMenulose();

};