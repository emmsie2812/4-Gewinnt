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

