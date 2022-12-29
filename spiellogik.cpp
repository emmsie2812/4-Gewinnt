#include "spiellogik.hpp"
#include "CppRandom.hpp"
#include <random>

 
Spiellogik::Spiellogik(){}

Spiellogik::Spiellogik(Field &game_field){
    field = game_field;
}

bool Spiellogik:: invalid_input(int columns, int lines, int user_input){

    if(user_input > columns || user_input == 0 || field.game_field[user_input-1][lines-1] == 'O'|| field.game_field[user_input-1][lines-1] == 'X'){
        std::cout << "Invalid Input, Please Try Again: ";
        return false;
    } 
    return true;
}

void Spiellogik::place_chip_user(int columns, int lines){

    bool valid_input = false;
    int user_input;

    while(!valid_input){
        std::cin >> user_input;
        valid_input = invalid_input(columns,lines, user_input);
    }


    for(int i = 0; i<lines; i++){
        if(field.game_field[user_input-1][i] == NULL ){
            field.game_field[user_input-1][i] = 'O';
            break;
        }else{
            continue;
        }
    }
}

void Spiellogik::place_chip_random(int columns, int lines){

    int column_random;
    bool valid_input = false;

    while(!valid_input){
        column_random = GetRandomNumberBetween(1,5);
        valid_input = invalid_input(columns,lines, column_random);
    }

    for(int i = 0; i<lines; i++){
        if(field.game_field[column_random-1][i] == NULL ){
            field.game_field[column_random-1][i] = 'X';
            break;
        }else{
            continue;
        }
    }
}

int Spiellogik:: horizontal_win_lose(int columns, int lines,int win_coins){
//waagrecht
    for (int i = 0; i < lines; i++){
        int count1_Me = 0;
        int count2_Enemy = 0;
        for (int j = 0; j < columns; j++){
            if(field.game_field[j][i] == 'O'){
                count1_Me++;
                count2_Enemy = 0;
            } 
            if(field.game_field[j][i] == 'X'){
                count2_Enemy++;
                count1_Me = 0;
            }
            if(count1_Me == win_coins){
                return 1;
            }
            if(count2_Enemy==win_coins){
                return 2;
            }
        }
    }
    return 0;
}

int Spiellogik:: vertical_win_lose(int columns, int lines,int win_coins){
    //senkrecht
    for (int j = 0; j < columns; j++){
        int count1_Me = 0;
        int count2_Enemy = 0;
        for (int i = 0; i < lines; i++){
            if(field.game_field[j][i] == 'O'){
                count1_Me++;
                count2_Enemy = 0;
            }
            if(field.game_field[j][i] == 'X'){
                count2_Enemy++;
                count1_Me = 0;
            }
            if(count1_Me == win_coins){
                return 3;
            }
            if(count2_Enemy== win_coins){
                return 4;
            }
        }
    }
    return 0;
}

int Spiellogik:: diagonal_win_lose(int columns, int lines,int win_coins){
    //diagonal left-top to right-bottom
    for(int i=0; i<lines+1; i++){
        for (int j=0; j<columns+1; j++){
            if(field.game_field[j][i] == 'O' && field.game_field[j-1][i+1] == 'O' && field.game_field[j-2][i+2] == 'O' && field.game_field[j-3][i+3] == 'O'){
                return 5;
            }
            if(field.game_field[j][i] == 'X' && field.game_field[j-1][i+1] == 'X' && field.game_field[j-2][i+2] == 'X' && field.game_field[j-3][i+3] == 'X'){
                return 6;
            }
        }
    }

    //diagonal left-bottom to right-top
    for(int i=0; i<lines+1; i++){
        for (int j=0; j<columns+1; j++){
            if(field.game_field[j][i] == 'O' && field.game_field[j+1][i+1] == 'O' && field.game_field[j+2][i+2] == 'O' && field.game_field[j+3][i+3] == 'O'){
                return 5;
            }
            if(field.game_field[j][i] == 'X' && field.game_field[j+1][i+1] == 'X' && field.game_field[j+2][i+2] == 'X' && field.game_field[j+3][i+3] == 'X'){
                return 6;
            }
        }
    }

    return 0;
}

int Spiellogik::win_lose(int columns, int lines,int win_coins){
    return horizontal_win_lose(columns,lines,win_coins);
    return vertical_win_lose(columns,lines, win_coins);
    return diagonal_win_lose(columns,lines, win_coins);
    return 0;
}

