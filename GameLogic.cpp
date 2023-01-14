#include "GameLogic.hpp"
#include "Random.hpp"
#include <random>

/*********************************************************************
To output the game field by cout 
*********************************************************************/
 
GameLogic::GameLogic() {

}

GameLogic::GameLogic(Field &gameField) {
    field = gameField;
}

bool GameLogic::invalidInputUser(int columns, int row, int userInput) {
/*********************************************************************
checks the input of the player
*********************************************************************/
 
    if (userInput > columns || userInput == 0 || field.gameField[userInput-1][row-1] == 'O'|| field.gameField[userInput-1][row-1] == 'X'|| !userInput) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input, Please Try Again: ";
        return false;
    } 
    return true;
}

bool GameLogic::invalidInputEnemy(int columns, int row, int userInput) {
/*********************************************************************
checks the input of the Enemy(Computer) 
*********************************************************************/

    if (userInput > columns || userInput == 0 || field.gameField[userInput-1][row-1] == 'O'|| field.gameField[userInput-1][row-1] == 'X'|| !userInput) {
        return false;
    } 
    return true;
}

bool GameLogic::fullGamefield(int columns, int row) {
/*********************************************************************
checks for full gamefield
*********************************************************************/
    bool fullGamefield = true; 

    for(int j = 0; j<columns; j++){
        if(field.gameField[j][row-1] != 'O' && field.gameField[j][row-1] != 'X'){
            fullGamefield = false;
        }
    }

    return fullGamefield;
}

void GameLogic::placeChipUser(int columns, int row) {
/*********************************************************************
Places the chip of the user after checking if the game field is empty
*********************************************************************/

    bool validInput = false;
    int userInput;

    while (!validInput) {
        std::cin >> userInput;
        validInput = invalidInputUser(columns,row, userInput);
    }

    for (int i = 0; i < row; i++) {                              //Places the chip of the user
        if (field.gameField[userInput-1][i] == NULL ) {
            field.gameField[userInput-1][i] = 'O';
            break;
        }else {
            continue;
        }
    }
}

void GameLogic::placeChipEnemy(int columns, int row) {
/*********************************************************************
Places the chip of the enemy after checking if the game field is empty
*********************************************************************/

    int columnRandom;
    bool validInput = false;

    while (!validInput) {
        Random random;
        columnRandom = random.getRandomNumberBetween(1, row);
        validInput = invalidInputEnemy(columns, row, columnRandom);
    }

    for (int i = 0; i<row; i++) {                                 //Places the chip of the enemy
        if (field.gameField[columnRandom-1][i] == NULL ) {
            field.gameField[columnRandom-1][i] = 'X';
            break;
        }else {
            continue;
        }
    }  
}

int GameLogic::horizontalWinLose(int columns, int row, int winCoins) {
/*********************************************************************
Checking for a horizontal winning or losing row 
*********************************************************************/

    for (int i = 0; i < row; i++) {             //i = row
        int count1_Me = 0;
        int count2_Enemy = 0;

        for (int j = 0; j < columns; j++) {     //j = columns
            if (field.gameField[j][i] == 'O') {
                count1_Me++;
                count2_Enemy = 0;
            } 
            if (field.gameField[j][i] == 'X') {
                count2_Enemy++;
                count1_Me = 0;
            }
            if (count1_Me == winCoins) {          //Win user
                return 1;
            }
            if (count2_Enemy==winCoins) {        //Win enemy
                return 2;
            }
        }
    }
    return 0;
}

int GameLogic::verticalWinLose(int columns, int row, int winCoins) {
/*********************************************************************
Checking for a vertical winning or losing row
*********************************************************************/

    for (int j = 0; j < columns; j++) {          //j = columns
        int count1_Me = 0;
        int count2_Enemy = 0;

        for (int i = 0; i < row; i++) {          //i = rows  
            if (field.gameField[j][i] == 'O') {
                count1_Me++;
                count2_Enemy = 0;
            }
            if (field.gameField[j][i] == 'X') {
                count2_Enemy++;
                count1_Me = 0;
            }
            if (count1_Me == winCoins) {         //win user
                return 1;
            }
            if (count2_Enemy == winCoins) {      //win enemy
                return 2;
            }
        }
    }
    return 0;
}

int GameLogic:: diagonalWinLose(int columns, int row,int winCoins) {
/*********************************************************************
Checking for a diagonal winning or losing row
*********************************************************************/

    //diagonal left-top to right-bottom
    for (int i=0; i<row+1; i++) {                //i = rows

        for (int j=0; j<columns+1; j++) {        //J = columns
            int count1_Me = 0;
            int count2_Enemy = 0;

            for (int coins = 0; coins < winCoins; coins++) {
                if (field.gameField[j-coins][i+coins] == 'O') {
                    count1_Me++;
                    count2_Enemy = 0;
                }
                if (field.gameField[j-coins][i+coins] == 'X') {
                    count2_Enemy++;
                    count1_Me = 0;
                }
                if (count1_Me == winCoins) {     //win user
                    return 1;
                }
                if (count2_Enemy== winCoins) {   //win enemy
                    return 2;
                }
            }
        }
    }

    //diagonal left-bottom to right-top
    for (int i=0; i<row+1; i++) {                //i = rows

        for (int j=0; j<columns+1; j++) {        //j = columns
            int count1_Me = 0;
            int count2_Enemy = 0;

            for (int coins = 0; coins < winCoins; coins++) {
                if (field.gameField[j+coins][i+coins] == 'O') {
                    count1_Me++;
                    count2_Enemy = 0;
                }
                if (field.gameField[j+coins][i+coins] == 'X') {
                    count2_Enemy++;
                    count1_Me = 0;
                }
                if (count1_Me == winCoins) {     //win user 
                    return 1;
                }
                if (count2_Enemy== winCoins) {   //win enemy
                    return 2;
                }
            }
        }
    }
    return 0;
}

int GameLogic::winLose(int columns, int row, int winCoins) {
/*********************************************************************
Checks who has won
*********************************************************************/

    int win = 0;

    int WinUserOrEnemyHorizontal = horizontalWinLose(columns, row, winCoins);
    int WinUserOrEnemyVertical = verticalWinLose(columns, row, winCoins);
    int WinUserOrEnemyDiagonal = diagonalWinLose(columns, row, winCoins);

    if (WinUserOrEnemyHorizontal == 1 || WinUserOrEnemyVertical == 1 ||  WinUserOrEnemyDiagonal == 1) {
        win = 1;

    }else if (WinUserOrEnemyHorizontal == 2 || WinUserOrEnemyVertical == 2 ||  WinUserOrEnemyDiagonal == 2) {
        win = 2;
    }
    return win;
}