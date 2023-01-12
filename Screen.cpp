#include "Screen.hpp"
#include "level.hpp"
#include "startEnd.hpp"
#include <iostream>
#include <unistd.h>

Screen::Screen(){
    //this.gameController = new StartEnd();
}

/*********************************************************************
From here pure output area by cout
*********************************************************************/


void Screen::winCout() {
    clearScreen();
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

void Screen::loseCout() {
    clearScreen();
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

void Screen::startMenuCout() {
    clearScreen();
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

void Screen::startNewCout() {
    clearScreen();
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

void Screen::startWithLevel() {
    clearScreen();
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

void Screen::getInput1Or2() {
    std::cout << "Please enter 1 or 2! ";
}

void Screen::invalidInputCout() {
    startMenuCout();
    std::cout << "\nPlease try again 1 or 2! ";
}

void Screen::clearScreen() {
    std::cout << "\x1B[2J\x1B[H";
}

void Screen::levelDescriptioncout(int* columnsLinesWinCoins, int recentLevel) {
    std::cout << "You are in level " << recentLevel <<".\nHere you have a " << columnsLinesWinCoins[0] << "x" << columnsLinesWinCoins[1] << " field \nand you need " << columnsLinesWinCoins[2] << " of your stones \nin a horizontal, vertical or diagonal line to win.\nGood luck!\n\n";
}

/*********************************************************************
From here comes the logical part behind the screen
*********************************************************************/

void Screen::levelDescription() {   
/*********************************************************************
Collects the level settings to be printed for the user
*********************************************************************/
    Level level;
    int recentLevel;
    recentLevel = level.getLevel();
    int* columnsLinesWinCoins;
    columnsLinesWinCoins = level.levelSetup();
    levelDescriptioncout(columnsLinesWinCoins, recentLevel);     //Output
}

void Screen::startMenu() {    
    /*********************************************************************
    Start menu at the beginning of the game
    Possible actions:
        1 start new game in level 1
        2 start with the stored level in file
    *********************************************************************/

    bool validInput = false;
    startMenuCout();                    //Output
    getInput1Or2();                     //Output
    StartEnd startEnd;

    while(!validInput) {
        int startInput; 
        std::cin >> startInput;         // Get user input from the keyboard
        clearScreen();
        
        switch(startInput) {            //1 means to begin a new game. The saved level will be overwritten to 1
            case 1:
                startNewCout();         //Output
                sleep(1);
                clearScreen();
                Level level;
                level.saveLevel(1);     //overwrite saved level in file
                validInput = true;
                startEnd.startGame();   //Starts the game 
                break;
            case 2:
                startWithLevel();       //Output
                startEnd.startGame();   //Starts the game 
                break;
            default:
                invalidInputCout();     //Output
        }
    }
    clearScreen();
}       

void Screen::endMenuWin() {
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Win screen
    //Possible actions:
    //  1 play next level
    //  2 leave game
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool validInputWin = false;
    int WinInput;
    clearScreen();

    while(!validInputWin) { 
        winCout();
        getInput1Or2();
        std::cin >> WinInput; // Get user input from the keyboard
        if (WinInput == 1 || WinInput == 2) {
            validInputWin = true;
        }
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
        startEnd.startGame(); //Starts the game
    }
}
void Screen::endMenuLose(){
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Lose screen
    //Possible actions:
    //  1 play level again
    //  2 leave game
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool validInputLose = false;
    int loseInput; 
    clearScreen();
    while(!validInputLose){
        loseCout();            //Output
        getInput1Or2();        //Output
        std::cin >> loseInput; // Get user input from the keyboard
        if(loseInput==1 || loseInput==2){validInputLose=true;}
    }
    if(loseInput==1){          //Play Level again
        StartEnd startEnd;
        startEnd.startGame();  //Starts the game
    }


/*
    selection = askUserWithStartscreen()
    if (selection == 1) {
        this.gameController->StartGame();
    }*/

}

       