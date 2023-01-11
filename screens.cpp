#include "screens.hpp"
#include "level.hpp"
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
/*
void Screens::winScreenVertical(){
    clear();        //defined below by ANSI escape sequence 
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*              Nice turn!              *\n"
    "*          You won vertically          *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}

void Screens::winScreenHorizontal(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*              Nice turn!              *\n"
    "*         You won horizontally         *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}

void Screens::winScreenDiagonal(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*              Nice turn!              *\n"
    "*          You won diagonally          *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}

void Screens::loseScreenVertical(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                Oh no!                *\n"
    "*         You lost vertically!         *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}

void Screens::loseScreenHorizontal(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                Oh no!                *\n"
    "*        You lost horizontally!        *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}

void Screens::loseScreenDiagonal(){
    clear();
    std::cout << "\n"
    "****************************************\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                Oh no!                *\n"
    "*         You lost diagonally!         *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "*                                      *\n"
    "****************************************\n"
    "\n";
}
*/
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

void Screens::clear()
{
    std::cout << "\x1B[2J\x1B[H";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//From here comes the logical part behind the menus
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Screens::startMenu(){   
    bool validInput = false;
    startMenuCout();
    getInput1Or2();
    while(!validInput){
        int startInput; 
        std::cin >> startInput; // Get user input from the keyboard
        clear();
        if(startInput==1){
            startNewCout(); //Output
            sleep(1);
            clear();
            validInput = true;
            int start_new = 1;
            return start_new;
        }
        else if(startInput==2){
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // getLevel() liest die Datei saved_levels.txt aus und gibt das Level zurück
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            startWithLevel(); //Output
            Level level;
            return level.getLevel();
        }
        else{invalidInputCout();} //Output
    }
    return 10;      //Error
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
    int resentLevel;
    Level level;
    resentLevel = level.getLevel();
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

}

       