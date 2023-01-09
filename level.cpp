#include "level.hpp"
#include <iostream>

int* Level::level_1(){
    level_setup[0] = 4; //columns
    level_setup[1] = 5; //lines
    level_setup[2] = 6; //win_coins
    
   return level_setup;
}
