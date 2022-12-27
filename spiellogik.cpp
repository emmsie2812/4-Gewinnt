#include "spiellogik.hpp"
#include "CppRandom.hpp"
#include <random>

 
Spiellogik::Spiellogik(){}

Spiellogik::Spiellogik(Field &game_field){
    field = game_field;
}

void Spiellogik::place_chip_user(){
    std::cin >> user_input; 

    for(int i = 0; i<5; i++){
        if(field.game_field[user_input-1][i] == NULL ){
            field.game_field[user_input-1][i] = 'O';
            break;
        }else{
            continue;
        }
    }
}

void Spiellogik::place_chip_random(){

    int column_random = GetRandomNumberBetween(1,5);
    for(int i = 0; i<5; i++){
        if(field.game_field[column_random-1][i] == NULL ){
            field.game_field[column_random-1][i] = 'X';
            break;
        }else{
            continue;
        }
    }
}

int Spiellogik::win_lose(int columns, int lines){

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
            if(count1_Me == 4){
                return 1;
            }
            if(count2_Enemy==4){
                return 2;
            }
        }
    }
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
            if(count1_Me == 4){
                return 1;
            }
            if(count2_Enemy== 4){
                return 2;
            }
        }
    }
//diagonal left-bottom to right-top
for(int i=0; i<lines+1; i++){
    for (int j=0; j<columns+1; j++){
        if(field.game_field[j][i] == 'O' && field.game_field[j+1][i+1] == 'O' && field.game_field[j+2][i+2] == 'O' && field.game_field[j+3][i+3] == 'O'){
            return 1;
        }
        if(field.game_field[j][i] == 'X' && field.game_field[j+1][i+1] == 'X' && field.game_field[j+2][i+2] == 'X' && field.game_field[j+3][i+3] == 'X'){
            return 2;
        }
    }
}

//diagonal left-top to right-bottom
for(int i=0; i<lines+1; i++){
    for (int j=0; j<columns+1; j++){
        if(field.game_field[j][i] == 'O' && field.game_field[j-1][i+1] == 'O' && field.game_field[j-2][i+2] == 'O' && field.game_field[j-3][i+3] == 'O'){
            return 1;
        }
        if(field.game_field[j][i] == 'X' && field.game_field[j-1][i+1] == 'X' && field.game_field[j-2][i+2] == 'X' && field.game_field[j-3][i+3] == 'X'){
            return 2;
        }
    }
}
return 0;
}

