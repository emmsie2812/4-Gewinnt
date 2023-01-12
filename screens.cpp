#include "screens.hpp"
#include "level.hpp"
#include "startEnd.hpp"
#include <iostream>
#include <unistd.h>

Screens::Screens(){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//From here pure output area by cout
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Screens::winCout(){
clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*         (: congratulations :)        *\n"
    "*     You have finished the level!     *\n"
    "*                                      *\n"
    "*     Tap 1 to go to the next level    *\n"
    "*       Tap 2 to finish the game       *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}
void Screens::loseCout(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*             ): oh no! :(             *\n"
    "*             you have lost            *\n"
    "*                                      *\n"
    "*     Tap 1 to try the level again     *\n"
    "*       Tap 2 to finish the game       *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}

void Screens::startMenuCout(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*            (:  Hello!  :)            *\n"
    "*   Do you want to start a new Game?   *\n"
    "*          Then please press 1         *\n"
    "* Or do you want to reload your score? *\n"
    "*          Then please press 2         *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}
void Screens::startNewCout(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*        Let's start a new game!       *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}
void Screens::startWithLevel(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*            (: Good luck :)           *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";        
}
void Screens::getInput1Or2(){
    std::cout << "Please enter 1 or 2! ";
}
void Screens::invalidInputCout(){
    startMenuCout();
    std::cout << "\nPlease try again 1 or 2! ";
}

void Screens::clear(){
    std::cout << "\x1B[2J\x1B[H";
}

void Screens::levelDescription(){
    Level level;
    int resentLevel;
    resentLevel = level.getLevel();
    int* columnsLinesWinCoins;
    columnsLinesWinCoins = level.levelSetup();
    std::cout << "You are in level " << resentLevel <<".\nHere you have a " << columnsLinesWinCoins[0] << "x" << columnsLinesWinCoins[1] << " field \nand you need " << columnsLinesWinCoins[2] << " of your stones \nin a horizontal, vertical or diagonal line to win.\nGood luck!\n\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//From here comes the logical part behind the menus
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Screens::startMenu(){   
    bool validInput = false;
    startMenuCout();
    getInput1Or2();
    StartEnd startEnd;
    while(!validInput){
        int startInput; 
        std::cin >> startInput; // Get user input from the keyboard
        clear();
        if(startInput==1){
            startNewCout(); //Output
            sleep(1);
            clear();
            Level level;
            level.saveLevel(1);
            validInput = true;
            int start_new = 1;
            startEnd.startGame();
        }
        else if(startInput==2){        
            startWithLevel(); //Output
            startEnd.startGame();
        }
        else{invalidInputCout();} //Output
    }
    clear();
    //return 10;      //Error
}       

void Screens::endMenuWin(){
    bool validInputWin = false;
    int WinInput;
    clear();
    while(!validInputWin){ 
        winCout();
        getInput1Or2();
        std::cin >> WinInput; // Get user input from the keyboard
        if(WinInput==1 || WinInput==2){validInputWin=true;}
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Is always executed, because you don't want to play the level again the next time you start the game, but you want to start in the new level
    int newLevel;
    Level level;
    newLevel = level.getLevel() + 1;
    level.saveLevel(newLevel);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(WinInput==1){
        StartEnd startEnd;
        startEnd.startGame();
    }
}
void Screens::endMenuLose(){
    bool validInputLose = false;
    int loseInput; 
    clear();
    while(!validInputLose){
        loseCout();
        getInput1Or2();
        std::cin >> loseInput; // Get user input from the keyboard
        if(loseInput==1 || loseInput==2){validInputLose=true;}
    }
    if(loseInput==1){
        StartEnd startEnd;
        startEnd.startGame();
    }

}

       