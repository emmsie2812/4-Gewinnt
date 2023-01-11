#include "spiellogik.hpp"
#include "CppRandom.hpp"
#include <random>

 
Spiellogik::Spiellogik(){}

Spiellogik::Spiellogik(Field &gameField){
    field = gameField;
}

bool Spiellogik:: invalidInput(int columns, int lines, int userInput){
    if(userInput > columns || userInput == 0 || field.gameField[userInput-1][lines-1] == 'O'|| field.gameField[userInput-1][lines-1] == 'X'|| !userInput){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << userInput <<" is a Invalid Input, Please Try Again: ";
        return false;
    } 
    return true;
}

void Spiellogik::placeChipUser(int columns, int lines){

    bool validInput = false;
    int userInput;

    while(!validInput){
        std::cin >> userInput;
        validInput = invalidInput(columns,lines, userInput);
    }


    for(int i = 0; i<lines; i++){
        if(field.gameField[userInput-1][i] == NULL ){
            field.gameField[userInput-1][i] = 'O';
            break;
        }else{
            continue;
        }
    }
}

void Spiellogik::placeChipRandom(int columns, int lines){

    int columnRandom;
    bool validInput = false;

    while(!validInput){
        columnRandom = GetRandomNumberBetween(1,5);
        validInput = invalidInput(columns,lines, columnRandom);
    }

    for(int i = 0; i<lines; i++){
        if(field.gameField[columnRandom-1][i] == NULL ){
            field.gameField[columnRandom-1][i] = 'X';
            break;
        }else{
            continue;
        }
    }  
}

int Spiellogik:: horizontalWinLose(int columns, int lines,int winCoins){
//waagrecht
    for (int i = 0; i < lines; i++){
        int count1_Me = 0;
        int count2_Enemy = 0;
        for (int j = 0; j < columns; j++){
            if(field.gameField[j][i] == 'O'){
                count1_Me++;
                count2_Enemy = 0;
            } 
            if(field.gameField[j][i] == 'X'){
                count2_Enemy++;
                count1_Me = 0;
            }
            if(count1_Me == winCoins){
                return 1;
            }
            if(count2_Enemy==winCoins){
                return 2;
            }
        }
    }
    return 0;
}

int Spiellogik:: verticalWinLose(int columns, int lines,int winCoins){
    //senkrecht
    for (int j = 0; j < columns; j++){
        int count1_Me = 0;
        int count2_Enemy = 0;
        for (int i = 0; i < lines; i++){
            if(field.gameField[j][i] == 'O'){
                count1_Me++;
                count2_Enemy = 0;
            }
            if(field.gameField[j][i] == 'X'){
                count2_Enemy++;
                count1_Me = 0;
            }
            if(count1_Me == winCoins){
                return 3;
            }
            if(count2_Enemy== winCoins){
                return 4;
            }
        }
    }
    return 0;
}

int Spiellogik:: diagonalWinLose(int columns, int lines,int winCoins){
    //diagonal left-top to right-bottom
    for(int i=0; i<lines+1; i++){
        for (int j=0; j<columns+1; j++){
            int count1_Me = 0;
            int count2_Enemy = 0;
            for (int coins = 0; coins < winCoins; coins++)
            {
                if(field.gameField[j-coins][i+coins] == 'O'){
                    count1_Me++;
                    count2_Enemy = 0;
                }
                if(field.gameField[j-coins][i+coins] == 'X'){
                    count2_Enemy++;
                    count1_Me = 0;
                }
                if(count1_Me == winCoins){
                    return 5;
                }
                if(count2_Enemy== winCoins){
                    return 6;
                }
            }
        }
    }

    //diagonal left-bottom to right-top
    for(int i=0; i<lines+1; i++){
        for (int j=0; j<columns+1; j++){
            int count1_Me = 0;
            int count2_Enemy = 0;
            for (int coins = 0; coins < winCoins; coins++)
            {
                if(field.gameField[j+coins][i+coins] == 'O'){
                    count1_Me++;
                    count2_Enemy = 0;
                }
                if(field.gameField[j+coins][i+coins] == 'X'){
                    count2_Enemy++;
                    count1_Me = 0;
                }
                if(count1_Me == winCoins){
                    return 5;
                }
                if(count2_Enemy== winCoins){
                    return 6;
                }
            }
        }
    }
    return 0;
}

int Spiellogik::winLose(int columns, int lines,int winCoins){
    int win = 0;

    int horizontalWin = horizontalWinLose(columns,lines,winCoins);
    int verticalWin = verticalWinLose(columns,lines, winCoins);
    int diagonalWin = diagonalWinLose(columns,lines, winCoins);
    if(horizontalWin != 0){
        win = horizontalWin;
    }else if(verticalWin != 0){
        win = verticalWin;
    }else if(diagonalWin != 0){
        win = diagonalWin;
    }
    return win;
}