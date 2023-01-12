#include "Screen.hpp"
#include "Level.hpp"
#include "StartGame.hpp"
#include <iostream>
#include <unistd.h>

Screen::Screen(){
    //this.gameController = new StartGame();
    //this.level = new Level();#
    //Level level;
}

/*********************************************************************
From here pure output area by cout
*********************************************************************/


void Screen::printWin() {
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

void Screen::printLose() {
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

void Screen::printStartMenu() {
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

void Screen::printStartNew() {
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

void Screen::printStartWithLevel() {
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

void Screen::printAskForUserInput1Or2() {
    std::cout << "Please enter 1 or 2! ";
}

void Screen::printInvalidInput() {
    printStartMenu();
    std::cout << "\nPlease try again 1 or 2! ";
}

void Screen::clearScreen() {
    std::cout << "\x1B[2J\x1B[H";
}

void Screen::printLevelDescription(int* columnsLinesWinCoins, int recentLevel) {
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
    printLevelDescription(columnsLinesWinCoins, recentLevel);     //Output
}

void Screen::startMenu() {    
    /*********************************************************************
    Start menu at the beginning of the game
    Possible actions:
        1 start new game in level 1
        2 start with the stored level in file
    *********************************************************************/

    printStartMenu();                   //Output
    printAskForUserInput1Or2();         //Output
    StartGame startGame;
    isValidInputFromUserByKeyboard = false;
    while (!isValidInputFromUserByKeyboard) {
        inputFromUserByKeyboard1Or2 = getInputFromUser();      // Get user input from the keyboard
        clearScreen();
        switch (inputFromUserByKeyboard1Or2) {            //1 means to begin a new game. The saved level will be overwritten to 1
            case 1:
                printStartNew();        //Output
                sleep(1);
                clearScreen();
                Level level;
                level.saveLevel(1);     //overwrite saved level in file
                isValidInputFromUserByKeyboard = true;
                startGame.startGame();   //Starts the game 
                break;
            case 2:
                printStartWithLevel();  //Output
                startGame.startGame();   //Starts the game 
                isValidInputFromUserByKeyboard = true;
                break;
            default:
                printInvalidInput();    //Output
        }
    }
    clearScreen();
}       

void Screen::endMenuWin() {
/*********************************************************************
Win screen
Possible actions:
    1 play next level
    2 leave game
*********************************************************************/

    clearScreen();
    isValidInputFromUserByKeyboard = false;
    while (!isValidInputFromUserByKeyboard) { 
        printWin();
        printAskForUserInput1Or2();
        inputFromUserByKeyboard1Or2 = getInputFromUser();      // Get user input from the keyboard
        if (inputFromUserByKeyboard1Or2 == 1 || inputFromUserByKeyboard1Or2 == 2) {
            isValidInputFromUserByKeyboard = true;
        }
    }

/*********************************************************************
    Is always executed, because you don't want to play the level again the next time you start the game, but you want to start in the new level*/
    Level level;
    level.incrementLevelInFile();
/********************************************************************/
    if (inputFromUserByKeyboard1Or2 == 1) {
        StartGame startGame;
        startGame.startGame();                                   //Starts the game
    }
}

void Screen::endMenuLose() {
/*********************************************************************
Lose screen
Possible actions:
    1 play level again
    2 leave game
********************************************************************/

    clearScreen();
    isValidInputFromUserByKeyboard = false;
    while (!isValidInputFromUserByKeyboard) {
        printLose();                                            //Output
        printAskForUserInput1Or2();                             //Output
        inputFromUserByKeyboard1Or2 = getInputFromUser();       // Get user input from the keyboard
        if (inputFromUserByKeyboard1Or2 == 1 || inputFromUserByKeyboard1Or2 == 2) {
            isValidInputFromUserByKeyboard = true;
        }
    }

    if (inputFromUserByKeyboard1Or2 == 1) {                      //Play Level again
        StartGame startGame;
        startGame.startGame();                                    //Starts the game
    }
}

bool Screen::getInputFromUser() {
/*********************************************************************
Gets input from user by keyboard
*********************************************************************/

    int inputFromUserByKeyboard1Or2;
    std::cin >> inputFromUserByKeyboard1Or2;           // Get user input from the keyboard
    return inputFromUserByKeyboard1Or2;
}   